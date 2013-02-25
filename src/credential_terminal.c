#include "credential_terminal.h"

#include "credential_crypto.h"

int credential_issue_init(const CredentialIdentifier cred, 
                          const Attributes *attr,
                          CommandAPDUs *command, 
                          IssuanceState *state) {

  // TODO(PV): Perform Idemix issuance protocol (init).
  //issue_challenge(...);

  // TODO(PV): Generate commitment commands.
  //issue_commit_commands(...);

  // TODO(PV): Save state.
}
                     
int credential_issue_sign(const CredentialIdentifier cred, 
                          const Attributes *attr, 
                          const ResponseAPDUs *response, CommandAPDUs *command, 
                          IssuanceState *state) {

  // TODO(PV): Restore state.

  // TODO(PV): Translate APDUs to internal data structures.
  //issue_commit_responses(...);

  // TODO(PV): Perform Idemix issuance protocol (sign).
  //issue_sign(...);

  // TODO(PV): Generate credential construction commands.
  //issue_construct_commands(...);

  // TODO(PV): Save state.
}

int credential_issue_check(const CredentialIdentifier cred, 
                           const Attributes *attr, 
                           const ResponseAPDUs *response,
                           IssuanceState *state) {

  // TODO(PV): Restore state.

  // TODO(PV): Translate APDUs to internal data structures.
  //issue_construct_responses(...);
}


int credential_verify_init(const CredentialIdentifier cred, Attributes *attr,
                           CommandAPDUs *command, 
                           VerificationState *state) {

  // TODO(PV): Perform Idemix verification protocol (init).
  //verify_challenge(...);

  // TODO(PV): Generate Idemix verification commands.
  //generate_proof_commands(...);

  // TODO(PV): Save state.
}

int credential_verify_check(const CredentialIdentifier cred, Attributes *attr,
                            const ResponseAPDUs *response, 
                            VerificationState *state) {

  // TODO(PV): Restore state.

  // TODO(PV): Translate APDUs to internal data structures.
  //generate_proof_responses(...);
  
  // TODO(PV): Perform Idemix verification protocol (verify).
  //verify_proof(...);
}

