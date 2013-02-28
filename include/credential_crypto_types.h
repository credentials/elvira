/**
 * Data types for credential crypto interfaces.
 *
 * @author Pim Vullers (pim@cs.ru.nl)
 */

#ifndef CREDENTIAL_CRYPTO_TYPES_H
#define CREDENTIAL_CRYPTO_TYPES_H

#define SIZE_N      128 // 1024 bits
#define SIZE_M       32 //  256 bits
#define SIZE_NONCE   10 //   80 bits
#define SIZE_HASH    20 //  160 bits
#define SIZE_V      201 // 1604 bits
#define SIZE_E       63 //  504 bits
#define SIZE_EPRIME  15 //  120 bits

#define SIZE_VPRIME    (SIZE_N + SIZE_NONCE) // 138 bytes
#define SIZE_VPRIMEHAT (SIZE_N + 2*SIZE_NONCE + SIZE_HASH) // 168 bytes
#define SIZE_MHAT      (SIZE_M + SIZE_NONCE + SIZE_HASH) // 62 bytes
#define SIZE_SHAT      (SIZE_M + SIZE_NONCE + SIZE_HASH + 1) // 63 bytes
#define SIZE_VHAT      (SIZE_V + SIZE_NONCE + SIZE_HASH) // 231 bytes
#define SIZE_EHAT      (SIZE_EPRIME + SIZE_NONCE + SIZE_HASH) // 45 bytes

typedef unsigned char Hash[SIZE_HASH];
typedef unsigned char Nonce[SIZE_NONCE];
typedef unsigned char Number[SIZE_N];

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

typedef unsigned char CLMessage[SIZE_M];
typedef struct {
  CLMessage *value;
  unsigned long count;
} CLMessages;

typedef struct {
  Number A;
  unsigned char e[SIZE_E];
  unsigned char v[SIZE_V];
} CLSignature;


typedef struct {
  CredentialIdentifier id;
  CLSignature signature;
  Attributes attributes;
} Credential;

typedef struct {
  Hash c;
  unsigned char vPrimeHat[SIZE_VPRIMEHAT];
  unsigned char sHat[SIZE_SHAT];
} ProofU;

typedef struct {
  Hash c;
  unsigned char eHat[SIZE_N];
} ProofS;

typedef struct {
  Hash c;
  Number APrime;
  unsigned char eHat[SIZE_EHAT];
  unsigned char vHat[SIZE_VHAT];
  unsigned char *aHat[SIZE_MHAT];
  CLMessage *a;
} ProofD;

typedef unsigned long Selection;

#endif // CREDENTIAL_CRYTPO_TYPES_H
