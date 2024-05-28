#ifndef PYOBJECT
#define PYOBJECT

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

typedef struct _object
{
    unsigned int ob_refcnt;
    struct _typeObject *ob_type;
} PyObject;

typedef struct _typeObject
{
    const char *name;               // type name( for example 'numbers')
    void (*ty_print)(PyObject *);   // print function
    void (*ty_dealloc)(PyObject *); // deacollaction function
    int (*ty_len)(PyObject *);      // getting the len of string

} PyTypeObject;

void Py_INCREREF(PyObject *obj);
void Py_DECREF(PyObject *obj);
void Py_Dealloc(PyObject *_object)
{
    free(_object);
}

#endif