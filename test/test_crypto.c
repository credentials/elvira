#include "credential_crypto.h"

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

  status = prepare_issuer(id, attr, iSession);
  if (status != SUCCESS) {
    // Error reporting & handling.
    return status;
  }

  status = prepare_recipient(id, attr, rSession);
  if (status != SUCCESS) {
    // Error reporting & handling.
    return status;
  }

  status = issue_challenge(iSession, &n_1);
  if (status != SUCCESS) {
    // Error reporting & handling.
    return status;
  }

  status = issue_commit(rSession, n_1, &U, &P_U, &n_2);
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

  return SUCCESS;
}

int doVerification(const Credential *cred, Attributes *attr) {
  int status;
  struct VerifierState *vSession;
  struct ProverState *pSession;
  Nonce n_1;
  ProofD P_D;

  status = prepare_verifier(&(cred->id), attr, vSession);
  if (status != SUCCESS) {
    // Error reporting & handling.
    return status;
  }

  status = prepare_prover(cred, attr, pSession);
  if (status != SUCCESS) {
    // Error reporting & handling.
    return status;
  }

  status = verify_challenge(vSession, &n_1);
  if (status != SUCCESS) {
    // Error reporting & handling.
    return status;
  }

  status = generate_proof(pSession, n_1, &P_D);
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
