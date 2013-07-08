#ifndef RSAMOD_H
#define RSAMOD_H

#include "credential_crypto_types.h"

/* v contains the value in radix 2^16, 
 * rm is -m^-1 (mod 2^16) */
typedef struct
{
  unsigned long long v[N_BYTES/2];
  unsigned long long rm;
} rsamod;

/* v contains the value in radix 2^16, 
 * mod is a pointer to the modulus */
typedef struct
{
  unsigned long long v[N_BYTES/2];
  rsamod *mod;
} rsaelt;

/* Converts a big-endian byte array to an rsamod */
void rsamod_frombytes(rsamod *r, const unsigned char x[N_BYTES]);

/* Converts a big-endian byte array to an rsaelt (given a modulus) */
void rsaelt_frombytes(rsaelt *r, const unsigned char x[N_BYTES], rsamod *mod);

/* Converts an rsaelt to a big-endian byte array */
void rsaelt_tobytes(unsigned char x[N_BYTES], const rsaelt *r);

/* compute r = x*y mod m */
void rsaelt_mul(rsaelt *r, const rsaelt *x, const rsaelt *y);

/* compute r = x^2 mod m */
void rsaelt_square(rsaelt *r, const rsaelt *x);

/* compute r = x^n mod m */
void rsaelt_exp(rsaelt *r, 
    const rsaelt *x, 
    const unsigned char *n, const unsigned long nlen);

/* compute r = x1^n1 * x2^n2 mod m */
void rsaelt_doubleexp(rsaelt *r, 
    const rsaelt *x1, 
    const unsigned char *n1, const unsigned long nlen1, 
    const rsaelt *x2, 
    const unsigned char *n2, const unsigned long nlen2);

void rsaelt_print();

#endif
