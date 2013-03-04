#include "credential_crypto.h"

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
  unsigned char vPrime[SIZE_VPRIME];
  Nonce n_2;
} RecipientState;

typedef struct {
  // Generic values.
  CLPublicKey issuerKey;
  Attributes attr;
  Selection D;

  // Protocol values.
  Nonce n_1;
} VerifierState;

typedef struct {
  // Generic values.
  CLPublicKey issuerKey;
  CLMessage attributes;
  CLSignature signature;
  CLMessage masterSecret;
  Selection D;
} ProverState;

/******************************************************************************
 * PREPARATION                                                                *
 ******************************************************************************/

int prepare_issuer(struct IssuerState *session, const CredentialIdentifier cred,
                   const Attributes attr) {
  // TODO: Prepare internal state according to high-level inputs.
}

int prepare_recipient(struct RecipientState *session, const CredentialIdentifier cred,
                      const Attributes attr) {
  // TODO: Prepare internal state according to high-level inputs.
}

int prepare_verifier(struct VerifierState *session, const CredentialIdentifier cred,
                     const Attributes attr) {
  // TODO: Prepare internal state according to high-level inputs.
}

int prepare_prover(struct ProverState *session, const CredentialIdentifier cred,
                   const Attributes attr) {
  // TODO: Prepare internal state according to high-level inputs.
}

/******************************************************************************
 * ISSUANCE                                                                   *
 ******************************************************************************/

int issue_challenge(struct IssuerState *session, Nonce *n_1) {
  // TODO: Generate a fresh nonce: n_1.
}

int issue_commit(struct RecipientState *session, const Nonce n_1, Number *U,
                 ProofU *P_U, Nonce *n_2) {
  // TODO: Implement according to specification: COMMIT().
  // TODO: Generate a fresh nonce: n_2.
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

int verify_challenge(struct VerifierState *session, Nonce *n_1) {
  // TODO: Generate a fresh nonce: n_1.
}

int generate_proof(struct ProverState *session, const Nonce n_1, ProofD *P_D) {
  // TODO: Implement according to specification: PROVE().
}

int verify_proof(struct VerifierState *session, ProofD P_D, Attributes *attr) {
  // TODO: Implement according to specification: VERIFY().
}
