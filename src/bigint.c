#include <stdio.h>

#include "bigint.h"

/* rlen has to be at least max(xlen,ylen), carry is returned */
unsigned char bigint_add(unsigned char *r,
    const unsigned char *x, unsigned long xlen,
    const unsigned char *y, unsigned long ylen)
{
  //XXX: TODO
  //
}

/* rlen has to be at least max(xlen,ylen), borrow is returned */
unsigned char bigint_sub(unsigned char *r,
    const unsigned char *x, unsigned long xlen,
    const unsigned char *y, unsigned long ylen
    )
{
  //XXX: TODO
}

/* rlen has to be at least xlen+ylen */
void bigint_mul(unsigned char *r,
    const unsigned char *x, unsigned long xlen,
    const unsigned char *y, unsigned long ylen
    )
{
  //XXX: TODO
}

/* rlen has to be at least mlen */
void bigint_invmod(unsigned char *r,
    const unsigned char *x, unsigned long xlen,
    const unsigned char *m, unsigned long mlen
    )
{
  //XXX: TODO
}

void bigint_print(const unsigned char *x, unsigned long xlen)
{
  long i;
  printf("(");
  for(i=xlen-1;i>0;i--)
    printf("%u*2^(%u) + ",x[i],xlen-1-i);
  printf("%u*2^(%u))",x[0],xlen-1);
}
