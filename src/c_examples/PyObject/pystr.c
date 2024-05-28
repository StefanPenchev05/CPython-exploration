#include "./header/pystr.h"

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

void PyStr_Print(PyObject *_object)
{
    PyStrObject *string_object = (PyStrObject *)_object;
    const char *message = string_object->message;
    const char *name = string_object->ob_base.ob_type->name;
    printf("Type is string - the value of %s is %s \n", name, message);
}

int PyStr_Len(PyObject *_object)
{
    if (_object == NULL)
    {
        printf("Error: _object is NULL\n");
        return -1;
    }

    PyStrObject *string_object = (PyStrObject *)_object;
    if (string_object->message == NULL)
    {
        printf("Error: message is NULL\n");
        return -1;
    }

    size_t count = 0;
    size_t i = 0;
    while (string_object->message[i] != '\0')
    {
        count++;
        i++;
    }

    return count;
}

PyTypeObject PyStr_Type = 
{
    "message",
    PyStr_Print,
    Py_Dealloc
};