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

} PyTypeObject;

typedef struct
{
    PyObject ob_base;
    int ob_ival;
} PyIntObject;

typedef struct
{
    PyObject ob_base;
    const char *message;
} PyStrObject;

void Py_INCREREF(PyObject *obj);
void Py_DECREF(PyObject *obj);
void Py_Dealloc(PyObject *obj);

PyIntObject *PyInt_Create(int value);
void PyInt_Print(PyObject *obj);

PyStrObject *PyStr_Create(const char *mesaage);
void PyStr_Print(PyObject *obj);


#endif