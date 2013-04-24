/**
 * Key generation and related functionality.
 *
 * @author Pim Vullers (pim@cs.ru.nl)
 */

#ifndef CREDENTIAL_KEYS_H
#define CREDENTIAL_KEYS_H

#include "credential_crypto_types.h"

int generateCLKeyPair(CLPublicKey *public, CLPrivateKey *private);
int generateMasterSecret(CLMessage *masterSecret);

int serializeCLPublicKey(const CLPublicKey *key, char *data);
int serializeCLPrivateKey(const CLPrivateKey *key, char *data);
int serializeMasterSecret(const CLMessage *secret, char *data);

int deserializeCLPublicKey(const char *data, CLPublicKey *key);
int deserializeCLPrivateKey(const char *data, CLPrivateKey *key);
int deserializeMasterSecret(const char *data, CLMessage *secret);

int fetchCLPublicKey(const char *URI, unsigned long *URI_bytes, CLPublicKey *key);
int fetchCLPrivateKey(const char *URI, unsigned long *URI_bytes, CLPrivateKey *key);
int fetchMasterSecret(const char *URI, unsigned long *URI_bytes, CLMessage *secret);

int storeCLPublicKey(const char *URI, unsigned long *URI_bytes, const CLPublicKey *key);
int storeCLPrivateKey(const char *URI, unsigned long *URI_bytes, const CLPrivateKey *key);
int storeMasterSecret(const char *URI, unsigned long *URI_bytes, const CLMessage *secret);

#endif // CREDENTIAL_KEYS_H
