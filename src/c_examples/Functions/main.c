#include "./function.c"
#include <stdarg.h>

void greet()
{
    printf("Hello, World!");
}

int main(void)
{
    FunctionRegistry registry;
    init_function_registry(&registry);

    register_function(&registry, "greet", &greet);

    call_function(&registry, "greet");
}