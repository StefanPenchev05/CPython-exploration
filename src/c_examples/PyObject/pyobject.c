#include "./header/pyobject.h"

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