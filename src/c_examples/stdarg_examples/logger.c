#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void print(char *text, ...);

int main(void)
{
    print("This is list of numbers: %d %f %d", 23, 65.3, 32);
}

void print(char *text, ...)
{
    va_list args;
    int num_arg = strlen(text);

    va_start(args, num_arg);
    for (int i = 0; i < num_arg; i++)
    {
        if (text[i] == '%')
        {
            i++;
            switch (text[i])
            {
            case 'd':
                printf("%d", va_arg(args, int));
                break;
            case 'f':
                printf("%f", va_arg(args, double));
                break;
            default:
                putchar(text[i]);
                break;
            }
        }
        else
        {
            putchar(text[i]);
        }
    }

    va_end(args);
}