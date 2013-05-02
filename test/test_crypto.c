#include "credential_crypto.h"

extern int initialise_test_state(struct IssuerState *iSession, struct RecipientState *rSession);
extern int clean_test_state(struct IssuerState *iSession, struct RecipientState *rSession);

int main(int argc, char *argv[]) {
  int status;
  CredentialIdentifier id;
  Credential cred;
  Attributes attr;
  Attributes selection;

  status = doIssuance(&id, &attr, &cred);
  if (status != SUCCESS) {
    // Error reporting & handling.
    return status;
  }

  status = doVerification(&cred, &selection);
  if (status != SUCCESS) {
    // Error reporting & handling.
    return status;
  }

  return SUCCESS;
}

int doIssuance(const CredentialIdentifier *id, const Attributes *attr,
               Credential *cred) {
  int status;
  struct IssuerState *iSession;
  struct RecipientState *rSession;
  Nonce n_1, n_2;
  Number U;
  ProofU P_U;
  CLSignature S;
  ProofS P_S;

  // Set up iSession and rSession
  init_issuance_test_state(iSession, rSession);

  status = issue_challenge(iSession, &n_1);
  if (status != SUCCESS) {
    // Error reporting & handling.
    return status;
  }

  status = issue_commit(rSession, &n_1, &U, &P_U, &n_2);
  if (status != SUCCESS) {
    // Error reporting & handling.
    return status;
  }

  status = issue_sign(iSession, U, P_U, &S, &P_S);
  if (status != SUCCESS) {
    // Error reporting & handling.
    return status;
  }

  status = issue_construct(rSession, S, P_S, cred);
  if (status != SUCCESS) {
    // Error reporting & handling.
    return status;
  }

  free_issuance_test_state(iSession, rSession);
  
  return SUCCESS;
}

int doVerification(const Credential *cred, Attributes *attr) {
  int status;
  struct VerifierState *vSession;
  struct ProverState *pSession;
  Nonce n_1;
  ProofD P_D;

  // TODO: set up vSession

  // TODO: set up pSession

  status = verify_challenge(vSession, &n_1);
  if (status != SUCCESS) {
    // Error reporting & handling.
    return status;
  }

  status = generate_proof(pSession, &n_1, &P_D);
  if (status != SUCCESS) {
    // Error reporting & handling.
    return status;
  }

  status = verify_proof(vSession, P_D, attr);
  if (status != SUCCESS) {
    // Error reporting & handling.
    return status;
  }

  return SUCCESS;
}
