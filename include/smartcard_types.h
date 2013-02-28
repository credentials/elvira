/**
 * Data types for smart card interfaces.
 *
 * @author Pim Vullers (pim@cs.ru.nl)
 */

#ifndef SMARTCARD_TYPES_H
#define SMARTCARD_TYPES_H

// Command APDU (according to ISO7816) with an additional identifier.
typedef struct {
  const char *id;
  unsigned long idLength;
  unsigned char cla;
  unsigned char ins;
  unsigned char p1;
  unsigned char p2;
  unsigned char *data;
  unsigned long dataLength;
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

#endif // SMARTCARD_TYPES_H
