#include "main.h"
/**
 * _print_binary - prints binary num
 * @n: print char
 * @k: counter thru str
 * Return: void
 */
void _print_binary(int n, int *k)
{
	char a[1000];
	int i = 0;

	while (n)
	{
		if (n & 1)
			a[i] = (1 + '0');
		else
			a[i] = (0 + '0');
		n >>= 1;
		i++;
	}
	i--;
	while (i >= 0)
	{
		_putchar(a[i], k);
		i--;
	}
}
