#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function.
 * @format: Format string containing specifiers.
 * Return: Number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;   

    char *str;
    char c;

    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++; 
            if (*format == 'c')
            {
                c = va_arg(args, int); 
                write(1, &c, 1);
                count++;
            }
            else if (*format   
 == 's')
            {
                str = va_arg(args, char *);
                if (str == NULL)
                    str = "(null)";
                while (*str)
                {
                    write(1, str, 1);
                    str++;
                    count++;
                }
            }
            else if (*format == '%')
            {
                write(1, "%", 1);
                count++;
            }
        }
        else
        {
            write(1,   
 format, 1);
            count++;
        }
        format++;
    }

    va_end(args);
    return count;
}
