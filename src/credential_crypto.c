#include "credential_crypto.h"
#include "credential_crypto_types.h"
#include "randombytes.h"

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
  CLMessages a;
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

int issue_challenge(struct IssuerState *session, Nonce *n_1) {
  // TODO: Generate a fresh nonce: n_1.
  // Use random nonces.
  // Nonce goes to *n_1 and to session->n_1
}

int issue_commit(struct RecipientState *session, const Nonce n_1, Number *U,
                 ProofU *P_U, Nonce *n_2) {
  // TODO: Implement according to specification: COMMIT().
  // TODO: Generate a fresh nonce: n_2.
  // Nonce goes to session->n_2 and to *n_2
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
