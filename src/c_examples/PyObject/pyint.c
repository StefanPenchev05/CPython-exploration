#include "./header/pyint.h"

PyIntObject *PyInt_Create(int value)
{
    PyIntObject *obj = (PyIntObject *)malloc(sizeof(PyIntObject));
    if (obj != NULL)
    {
        obj->ob_base.ob_refcnt = 1;
        extern PyTypeObject PyInt_Type;
        obj->ob_base.ob_type = &PyInt_Type;
        obj->ob_ival = value;
    }

    return obj;
}

void PyInt_Print(PyObject *_object)
{
    PyIntObject *int_object = (PyIntObject *)_object;
    int value = int_object->ob_ival;
    const char *name = int_object->ob_base.ob_type->name;
    printf("Type is int - the value of %s is %d \n", name, value);
}

PyTypeObject PyInt_Type = 
{
    "integer",
    PyInt_Print,
    Py_Dealloc
};