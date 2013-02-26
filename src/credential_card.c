// TODO(PV): Implement APDU processing.

/******************************************************************************
 * PREPARATION                                                                *
 ******************************************************************************/

int prepare_recipient_commands(const CredentialIdentifier cred, 
                               const Attributes attr, CommandAPDUs *command) {
  // TODO: Generate the issuance protocol initialisation commands (see 
  //       specification).
}

int prepare_recipient_responses(const ResponseAPDUs response) {
  // TODO: Process the issuance protocol initialisation responses (see 
  //       specification).
}

int prepare_prover_commands(const CredentialIdentifier cred, 
                            const Attributes attr, CommandAPDUs *command) {
  // TODO: Generate the verification protocol initialisation commands (see 
  //       specification).
}

int prepare_prover_responses(const ResponseAPDUs response) {
  // TODO: Process the verification protocol initialisation responses (see 
  //       specification).
}

/******************************************************************************
 * ISSUANCE                                                                   *
 ******************************************************************************/

int issue_commit_commands(const Nonce n_1, CommandAPDUs *command) {
  // TODO: Generate the ISSUE_COMMITMENT, COMMITMENT_PROOF and CHALLENGE 
  //       commands (see specification).
}

int issue_commit_responses(const ResponseAPDUs response, Number *U, 
                           ProofU *P_U, Nonce *n_2);
  // TODO: Process the ISSUE_COMMITMENT, COMMITMENT_PROOF and CHALLENGE 
  //       responses (see specification).
}

int issue_construct_commands(const CLSignature S, const ProofS P_S, 
                             CommandAPDUs *command) {
  // TODO: Generate the ISSUE_SIGNATURE and SIGNATURE_PROOF commands (see
  //       specification).
}

int issue_construct_responses(const ResponseAPDUs response) {
  // TODO: Process the ISSUE_SIGNATURE and SIGNATURE_PROOF responses (see
  //       specification).
}

/******************************************************************************
 * VERIFICATION                                                               *
 ******************************************************************************/

int generate_proof_commands(const Nonce n_1, CommandAPDUs *command) {
  // TODO: Generate the PROVE_COMMITMENT, PROVE_SIGNATURE and ATTRIBUTE commands
  //       (see specification).
}

int generate_proof_responses(const ResponseAPDUs response, ProofD *P_D) {
  // TODO: Process the PROVE_COMMITMENT, PROVE_SIGNATURE and ATTRIBUTE responses
  //       (see specification).
}
