#ifndef BIGINT_H
#define BIGINT_H

/* rlen has to be at least max(xlen,ylen), carry is returned */
unsigned char bigint_add(unsigned char *r,
    const unsigned char *x, unsigned long xlen,
    const unsigned char *y, unsigned long ylen);

/* rlen has to be at least max(xlen,ylen), borrow is returned */
unsigned char bigint_sub(unsigned char *r,
    const unsigned char *x, unsigned long xlen,
    const unsigned char *y, unsigned long ylen);

/* rlen has to be at least xlen+ylen */
void bigint_mul(unsigned char *r,
    const unsigned char *x, unsigned long xlen,
    const unsigned char *y, unsigned long ylen);

/* rlen has to be at least mlen */
void bigint_invmod(unsigned char *r,
    const unsigned char *x, unsigned long xlen,
    const unsigned char *m, unsigned long mlen);

void bigint_print(const unsigned char *x, unsigned long xlen);

#endif
