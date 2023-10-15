#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
int _printf(const char *format, ...);
#endif

/**
* _printf - Custom printf function
* @format: A character string containing format specifiers
* @...: Additional arguments corresponding to format specifiers
*
* Return: The number of characters printed (excluding the null byte)
*/
int _printf(const char *format, ...)
{
	
	va_list args;
	int printed_chars = 0;
	va_start(args, format);

	while (*format)
{
	
	if (*format != &#39;%&#39;)

		{

			write(1, format, 1);
			printed_chars++;
		}
	
	else
		
		{
			
			format++;
			if (*format == &#39;c&#39;)
		{
			
			char c = va_arg(args, int);
			write(1, &amp;c, 1);
			printed_chars++;
		}
	else if (*format == &#39;s&#39;)
		{
			char *str = va_arg(args, char *);
			while (*str)
		{
			write(1, str, 1);
			printed_chars++;
			str++;
		}

			}
	else if (*format == &#39;%&#39;)
		{
			write(1, &quot;%&quot;, 1);
			printed_chars++;
		}
	}

		format++;
	}

		va_end(args);
		return printed_chars;
}
