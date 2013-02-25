/**
 * Low-level cryptographic credential operations.
 *
 * @author Pim Vullers (pim@cs.ru.nl)
 */

#ifndef CREDENTIAL_CRYPTO_H
#define CREDENTIAL_CRYPTO_H

/**
 * Idemix credential issuance (round 0)
 *
 * The issuer executes this command to generate a fresh nonce.
 */
int issue_challenge(IssuerState state, Nonce *nonce);

/**
 * Idemix credential issuance (round 1)
 *
 * The receipient executes this command to generate a commitment.
 */
int issue_commit();

/**
 * Idemix credential issuance (round 2)
 *
 * The issuer executes this command to construct a signature.
 */
int issue_sign();

/**
 * Idemix credential issuance (round 3)
 *
 * The receipient executes this command to construct a credential.
 */
int issue_construct();



/**
 * Idemix credential proving (round 0)
 *
 * The verifier executes this command to generate a fresh nonce.
 */
int verify_challenge();

/**
 * Idemix credential verification (round 1)
 *
 * The prover executes this command to generate a proof-of-knowledge.
 */
int generate_proof();

/**
 * Idemix credential verification (round 2)
 *
 * The verifier executes this command to verify the proof from the prover.
 */
int verify_proof();

#endif // CREDENTIAL_CRYPTO_H
