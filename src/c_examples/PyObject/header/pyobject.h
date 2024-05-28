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
    void (*ty_dealloc)(PyObject *); // deallaction function
    int (*ty_ob_ref)(PyObject *);   // show the number of reference of the object
    int (*ty_len)(PyObject *);      // getting the len of string

} PyTypeObject;

typedef struct _registry
{
    PyObject **objects;
    size_t capacity;
    size_t count;
} Registry;

Registry registry = {NULL, 0, 0};

void Py_INCREREF(PyObject * obj);
void Py_DECREF(PyObject *obj);
void Py_Dealloc(PyObject *_object)
{
    free(_object);
}

void Add_to_registry(PyObject *obj)
{
    if(registry.count >= registry.capacity)
    {
        registry.capacity = registry.capacity == 0 ? 5 : registry.capacity * 2;
        registry.objects = realloc(registry.objects, registry.capacity * sizeof(PyObject *));
    }
    registry.objects[registry.count++] = obj;
} 

#endif