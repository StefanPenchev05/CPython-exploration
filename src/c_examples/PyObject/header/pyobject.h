#ifndef PYOBJECT
#define PYOBJECT

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

// Basic object structure
typedef struct _object
{
    unsigned int ob_refcnt;         // Reference count
    struct _typeObject *ob_type;    // Type of the object
} PyObject;

// Type object structure
typedef struct _typeObject
{
    const char *name;               // Type name (e.g., 'numbers')
    void (*ty_print)(PyObject *);   // Function to print the object
    void (*ty_dealloc)(PyObject *); // Function to deallocate the object
    int (*ty_ob_ref)(PyObject *);   // Function to show the number of references to the object
    void (*reassign)(PyObject **, int); // Function to reassign the object
    int (*ty_len)(PyObject *);      // Function to get the length of the string (if applicable)

} PyTypeObject;

// Registry structure to keep track of all live Python objects
typedef struct _registry
{
    PyObject **objects;             // Array of pointers to live Python objects
    size_t capacity;                // Current capacity of the array
    size_t count;                   // Current count of live Python objects

} Registry;

Registry registry = {NULL, 0, 0};  // Initialize the registry

// Function to increase the reference count of an object
void Py_INCREREF(PyObject *obj);

// Function to decrease the reference count of an object
void Py_DECREF(PyObject *obj);

// Function to deallocate an object
void Py_Dealloc(PyObject *_object)
{
    free(_object);
}

// Function to add an object to the registry
void Add_to_registry(PyObject *obj)
{
    // If the registry is full, double its capacity
    if (registry.count >= registry.capacity)
    {
        registry.capacity = registry.capacity == 0 ? 5 : registry.capacity * 2;
        registry.objects = realloc(registry.objects, registry.capacity * sizeof(PyObject *));
    }
    // Add the object to the registry and increase the count
    registry.objects[registry.count++] = obj;
}

#endif