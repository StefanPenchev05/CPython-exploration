#include <stdio.h>
#include <stdarg.h>

int max(int number_args, ...);

int main(void)
{
    int maxDigit = max(4, 4, 8, 23, 12);
    printf("The biggest number is: %d", maxDigit);
}

int max(int number_args, ...)
{
    va_list args;
    va_start(args, number_args);

    int max = 0;
    for (int i = 0; i < number_args; i++)
    {
        int x = va_arg(args, int);
        if (x > max)
            max = x;
    }

    va_end(args);

    return max;
}