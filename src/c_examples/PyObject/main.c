#include "./pyobject.c"

int main(void)
{
    PyIntObject *int_object = PyInt_Create(542);

    if(int_object != NULL)
    {
        PyInt_Type.ty_print((PyIntObject *)int_object);
    }

    PyStrObject *string_object = PyStr_Create("Hell, world!");
    if(string_object != NULL)
    {
        PyStr_Type.ty_print((PyStrObject*) string_object);
    }
}