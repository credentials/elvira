/**
 * Data types for credential crypto interfaces.
 *
 * @author Pim Vullers (pim@cs.ru.nl)
 */

#ifndef CREDENTIAL_CRYPTO_TYPES_H
#define CREDENTIAL_CRYPTO_TYPES_H

#define N_BYTES     128 // 1024 bits
#define M_BYTES      32 //  256 bits
#define NONCE_BYTES  10 //   80 bits
#define HASH_BYTES   20 //  160 bits
#define V_BYTES     201 // 1604 bits
#define E_BYTES      63 //  504 bits
#define EPRIME_BYTES 15 //  120 bits

#define VPRIME_BYTES    (N_BYTES + NONCE_BYTES) // 138 bytes
#define VPRIMEHAT_BYTES (N_BYTES + 2*NONCE_BYTES + HASH_BYTES) // 168 bytes
#define MHAT_BYTES      (M_BYTES + NONCE_BYTES + HASH_BYTES) // 62 bytes
#define SHAT_BYTES      (M_BYTES + NONCE_BYTES + HASH_BYTES + 1) // 63 bytes
#define VHAT_BYTES      (V_BYTES + NONCE_BYTES + HASH_BYTES) // 231 bytes
#define EHAT_BYTES      (EPRIME_BYTES + NONCE_BYTES + HASH_BYTES) // 45 bytes

typedef struct {
  unsigned char v[HASH_BYTES];
} Hash;

typedef struct {
  unsigned char v[NONCE_BYTES];
} Nonce;

typedef struct {
  unsigned char v[N_BYTES];
} Number;

typedef struct {
  Number p;
  Number q;
} CLPrivateKey;

typedef struct {
  Number n;
  Number Z;
  Number S;
  Number *R;
  unsigned long count;
} CLPublicKey;

typedef unsigned char CLMessage[M_BYTES];
typedef struct {
  CLMessage *value;
  unsigned long count;
} CLMessages;

typedef struct {
  Number A;
  unsigned char e[E_BYTES];
  unsigned char v[V_BYTES];
} CLSignature;


typedef struct {
  CredentialIdentifier id;
  CLSignature signature;
  Attributes attributes;
} Credential;

typedef struct {
  Hash c;
  unsigned char vPrimeHat[VPRIMEHAT_BYTES];
  unsigned char sHat[SHAT_BYTES];
} ProofU;

typedef struct {
  Hash c;
  unsigned char eHat[N_BYTES];
} ProofS;

typedef struct {
  Hash c;
  Number APrime;
  unsigned char eHat[EHAT_BYTES];
  unsigned char vHat[VHAT_BYTES];
  unsigned char *aHat[MHAT_BYTES];
  CLMessage *a;
} ProofD;

typedef unsigned long Selection;

#endif // CREDENTIAL_CRYTPO_TYPES_H
