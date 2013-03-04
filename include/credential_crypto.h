/**
 * Low-level cryptographic credential operations.
 *
 * @author Pim Vullers (pim@cs.ru.nl)
 */

#ifndef CREDENTIAL_CRYPTO_H
#define CREDENTIAL_CRYPTO_H

#include "credential_types.h"
#include "credential_crypto_types.h"

struct IssuerState;
struct RecipientState;
struct VerifierState;
struct ProverState;

/**
 * Prepare the internal IssuerState for a new session based on high-level input
 * and an external data structure.
 *
 * @param session contains the internal state for the issuer in this session.
 * @param cred identifier that indicates which credential is to be issued
 *             (and hence which set of parameters should be used).
 * @param attr list of attributes to be included in this credential.
 * @return status.
 */
int prepare_issuer(struct IssuerState *session, const CredentialIdentifier *cred,
                   const Attributes *attr);

/**
 * Prepare the internal RecipientState for a new session based on high-level
 * input and an external data structure.
 *
 * @param session contains the internal state for the recipient in this session.
 * @param cred identifier that indicates which credential is to be issued
 *             (and hence which set of parameters should be used).
 * @param attr list of attributes to be included in this credential.
 * @return status.
 */
int prepare_recipient(struct RecipientState *session, const CredentialIdentifier *cred,
                      const Attributes *attr);

/**
 * Prepare the internal VerifierState for a new session based on high-level
 * input and an external data structure.
 *
 * @param session contains the internal state for the verifier in this session.
 * @param cred identifier that indicates which credential is to be verified
 *             (and hence which set of parameters should be used).
 * @param attr list of attributes requested from this credential.
 * @return status.
 */
int prepare_verifier(struct VerifierState *session, const CredentialIdentifier *cred,
                     const Attributes *attr);

/**
 * Prepare the internal ProverState for a new session based on high-level
 * input and an external data structure.
 *
 * @param session contains the internal state for the prover in this session.
 * @param cred identifier that indicates which credential is to be verified
 *             (and hence which set of parameters should be used).
 * @param attr list of attributes requested from this credential.
 * @return status.
 */
int prepare_prover(struct ProverState *session, const CredentialIdentifier *cred,
                   const Attributes *attr);



/**
 * Idemix credential issuance (round 0)
 *
 * The issuer executes this command to generate a fresh nonce.
 */
int issue_challenge(struct IssuerState *session, Nonce *n_1);

/**
 * Idemix credential issuance (round 1)
 *
 * The receipient executes this command to generate a commitment.
 */
int issue_commit(struct RecipientState *session, const Nonce n_1, Number *U,
                 ProofU *P_U, Nonce *n_2);

/**
 * Idemix credential issuance (round 2)
 *
 * The issuer executes this command to construct a signature.
 */
int issue_sign(struct IssuerState *session, const Number U, const ProofU P_U,
               CLSignature *S, ProofS *P_S);

/**
 * Idemix credential issuance (round 3)
 *
 * The receipient executes this command to construct a credential.
 */
int issue_construct(struct RecipientState *session, const CLSignature S,
                    const ProofS P_S, Credential *C);



/**
 * Idemix credential proving (round 0)
 *
 * The verifier executes this command to generate a fresh nonce.
 */
int verify_challenge(struct VerifierState *session, Nonce *n_1);

/**
 * Idemix credential verification (round 1)
 *
 * The prover executes this command to generate a proof-of-knowledge.
 */
int generate_proof(struct ProverState *session, const Nonce n_1, ProofD *P_D);

/**
 * Idemix credential verification (round 2)
 *
 * The verifier executes this command to verify the proof from the prover.
 */
int verify_proof(struct VerifierState *session, ProofD P_D, Attributes *attr);

#endif // CREDENTIAL_CRYPTO_H
