#include "./pyobject.h"

void Py_INCREREF(PyObject *_object)
{
    _object->ob_refcnt++;
}

void Py_DECREF(PyObject *_object)
{
    if (--_object->ob_refcnt == 0)
    {
        if (_object->ob_type->ty_dealloc)
        {
            Py_Dealloc(_object);
        }
        else
        {
            free(_object);
        }
    }
}

void Py_Dealloc(PyObject *_object)
{
    free(_object);
}

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

PyStrObject *PyStr_Create(const char *message)
{
    PyStrObject *obj = (PyStrObject *)malloc(sizeof(PyStrObject));
    if (obj != NULL)
    {
        obj->ob_base.ob_refcnt = 1;
        extern PyTypeObject PyStr_Type;
        obj->ob_base.ob_type = &PyStr_Type;
        obj->message = message;
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

void PyStr_Print(PyObject *_object)
{
    PyStrObject *string_object = (PyStrObject *)_object;
    const char *message = string_object->message;
    const char *name = string_object->ob_base.ob_type->name;
    printf("Type is string - the value of %s is %s \n", name, message);
}

int PyStr_Len(PyObject *_object)
{
    if(_object == NULL)
    {
        printf("Error: _object is NULL\n");
        return -1;
    }
    PyStrObject *string_object = (PyStrObject *)_object;
    if(string_object->message == NULL)
    {
        printf("Error: message is NULL\n");
        return -1;
    }

    size_t count = 0;
    size_t i = 0;
    while(string_object->message[i] != '\0')
    {
        count++;
        i++;
    }

    return count;
}

PyTypeObject PyInt_Type =
    {
        "x",
        PyInt_Print,
        Py_Dealloc};

PyTypeObject PyStr_Type =
    {
        "message",
        PyStr_Print,
        Py_Dealloc};
