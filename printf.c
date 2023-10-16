#include "main.h"

/**
 * to_printf - custom printf
 * @format: char str
 * Return: 1 if printable, else 0
 */
void write_buffer(char buffer[], int *buff_ind);
int get_flag(const char *format, int *i);
int write_width(const char *format, int *i, va_list list);
int get_acc(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
int handle_width(const char *format, int *i, va_list list, char buffer[], int flags, int width, int accuracy, int size);
int to_printf(const char *format, ...)
{
	int i, printed = 0;
	int buff_ind = 0;
	int flags, width, accuracy, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
			{
				write_buffer(buffer, &buff_ind);
				printed_chars += BUFF_SIZE;
		}
		else
		{
			printed_chars++;
		}
	}
	else
	{
		write_bufer(bufer, &buff_ind);
		i++;
	}
	}
			write_buffer(buffer, &buff_ind);
			va_end(list);
			return printed_char;
}

void write_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
