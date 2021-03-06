#include "credential_terminal.h"

#include "credential_crypto.h"

// Internal state object that stores information needed for future processing.
typedef struct {
  unsigned char *nonce;
  unsigned long length;
  // TODO: add crypto internal state.
} State;

// For now the state objects contain the same data.
typedef State IssuanceState;
typedef State VerificationState;

/******************************************************************************
 * ISSUANCE                                                                   *
 ******************************************************************************/

int credential_issue_init(const CredentialIdentifier *cred,
                          const Attributes *attr,
                          CommandAPDUs *command,
                          struct IssuanceState *state) {
  int status;
  struct IssuerState *session;
  Nonce n_1;

  // Prepare the issuer.
  status = prepare_issuer(cred, attr, session);
  if (status != SUCCESS) {
    // TODO: Error handling.
    return status;
  }

  // Perform Idemix issuance protocol (init).
  status = issue_challenge(session, &n_1);
  if (status != SUCCESS) {
    // TODO: Error handling.
    return status;
  }

  // Generate the recipient preparation commands.
  status = prepare_recipient_commands(cred, attr, command);
  if (status != SUCCESS) {
    // TODO: Error handling.
    return status;
  }

  // Generate the Idemix issuance commands (commit).
  status = issue_commit_commands(n_1, command);
  if (status != SUCCESS) {
    // TODO: Error handling.
    return status;
  }

  // TODO: Save state.

  return SUCCESS;
}

int credential_issue_sign(const CredentialIdentifier *cred,
                          const Attributes *attr,
                          const ResponseAPDUs response, CommandAPDUs *command,
                          struct IssuanceState *state) {
  int status;
  struct IssuerState *session;
  Number U;
  ProofU P_U;
  Nonce n_2;
  CLSignature S;
  ProofS P_S;

  // TODO: Restore state.

  // Process the recipient preparation responses.
  status = prepare_recipient_responses(response);
  if (status != SUCCESS) {
    // TODO: Error handling.
    return status;
  }

  // Process the Idemix issuance responses (commit).
  status = issue_commit_responses(response, &U, &P_U, &n_2);
  if (status != SUCCESS) {
    // TODO: Error handling.
    return status;
  }

  // Perform Idemix issuance protocol (sign).
  status = issue_sign(session, U, P_U, &S, &P_S);
  if (status != SUCCESS) {
    // TODO: Error handling.
    return status;
  }

  // Generate the Idemix issuance commands (construct).
  status = issue_construct_commands(S, P_S, command);
  if (status != SUCCESS) {
    // TODO: Error handling.
    return status;
  }

  // TODO: Save state.

  return SUCCESS;
}

int credential_issue_check(const CredentialIdentifier *cred,
                           const Attributes *attr,
                           const ResponseAPDUs response,
                           struct IssuanceState *state) {
  int status;

  // TODO: Restore state.

  // Process the Idemix issuance responses (construct).
  status = issue_construct_responses(response);
  if (status != SUCCESS) {
    // TODO: Error handling.
    return status;
  }

  return SUCCESS;
}

/******************************************************************************
 * VERIFICATION                                                               *
 ******************************************************************************/

int credential_verify_init(const CredentialIdentifier *cred, const Attributes *attr,
                           CommandAPDUs *command,
                           struct VerificationState *state) {
  int status;
  struct VerifierState *session;
  Nonce n_1;

  // Prepare the verifier.
  status = prepare_verifier(cred, attr, session);
  if (status != SUCCESS) {
    // TODO: Error handling.
    return status;
  }

  // Perform Idemix verification protocol (init).
  status = verify_challenge(session, &n_1);
  if (status != SUCCESS) {
    // TODO: Error handling.
    return status;
  }

  // Generate the prover preparation commands.
  status = prepare_prover_commands(cred, attr, command);
  if (status != SUCCESS) {
    // TODO: Error handling.
    return status;
  }

  // Generate Idemix verification commands (prove).
  status = generate_proof_commands(n_1, command);
  if (status != SUCCESS) {
    // TODO: Error handling.
    return status;
  }

  // TODO: Save state.

  return SUCCESS;
}

int credential_verify_check(const CredentialIdentifier *cred,
                            const ResponseAPDUs response,
                            Attributes *attr,
                            struct VerificationState *state) {

  int status;
  struct VerifierState *session;
  ProofD P_D;

  // TODO: Restore state.

  // Process the prover preparation responses.
  status = prepare_prover_responses(response);
  if (status != SUCCESS) {
    // TODO: Error handling.
    return status;
  }

  // Process the Idemix verification responses (prove).
  status = generate_proof_responses(response, &P_D);
  if (status != SUCCESS) {
    // TODO: Error handling.
    return status;
  }

  // Perform Idemix verification protocol (verify).
  status = verify_proof(session, P_D, attr);
  if (status != SUCCESS) {
    // TODO: Error handling.
    return status;
  }

  return SUCCESS;
}
