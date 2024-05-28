#ifndef PYINTOBJECT
#define PYINTOBJECT

#include "./pyobject.h"

typedef struct 
{
    PyObject ob_base;
    int ob_ival;
} PyIntObject;

PyIntObject *PyInt_Create(int value);
void Reassign_Int_Object(PyObject **obj, int newValue);
void PyInt_Print(PyObject *obj);
int ReferenceCount(PyObject *obj);

#endif