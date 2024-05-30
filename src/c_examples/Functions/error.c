#include "./header/Error.h"

#define EXIT_FAILURE -1

ErrorObject* create_error(const char *name, int statusCode, const char* message)
{
    ErrorObject *err_object = (ErrorObject *)malloc(sizeof(ErrorObject));
    if(err_object == NULL)
    {
        fprintf(stderr, "Faild to allocate memory");
        exit(EXIT_FAILURE);
    }

    err_object->name = name;
    err_object->ob_type.code = statusCode;
    err_object->ob_type.message = message; 
}

void destroy_error(ErrorObject *err_object)
{
    free(err_object);
}

void throw_error( ErrorObject *error)
{
    fprintf(stderr, "Error: %s\n", error->ob_type.message);
    exit(error->ob_type.code);
}