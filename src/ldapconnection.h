#ifndef LDAPCONNECTION_H_
#define LDAPCONNECTION_H_

#include <Python.h>
#include "structmember.h"

#include "ldap-xplat.h"
#include "utils.h"

typedef struct {
    PyObject_HEAD
    PyObject *client;
    PyObject *pending_ops;
    LDAP *ld;
    char closed;
    char async;
    char ppolicy;
    SOCKET csock;
    PyObject *socketpair;
} LDAPConnection;

extern PyTypeObject LDAPConnectionType;

int LDAPConnection_IsClosed(LDAPConnection *self);
int LDAPConnection_Searching(LDAPConnection *self, ldapsearchparams *params, PyObject *iterator);

#endif /* LDAPCONNECTION_H_ */
