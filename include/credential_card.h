/**
 * Low-level card operations (APDU procesing).
 *
 * @author Pim Vullers (pim@cs.ru.nl)
 */

#ifndef CREDENTIAL_CARD_H
#define CREDENTIAL_CARD_H

/**
 * Prepare the card for a new session based on high-level input and an external
 * data structure.
 *
 * @param cred identifier that indicates which credential is to be issued
 *             (and hence which set of parameters should be used).
 * @param attr list of attributes to be included in this credential.
 * @param command list of APDUs to be send to the card.
 * @return status.
 */
int prepare_recipient_commands(const CredentialIdentifier cred, 
                               const Attributes attr, CommandAPDUs *command);

/**
 * Prepare the card for a new session based on high-level input and an external 
 * data structure.
 *
 * @param response list of APDUs received from the card. 
 * @return status.
 */
int prepare_recipient_responses(const ResponseAPDUs response);

/**
 * Prepare the card for a new session based on high-level input and an external 
 * data structure.
 *
 * @param cred identifier that indicates which credential is to be verified
 *             (and hence which set of parameters should be used).
 * @param attr list of attributes requested from this credential.
 * @param command list of APDUs to be send to the card.
 * @return status.
 */
int prepare_prover_commands(const CredentialIdentifier cred, 
                            const Attributes attr, CommandAPDUs *command);

/**
 * Prepare the card for a new session based on high-level input and an external 
 * data structure.
 *
 * @param response list of APDUs received from the card. 
 * @return status.
 */
int prepare_prover_responses(const ResponseAPDUs response);



/**
 * Idemix credential issuance (round 1)
 *
 * The receipient executes this command to generate a commitment.
 */
int issue_commit_commands(const Nonce n_1, CommandAPDUs *command);

/**
 * Idemix credential issuance (round 1)
 *
 * The receipient executes this command to generate a commitment.
 */
int issue_commit_responses(const ResponseAPDUs response, Number *U, 
                           ProofU *P_U, Nonce *n_2);

/**
 * Idemix credential issuance (round 3)
 *
 * The receipient executes this command to construct a credential.
 */
int issue_construct_commands(const CLSignature S, const ProofS P_S, 
                             CommandAPDUs *command);

/**
 * Idemix credential issuance (round 3)
 *
 * The receipient executes this command to construct a credential.
 */
int issue_construct_responses(const ResponseAPDUs response);



/**
 * Idemix credential verification (round 1)
 *
 * The prover executes this command to generate a proof-of-knowledge.
 */
int generate_proof_commands(const Nonce n_1, CommandAPDUs *command);

/**
 * Idemix credential verification (round 1)
 *
 * The prover executes this command to generate a proof-of-knowledge.
 */
int generate_proof_responses(const ResponseAPDUs response, ProofD *P_D);

#endif // CREDENTIAL_CARD_H
