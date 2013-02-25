/**
 * High-level interface for credential operations in terminal applications.
 *
 * @author Pim Vullers (pim@cs.ru.nl)
 */

#ifndef CREDENTIAL_TERMINAL_H
#define CREDENTIAL_TERMINAL_H

#include "credential_types.h"

// Return values for this library
#define SUCCESS 0
#define FAILURE -1
#define PRESENT -2
#define INVALID -3
#define MISSING -4

// Command APDU (according to ISO7816) with an additional identifier.
typedef struct {
  const char *id;
  unsigned long idLength;
  unsigned char cla;
  unsigned char ins;
  unsigned char p1;
  unsigned char p2;
  unsigned char *data;
  unsigned long dataLength
} CommandAPDU;

/**
 * List of command APDUs.
 *
 * @param apdu list of command APDUs.
 * @param count number of commands in the list.
 */
typedef struct {
  CommandAPDU *apdu;
  unsigned long count;
} CommandAPDUs;

// Response APDU (according to ISO7816) with an additional identifier to link to
// the executed command.
typedef struct {
  const char *id;
  unsigned long idLength;
  unsigned char *data;
  unsigned long dataLength;
  unsigned short sw;
} ResponseAPDU;

/**
 * List of response APDUs.
 *
 * @param apdu list of response APDUs.
 * @param count number of responses in the list.
 */
typedef struct {
  ResponseAPDU *apdu;
  unsigned long count;
} ResponseAPDUs;

// Internal state object that stores information needed for future processing.
typedef struct {
  unsigned char *nonce;
  unsigned long length;
} State;

// For now the state objects contain the same data.
typedef IssuanceState State;
typedef VerificationState State;

/**
 * Issue a new credential (step 1, initialisation)
 *
 * @param cred identifier that indicates which credential is to be issued 
 *             (and hence which set of parameters should be used).
 * @param attr list of attributes to be included in this credential.
 * @param command list of APDUs to be send to the card.
 * @param state information that needs to be stored for future processing.
 * @return SUCCESS if the command generation was successful, or
 *         FAILURE if the credential issuance has failed.
 */
int credential_issue_init(const CredentialIdentifier cred, 
                          const Attributes *attr,
                          CommandAPDUs *command, 
                          IssuanceState *state);
                     
/**
 * Issue a new credential (step 2, sign the commitment).
 *
 * @param cred identifier that indicates which credential is to be issued 
 *             (and hence which set of parameters should be used).
 * @param attr list of attributes to be included in this credential.
 * @param response list of APDUs received from the card.
 * @param command list of APDUs to be send to the card.
 * @param state information that has been, or needs to be, stored for future 
 *              processing.
 * @return SUCCESS if the command generation was successful, or
 *         FAILURE if the credential issuance has failed, or
 *         PRESENT if the credential was already present.
 */
int credential_issue_sign(const CredentialIdentifier cred, 
                          const Attributes *attr, 
                          const ResponseAPDUs *response, CommandAPDUs *command, 
                          IssuanceState *state);

/**
 * Issue a new credential (step 3, check the responses).
 *
 * @param cred identifier that indicates which credential is to be issued 
 *             (and hence which set of parameters should be used).
 * @param attr list of attributes to be included in this credential.
 * @param response list of APDUs received from the card.
 * @param state information that has been stored for future processing.
 * @return SUCCESS if the credential issuance was successful, or
 *         FAILURE if the credential issuance has failed.
 */
int credential_issue_check(const CredentialIdentifier cred, 
                           const Attributes *attr, 
                           const ResponseAPDUs *response,
                           IssuanceState *state);

/**
 * Verify attributes from a credential (step 1, initialisation).
 *
 * @param cred identifier that indicates which credential is to be verified
 *             (and hence which set of parameters should be used).
 * @param attr list of attributes requested from this credential, the attribute
 *             values will be set after successful verification.
 * @param command list of APDUs to be send to the card.
 * @param state information that needs to be stored for future processing.
 * @return SUCCESS if the command generation was successful, or
 *         FAILURE if the credential verification has failed.
 */
int credential_verify_init(const CredentialIdentifier cred, Attributes *attr,
                           CommandAPDUs *command, 
                           VerificationState *state);

/**
 * Verify attributes from a credential (step 2, check the responses, that is,
 * the generated proof).
 *
 * @param cred identifier that indicates which credential is to be verified
 *             (and hence which set of parameters should be used).
 * @param attr list of attributes requested from this credential, the attribute
 *             values will be set after successful verification.
 * @param response list of APDUs received from the card.
 * @param state information that has been stored for future processing.
 * @return SUCCESS if the credential verification was successful, or
 *         FAILURE if the credential verification has failed, or
 *         INVALID if the credential was not valid, or
 *         MISSING if the credential was not available.
 */
int credential_verify_check(const CredentialIdentifier cred, Attributes *attr,
                            const ResponseAPDUs *response, 
                            VerificationState *state);

#endif // CREDENTIAL_TERMINAL_H
