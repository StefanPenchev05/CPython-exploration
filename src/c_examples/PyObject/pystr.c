#include "./header/pystr.h"

// Function to create a new PyStrObject
PyStrObject *PyStr_Create(const char *message)
{
    // Allocate memory for the new PyStrObject
    PyStrObject *obj = (PyStrObject *)malloc(sizeof(PyStrObject));
    if (obj != NULL)
    {
        // Initialize the reference count, type, and message of the new PyStrObject
        obj->ob_base.ob_refcnt = 1;
        extern PyTypeObject PyStr_Type;
        obj->ob_base.ob_type = &PyStr_Type;
        obj->message = message;
    }

    // Return the new PyStrObject
    return obj;
}

// Function to print a PyStrObject
void PyStr_Print(PyObject *_object)
{
    // Cast the PyObject to a PyStrObject
    PyStrObject *string_object = (PyStrObject *)_object;

    // Get the message and type name of the PyStrObject
    const char *message = string_object->message;
    const char *name = string_object->ob_base.ob_type->name;

    // Print the type and value of the PyStrObject
    printf("Type is string - the value of %s is %s \n", name, message);
}

// Function to get the length of a PyStrObject's message
int PyStr_Len(PyObject *_object)
{
    // Check if the PyObject is NULL
    if (_object == NULL)
    {
        printf("Error: _object is NULL\n");
        return -1;
    }

    // Cast the PyObject to a PyStrObject
    PyStrObject *string_object = (PyStrObject *)_object;

    // Check if the PyStrObject's message is NULL
    if (string_object->message == NULL)
    {
        printf("Error: message is NULL\n");
        return -1;
    }

    // Count the number of characters in the PyStrObject's message
    size_t count = 0;
    size_t i = 0;
    while (string_object->message[i] != '\0')
    {
        count++;
        i++;
    }

    // Return the length of the PyStrObject's message
    return count;
}

// PyStr_Type structure
PyTypeObject PyStr_Type = 
{
    "message",    // Type name
    PyStr_Print,  // Print function
    Py_Dealloc    // Deallocate function
};