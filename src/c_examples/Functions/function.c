#include "./header/function.h"
#include "./error.c"

int StringLen(const char *name)
{
    char stopChar = '\0';
    int index = 0;
    size_t count = 0;
    while(name[index] != stopChar)
    {
        index++;
        count++;
    }

    return count;
}


void init_function_registry(FunctionRegistry *registry)
{
    registry->functions = NULL;
    registry->capacity = 0;
    registry->cout = 0;
}


void register_function(FunctionRegistry *registry, const char *name, FunctionPointer *func)
{
    if(registry->cout >= registry->capacity)
    {
        registry->capacity = registry->capacity == 0 ? 5 : registry->capacity * 2;
        registry->functions = realloc(registry->functions, registry->capacity * sizeof(Function));
    }

    registry->functions[registry->cout].name = name;
    registry->functions[registry->cout].func = func;
    registry->cout++;
}

FunctionPointer get_function(FunctionRegistry *registry, const char *name)
{
    if(registry == NULL || StringLen(name) == 0 )
    {
        ErrorObject *error_object =  create_error("Null registry or name of function", -1, "You have to give created Registry and registered function");
        throw_error(error_object);
    }

    for(size_t i = 0; i < registry->cout; i++)
    {
        if(registry->functions[i].name == name)
        {
            return registry->functions[i].func;
        }
    }

    ErrorObject *error_object =  create_error("Function Not Found", -1, "function with that name was not found!");
    throw_error(error_object);
}

void call_function(const FunctionRegistry *registry, const char *name)
{
    if(registry == NULL || StringLen(name) == 0)
    {
        ErrorObject *error_object =  create_error("Null registry or name of function", -1, "You have to give created Registry and registered function");
        throw_error(error_object);
    }

    FunctionPointer fp = get_function(registry, name);
    fp();
}