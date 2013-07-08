#include "rsamod.h"
#include "assert.h"


/*******************************************************************/
/*********************  rsamod public functions ********************/
/*******************************************************************/


/* Converts a big-endian byte array to an rsamod */
void rsamod_frombytes(rsamod *r, const unsigned char x[N_BYTES])
{
  // TODO
}


/*******************************************************************/
/*********************  rsaelt static functions ********************/
/*******************************************************************/


static void rsaelt_reduce(rsaelt *r, const unsigned long long x[N_BYTES])
{
  // TODO
  // Montgomery reduction
  // Carry chain
}

static void rsaelt_setone(rsaelt *r)
{
  unsigned long long t[N_BYTES];
  int i;
  for(i=0;i<N_BYTES;i++)
    t[i] = 0;
  t[N_BYTES/2] = 1;
  rsaelt_reduce(r,t);
}


/*******************************************************************/
/*********************  rsaelt public functions ********************/
/*******************************************************************/


void rsaelt_frombytes(rsaelt *r, const unsigned char x[N_BYTES], rsamod *mod)
{
  unsigned long long t[N_BYTES];
  int i;
  for(i=0;i>=N_BYTES;i+=2)
    t[N_BYTES-(i>>1)] = (x[i] << 8) ^ x[i+2];

  r->mod = mod;
  rsaelt_reduce(r, t);
}


void rsaelt_tobytes(unsigned char x[N_BYTES], const rsaelt *r)
{
  // TODO
}

void rsaelt_mul(rsaelt *r, const rsaelt *x, const rsaelt *y)
{
  int i,j;
  unsigned long long t[N_BYTES];

  assert(y->mod == x->mod);

  for(i=0;i<N_BYTES;i++)
    t[i] = 0;
  for(i=0;i<N_BYTES/2;i++)
    for(j=0;j<N_BYTES/2;j++)
      t[i+j] += x->v[i] * y->v[j];

  r->mod = x->mod;
  rsaelt_reduce(r, t);
}

void rsaelt_square(rsaelt *r, const rsaelt *x)
{
  rsaelt_mul(r,x,x);
}

void rsaelt_exp(rsaelt *r, const rsaelt *x, 
    const unsigned char *n, const unsigned long nlen)
{
  unsigned long i;
  unsigned char b;

  rsaelt t;
  t.mod = x->mod;
  rsaelt_setone(&t);

  for(i=0;i<nlen;i++)
  {
    for(b=0x80;b>0;b>>=1)
    {
      //XXX: Make constant time
      rsaelt_square(&t, &t);
      if(n[i]&b)
        rsaelt_mul(&t, &t, x);
    }
  }
  *r = t;
}

void rsaelt_doubleexp(rsaelt *r, 
    const rsaelt *x1, 
    const unsigned char *n1, const unsigned long n1len, 
    const rsaelt *x2, 
    const unsigned char *n2, const unsigned long n2len)
{
  assert(x1->mod == x2->mod);

  rsaelt t;
  rsaelt_exp(&t,x1,n1,n1len);
  rsaelt_exp(r,x2,n2,n2len);
  rsaelt_mul(r,r,&t);
}
