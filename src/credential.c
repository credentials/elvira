#include "credential.h"

#include "credential_terminal.h"

/**
 * Transmit command APDUs to a card and store the responses for processing.
 *
 * @param command list of APDUs to be send to the card.
 * @param response list of APDUs received from the card.
 * @return status.
 */
static int transmitAPDUS(const CommandAPDUs *command, ResponseAPDUs *response) {
  // TODO: implement PC/SC transmit command.
}

int credential_issue(const CredentialIdentifier *cred, const Attributes *attr) {
  int status;
  CommandAPDUs command;
  ResponseAPDUs response;
  struct IssuanceState *state;

  // TODO: Verify input values and retrieve credential information.

  status = credential_issue_init(cred, attr, &command, state);
  if (status != SUCCESS) {
    // TODO: Error handling and cleanup.
    return status;
  }

  status = transmitAPDUs(command, &response);
  if (status != SUCCESS) {
    // TODO: Error handling and cleanup.
    return FAILURE;
  }

  status = credential_issue_sign(cred, attr, response, &command, state);
  if (status != SUCCESS) {
    // TODO: Error handling and cleanup.
    return status;
  }

  status = transmitAPDUs(command, &response);
  if (status != SUCCESS) {
    // TODO: Error handling and cleanup.
    return FAILURE;
  }

  status = credential_issue_check(cred, attr, response, state);
  if (status != SUCCESS) {
    // TODO: Error handling and cleanup.
    return status;
  }

  return SUCCESS;
}

int credential_verify(const CredentialIdentifier *cred, Attributes *attr) {
  int status;
  CommandAPDUs command;
  ResponseAPDUs response;
  struct VerificationState *state;

  // TODO: Verify input values and retrieve credential information.

  status = credential_verify_init(cred, attr, &command, state);
  if (status != SUCCESS) {
    // TODO: Error handling and cleanup.
    return status;
  }

  status = transmitAPDUs(command, &response);
  if (status != SUCCESS) {
    // TODO: Error handling and cleanup.
    return FAILURE;
  }

  status = credential_verify_check(cred, response, attr, state);
  if (status != SUCCESS) {
    // TODO: Error handling and cleanup.
    return status;
  }

  return SUCCESS;
}

