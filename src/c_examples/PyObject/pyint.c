#include "./header/pyint.h"

PyIntObject *PyInt_Create(int value)
{
    extern PyTypeObject PyInt_Type;
    for (size_t i = 0; i < registry.count; i++)
    {
        if (registry.objects[i]->ob_type == &PyInt_Type)
        {
            PyIntObject *int_type = (PyIntObject *)registry.objects[i];
            if (int_type->ob_ival == value)
            {
                Py_INCREREF((PyObject *)registry.objects[i]);
                return int_type;
            }
        }
    }

    PyIntObject *obj = (PyIntObject *)malloc(sizeof(PyIntObject));
    if (obj != NULL)
    {
        obj->ob_base.ob_refcnt = 1;
        extern PyTypeObject PyInt_Type;
        obj->ob_base.ob_type = &PyInt_Type;
        obj->ob_ival = value;
        Add_to_registry(obj);
    }

    return obj;
}

void Reassign_Int_Object(PyObject **_object, int newValue)
{
    if(*_object != NULL){
        Py_DECREF(*_object);}
    
    *_object = PyInt_Create(newValue);
}

void PyInt_Print(PyObject *_object)
{
    PyIntObject *int_object = (PyIntObject *)_object;
    int value = int_object->ob_ival;
    const char *name = int_object->ob_base.ob_type->name;
    printf("Type is int - the value of %s is %d \n", name, value);
}

int ReferenceCount(PyObject *obj)
{
    return obj->ob_refcnt;
}

PyTypeObject PyInt_Type =
    {
        "integer",
        PyInt_Print,
        Py_Dealloc,
        ReferenceCount,
        Reassign_Int_Object
    };