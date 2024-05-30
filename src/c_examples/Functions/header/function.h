#ifndef FUNCTIONS
#define FUNCTIONS

#include <stdio.h>
#include <stdlib.h>


typedef void (*FunctionPointer)();

typedef struct
{
    const char *name;
    FunctionPointer func;    
} Function;

typedef struct
{
    Function *functions;
    size_t cout;
    size_t capacity;
} FunctionRegistry;

void init_function_registry(FunctionRegistry *registry);
void register_function(FunctionRegistry *registry, const char* name, FunctionPointer *func);
FunctionPointer get_function(FunctionRegistry *registry, const char *name);
void call_function(const FunctionRegistry *registry, const char *name);


#endif