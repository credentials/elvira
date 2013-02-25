/**
 * Data types for credential interfaces.
 *
 * @author Pim Vullers (pim@cs.ru.nl)
 */

#ifndef CREDENTIAL_TYPES_H
#define CREDENTIAL_TYPES_H

/**
 * Credential identification by means of a URI which points to some file(s)
 * with more information.
 *
 * @param uri string which contains the URI.
 * @param length of the URI string.
 */
typedef struct {
  const char *uri;
  unsigned long length;
} CredentialIdentifier;

/**
 * Attribute name/value pair.
 *
 * @param name string which contains the attribute name.
 * @param length of the name string.
 * @param value bytearray containing the attribute value.
 * @param size of the attribute value.
 */
typedef struct {
  const char *name;
  unsigned long length;
  unsigned char *value;
  unsigned long size;
} Attribute;

/**
 * List of attributes.
 * 
 * @param attribute list of attributes.
 * @param count number of attributes in the list.
 */
typedef struct {
  Attribute *attribute;
  unsigned long count;
} Attributes;

#endif // CREDENTIAL_TYPES_H
