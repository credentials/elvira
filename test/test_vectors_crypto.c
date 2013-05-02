#include <stdlib.h>
#include <string.h>

#include "credential_types.h"
#include "credential_crypto_types.h"
#include "test_vectors.h"

typedef struct {
  // Generic values.
  CLPublicKey issuerKey;
  CLMessages attributes;
  CLPrivateKey privateKey;

  // Protocol values.
  Nonce n_1;
} IssuerState;

typedef struct {
  // Generic values.
  CLPublicKey issuerKey;
  CLMessages a;
  CLMessage s; // Master secret
  CredentialIdentifier id;
  Attributes attr;

  // Protocol values.
  unsigned char vPrime[VPRIME_BYTES];
  Nonce n_2;
} RecipientState;

int init_issuance_test_state(IssuerState *iSession, RecipientState *rSession) {
  int i;
  
  iSession = malloc(sizeof(IssuerState));
  if (iSession == NULL) {
    free_issuance_test_state(iSession, rSession);
    return -1;
  }

  iSession->issuerKey.count = TEST_COUNT;
  memcpy(&(iSession->issuerKey.n), &TEST_N, sizeof(Number));
  memcpy(&(iSession->issuerKey.S), &TEST_S, sizeof(Number));
  memcpy(&(iSession->issuerKey.Z), &TEST_Z, sizeof(Number));
  iSession->issuerKey.R = malloc(iSession->issuerKey.count * sizeof(Number));
  if (iSession->issuerKey.R == NULL) {
    free_issuance_test_state(iSession, rSession);
    return -1;
  }
  for (i = 0; i < iSession->issuerKey.count; ++i) {
	memcpy(&(iSession->issuerKey.R[i]), &(TEST_R[i]), sizeof(Number));
  }

  iSession->attributes.count = iSession->issuerKey.count - 1;
  iSession->attributes.value = malloc(iSession->attributes.count * sizeof(CLMessage));
  if (iSession->attributes.value == NULL) {
    free_issuance_test_state(iSession, rSession);
    return -1;
  }
  for (i = 0; i < iSession->attributes.count; ++i) {
	memcpy(iSession->attributes.value[i], TEST_A, sizeof(CLMessage));
  }
  
  memcpy(&(iSession->privateKey.p), &TEST_P, sizeof(Number));
  memcpy(&(iSession->privateKey.q), &TEST_Q, sizeof(Number));
  
  rSession = malloc(sizeof(RecipientState));
  if (rSession == NULL) {
    free_issuance_test_state(iSession, rSession);
    return -1;
  }
  rSession->issuerKey.count = iSession->issuerKey.count;
  memcpy(&(rSession->issuerKey.n), &(iSession->issuerKey.n), sizeof(Number));
  memcpy(&(rSession->issuerKey.S), &(iSession->issuerKey.S), sizeof(Number));
  memcpy(&(rSession->issuerKey.Z), &(iSession->issuerKey.Z), sizeof(Number));
  rSession->issuerKey.R = malloc(rSession->issuerKey.count * sizeof(Number));
  if (rSession->issuerKey.R == NULL) {
    free_issuance_test_state(iSession, rSession);
    return -1;
  }
  for (i = 0; i < rSession->issuerKey.count; ++i) {
    memcpy(&(rSession->issuerKey.R[i]), &(iSession->issuerKey.R[i]), sizeof(Number));
  }
  
  rSession->a.count = iSession->attributes.count;
  rSession->a.value = malloc(rSession->a.count * sizeof(CLMessage));
  if (rSession->a.value == NULL) {
    free_issuance_test_state(iSession, rSession);
    return -1;
  }
  for (i = 0; i < rSession->a.count; ++i) {
    memcpy(&(rSession->a.value[i]), &(iSession->attributes.value[i]), sizeof(CLMessage));
  }
  memcpy(rSession->s, &TEST_SECRET, sizeof(CLMessage));
  
  rSession->id.length = 0;
  rSession->id.uri = NULL;
  
  rSession->attr.count = 0;
  rSession->attr.attribute = NULL;
}

int free_issuance_test_state(IssuerState *iSession, RecipientState *rSession) {
  if (iSession != NULL) {
    if (iSession->issuerKey.R != NULL) {
      free(iSession->issuerKey.R);
    }
    
    if (iSession->attributes.value != NULL) {
	  free(iSession->attributes.value);
	}
	
    free(iSession);
  }
  
  if (rSession != NULL) {
	 if (rSession->issuerKey.R != NULL) {
      free(rSession->issuerKey.R);
    }
    
    if (rSession->a.value != NULL) {
	  free(rSession->a.value);
	}
	
   free(rSession);
  } 
}
