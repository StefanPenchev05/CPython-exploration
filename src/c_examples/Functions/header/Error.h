#ifndef ERROR
#define ERROR

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int code;
    const char *message;

} ErrorTypeObject;

typedef struct
{
    const char* name;
    ErrorTypeObject ob_type;

} ErrorObject;

ErrorObject* create_error(const char *name, int statusCode, const char* message);
void destroy_error(ErrorObject *err_object);
void throw_error(ErrorObject *error);

#endif