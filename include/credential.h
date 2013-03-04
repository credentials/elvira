/**
 * High-level interface for credential operations.
 *
 * @author Pim Vullers (pim@cs.ru.nl)
 */

#ifndef CREDENTIAL_H
#define CREDENTIAL_H

#include "credential_types.h"

// Return values for this library
#define SUCCESS 0
#define FAILURE -1
#define PRESENT -2
#define INVALID -3
#define MISSING -4

/**
 * Issue a new credential.
 *
 * @param cred identifier that indicates which credential is to be issued
 *             (and hence which set of parameters should be used).
 * @param attr list of attributes to be included in this credential.
 * @return SUCCESS if the credential issuance was successful, or
 *         FAILURE if the credential issuance has failed, or
 *         PRESENT if the credential was already present.
 */
int credential_issue(const CredentialIdentifier *cred, const Attributes *attr);

/**
 * Verify attributes from a credential.
 *
 * @param cred identifier that indicates which credential is to be verified
 *             (and hence which set of parameters should be used).
 * @param attr list of attributes requested from this credential, the attribute
 *             values will be set after successful verification.
 * @return SUCCESS if the credential verification was successful, or
 *         FAILURE if the credential verification has failed, or
 *         INVALID if the credential was not valid, or
 *         MISSING if the credential was not available.
 */
int credential_verify(const CredentialIdentifier *cred, Attributes *attr);

#endif // CREDENTIAL_H
