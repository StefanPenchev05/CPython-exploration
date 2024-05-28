#include "./header/pyint.h"

// Function to create a new PyIntObject or return an existing one with the same value
PyIntObject *PyInt_Create(int value)
{
    extern PyTypeObject PyInt_Type;

    // Check if a PyIntObject with the same value already exists in the registry
    for (size_t i = 0; i < registry.count; i++)
    {
        if (registry.objects[i]->ob_type == &PyInt_Type)
        {
            PyIntObject *int_type = (PyIntObject *)registry.objects[i];
            if (int_type->ob_ival == value)
            {
                // If an existing PyIntObject with the same value is found, increment its reference count and return it
                Py_INCREREF((PyObject *)registry.objects[i]);
                return int_type;
            }
        }
    }

    // If no existing PyIntObject with the same value is found, create a new one
    PyIntObject *obj = (PyIntObject *)malloc(sizeof(PyIntObject));
    if (obj != NULL)
    {
        obj->ob_base.ob_refcnt = 1;
        obj->ob_base.ob_type = &PyInt_Type;
        obj->ob_ival = value;
        // Add the new PyIntObject to the registry
        Add_to_registry(obj);
    }

    return obj;
}

// Function to reassign a PyIntObject to a new value
void Reassign_Int_Object(PyObject **_object, int newValue)
{
    // If the object is not NULL, decrement its reference count
    if(*_object != NULL){
        Py_DECREF(*_object);
    }
    
    // Create a new PyIntObject with the new value and assign it to the object
    *_object = PyInt_Create(newValue);
}

// Function to print a PyIntObject
void PyInt_Print(PyObject *_object)
{
    PyIntObject *int_object = (PyIntObject *)_object;
    int value = int_object->ob_ival;
    const char *name = int_object->ob_base.ob_type->name;
    printf("Type is int - the value of %s is %d \n", name, value);
}

// Function to get the reference count of an object
int ReferenceCount(PyObject *obj)
{
    return obj->ob_refcnt;
}

// PyInt_Type structure
PyTypeObject PyInt_Type =
    {
        "integer",          // Type name
        PyInt_Print,        // Print function
        Py_Dealloc,         // Deallocate function
        ReferenceCount,     // Reference count function
        Reassign_Int_Object // Reassign function
    };