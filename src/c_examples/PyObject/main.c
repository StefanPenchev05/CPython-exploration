#include "./pyobject.c"

int main(void)
{
    PyIntObject *int_object = PyInt_Create(542);

    if(int_object != NULL)
    {
        PyInt_Type.ty_print((PyObject *)int_object);
        PyInt_Type.ty_dealloc(int_object);
    }

    PyStrObject *string_object = PyStr_Create("Hello, world!");
    if(string_object != NULL)
    {
        PyStr_Type.ty_print((PyObject*) string_object);
        int strlen = PyStr_Len(string_object);
        printf("The length of the string is %d", strlen);
        PyStr_Type.ty_dealloc(string_object);
    }
}