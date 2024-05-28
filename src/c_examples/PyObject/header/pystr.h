#ifndef PYSTROBJECT
#define PYSTROBJECT

#include "./pyobject.h"

typedef struct 
{
    PyObject ob_base;
    char const *message;
} PyStrObject;

PyStrObject *PyStr_Create(const char *mesaage);
void PyStr_Print(PyObject *obj);
int PyStr_Len(PyObject *obj);

#endif