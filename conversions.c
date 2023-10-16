#include "main.h"

/**
 * convert_sbase - Converts long to base then stores
 * @output: buffer_t that has char array
 * @num: long to be converted
 * @base: str that has base to convert to
 * @flags: modifiers
 * @wid: modifier
 * @acc: modifier
 * Return: num of bytes stored to the buffer
 */
unsigned int convert_sbase(buffer_t *output, long int num, char *base, unsigned char flags, int wid, int acc)
{
	int size;
	char digi, pad = '0';
	unsigned int ret = 1;

	for (size = 0; *(base + size);)
		size++;

	if (num >= size || num <= -size)
		ret += convert_sbase(output, num / size, base,
				flags, wid - 1, acc - 1);

	else
	{
		for (; acc > 1; acc--, wid--)
			ret += _memcpy(output, &pad, 1);

		if (NEG_FLAG == 0)
		{
			pad = (ZERO_FLAG == 1) ? '0' : ' ';
			for (; wid > 1; wid--)
				ret += _memcpy(output, &pad, 1);
		}
	}

	digi = base[(num < 0 ? -1 : 1) * (num % size)];
	_memcpy(output, &digi, 1);

	return (ret);
}

/**
 * convert_ubase - Con unsigned long to an inputted base
 * @output: buffer_t struct that has char array
 * @num: unsigned long conversion
 * @base: str that has the base to convert to
 * @flags: modifiers
 * @wid: wid modifier
 * @acc: modifier
 *
 * Return: num of bytes stored to the buffer
 */
unsigned int convert_ubase(buffer_t *output, unsigned long int num, char *base, unsigned char flags, int wid, int acc)
{
	unsigned int size, ret = 1;
	char digi, pad = '0', *lead = "0x";

	for (size = 0; *(base + size);)
		size++;

	if (num >= size)
		ret += convert_ubase(output, num / size, base,
				flags, wid - 1, acc - 1);

	else
	{
		if (((flags >> 5) & 1) == 1)
		{
			wid -= 2;
			accu -= 2;
		}
		for (; acc > 1; acc--, wid--)
			ret += _memcpy(output, &pad, 1);

		if (NEG_FLAG == 0)
		{
			pad = (ZERO_FLAG == 1) ? '0' : ' ';
			for (; wid > 1; wid--)
				ret += _memcpy(output, &pad, 1);
		}
		if (((flags >> 5) & 1) == 1)
			ret += _memcpy(output, lead, 2);
	}

	digi = base[(num % size)];
	_memcpy(output, &digi, 1);

	return (ret);
}
