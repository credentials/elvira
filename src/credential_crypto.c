#include <stdlib.h>

#include "credential_crypto.h"
#include "credential_crypto_types.h"
#include "randombytes.h"
//#include "rsamod.h"
//#include "bigint.h"

struct IssuerState {
  // Generic values.
  CLPublicKey issuerKey;
  CLMessages attributes;
  CLPrivateKey privateKey;

  // Protocol values.
  Nonce n_1;
};

struct RecipientState {
  // Generic values.
  CLPublicKey issuerKey;
  CLMessages attributes;
  CLMessage s; // Master secret
  CredentialIdentifier id;
  Attributes attr;

  // Protocol values.
  unsigned char vPrime[VPRIME_BYTES];
  Nonce n_2;
};

struct VerifierState {
  // Generic values.
  CLPublicKey issuerKey;
  Attributes attr;
  Selection D;

  // Protocol values.
  Nonce n_1;
};

struct ProverState {
  // Generic values.
  CLPublicKey issuerKey;
  CLMessage attributes;
  CLSignature signature;
  CLMessage masterSecret;
  Selection D;
};

/******************************************************************************
 * PREPARATION                                                                *
 ******************************************************************************/

int prepare_issuer(const CredentialIdentifier *cred,
    const Attributes *attr,
    struct IssuerState *session)
{
  // TODO: Prepare internal state according to high-level inputs.
}

int prepare_recipient(const CredentialIdentifier *cred,
    const Attributes *attr,
    struct RecipientState *session){
  // TODO: Prepare internal state according to high-level inputs.
}

int prepare_verifier(const CredentialIdentifier *cred,
    const Attributes *attr,
    struct VerifierState *session){
  // TODO: Prepare internal state according to high-level inputs.
}

int prepare_prover(const Credential *cred,
    const Attributes *attr,
    struct ProverState *session){
  // TODO: Prepare internal state according to high-level inputs.
}

/******************************************************************************
 * ISSUANCE                                                                   *
 ******************************************************************************/

int issue_challenge(struct IssuerState *session, Nonce *n_1) 
{
  int i;
  randombytes(n_1->v, NONCE_BYTES);
  for(i=0;i<NONCE_BYTES;i++)
    session->n_1.v[i] = n_1->v[i];
}

int issue_commit(struct RecipientState *session, const Nonce *n_1, Number *U,
                 ProofU *P_U, Nonce *n_2) 
{
  /*
  unsigned long i,j;
  Number Utilde;
  const unsigned int vprimetildelen = N_BYTES+2*NONCE_BYTES+HASH_BYTES;
  unsigned char vprimetilde[vprimetildelen];
  unsigned char *buf;

  buf = (unsigned char *)malloc((session->issuerKey.count+5)*sizeof(Number)+sizeof(Nonce));
  if(!buf) return -1; //XXX Figure out error code.

  // COMPUTE_COMMITMENT
  randombytes(session->vPrime, VPRIME_BYTES);
  number_doublexp(U,session->issuerKey.S,session->vPrime,VPRIME_BYTES,session->issuerKey.R[0],session->s,M_BYTES);
  // PROVE_COMMITMENT
  randombytes(P_U->sHat,SHAT_BYTES);
  P_U->sHat[0] &= 1;
  randombytes(vprimetilde,vprimetildelen);
  number_doublexp(&Utilde,session->issuerKey.S,vprimetilde,vprimetildelen,session->issuerKey.R[0],sHat,SHAT_BYTES);

  for(j=0;j<N_BYTES;j++)
    buf[j] = session->issuerKey.n.v[j];
  for(j=0;j<N_BYTES;j++)
    buf[j+N_BYTES] = session->issuerKey.Z.v[j];
  for(j=0;j<N_BYTES;j++)
    buf[j+2*N_BYTES] = session->issuerKey.S.v[j];
  for(i=0;i<session->issuerKey.count;i++)
    for(j=0;j<N_BYTES;j++)
      buf[j+(i+3)*N_BYTES] = session->issuerKey.R[i].v[j];
  for(j=0;j<N_BYTES;j++)
    buf[j+(i+3)*N_BYTES] = U->v[j];
  for(j=0;j<N_BYTES;j++)
    buf[j+(i+4)*N_BYTES] = Utilde.v[j];
  for(j=0;j<NONCE_BYTES;j++)
    buf[j+(i+5)*N_BYTES] = n1->v[j];
  
  hash(P_U->c.v,buf,(session->issuerKey.count+5)*sizeof(Number)+sizeof(Nonce));
  bigint_mul(P_U->sHat, session->s, M_BYTES, P_U->c.v, HASH_BYTES);
  

  
  // TODO

  // context = issuerKey || attributes

  // Generate a fresh nonce: n_2.
  randombytes(n_2->v, NONCE_BYTES);
  for(i=0;i<NONCE_BYTES;i++)
    session->n_2.v[i] = n_2->v[i];

  free(buf);

  */
  return 0;
}

int issue_sign(struct IssuerState *session, const Number U, const ProofU P_U,
               CLSignature *S, ProofS *P_S) {
  // TODO: Implement according to specification: SIGN().
}

int issue_construct(struct RecipientState *session, const CLSignature S,
                    const ProofS P_S, Credential *C) {
  // TODO: Implement according to specification: CREDENTIAL().
}

/******************************************************************************
 * VERIFICATION                                                               *
 ******************************************************************************/

int verify_challenge(struct VerifierState *session, Nonce *n_1) 
{
  int i;
  randombytes(n_1->v, NONCE_BYTES);
  for(i=0;i<NONCE_BYTES;i++)
    session->n_1.v[i] = n_1->v[i];
}

int generate_proof(struct ProverState *session, const Nonce *n_1, ProofD *P_D) {
  // TODO: Implement according to specification: PROVE().
}

int verify_proof(struct VerifierState *session, ProofD P_D, Attributes *attr) {
  // TODO: Implement according to specification: VERIFY().
}
