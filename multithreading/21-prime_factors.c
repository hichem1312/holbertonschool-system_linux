#include "multithreading.h"

/**
 * prime_factors - function that factorizes number into a list of prime factor
 * @s: a string representation of the number to factorize.
 * Return: list_t
 **/
list_t *prime_factors(char const *s)
{
	unsigned long x = strtoul(s, NULL, 10), *var, y = 2;
	list_t *list = malloc(sizeof(list_t));

	list_init(list);
	while (y * y <= x)
	{
		while (x % y == 0)
		{
			var = malloc(sizeof(unsigned long));
			*var = y;
			list_add(list, (void *)var);
			x /= y;
		}

		y += 1 + (y != 2);
	}

	if (x >= 2)
	{
		var = malloc(sizeof(unsigned long));
		*var = x;
		list_add(list, (void *)var);
	}
	return (list);
}
