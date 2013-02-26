#include "credential_crypto.h"

/******************************************************************************
 * PREPARATION                                                                *
 ******************************************************************************/

int prepare_issuer(IssuerState *session, const CredentialIdentifier cred, 
                   const Attributes *attr) {
  // TODO: Prepare internal state according to high-level inputs.
}

int prepare_recipient(RecipientState *session, const CredentialIdentifier cred,
                      const Attributes *attr) {
  // TODO: Prepare internal state according to high-level inputs.
}

int prepare_verifier(VerifierState *session, const CredentialIdentifier cred,
                     const Attributes *attr) {
  // TODO: Prepare internal state according to high-level inputs.
}

int prepare_prover(ProverState *session, const CredentialIdentifier cred,
                   const Attributes *attr) {
  // TODO: Prepare internal state according to high-level inputs.
}

/******************************************************************************
 * ISSUANCE                                                                   *
 ******************************************************************************/

int issue_challenge(IssuerState *session, Nonce *n_1) {
  // TODO: Generate a fresh nonce: n_1.
}

int issue_commit(RecipientState *session, const Nonce n_1, Number *U, 
                 ProofU *P_U, Nonce *n_2) {
  // TODO: Implement according to specification: COMMIT().
  // TODO: Generate a fresh nonce: n_2.
}

int issue_sign(IssuerState *session, const Number U, const ProofU P_U, 
               CLSignature *S, ProofS *P_S) {
  // TODO: Implement according to specification: SIGN().
}

int issue_construct(RecipientState *session, const CLSignature S, 
                    const ProofS P_S, Credential *C) {
  // TODO: Implement according to specification: CREDENTIAL().
}

/******************************************************************************
 * VERIFICATION                                                               *
 ******************************************************************************/
 
int verify_challenge(VerifierState *session, Nonce *n_1) {
  // TODO: Generate a fresh nonce: n_1.
}

int generate_proof(ProverState *session, const Nonce n_1, ProofD *P_D) {
  // TODO: Implement according to specification: PROVE().
}

int verify_proof(VerifierState *session, ProofD P_D, Attributes *attr) {
  // TODO: Implement according to specification: VERIFY().
}
