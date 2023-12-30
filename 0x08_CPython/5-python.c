#include <stdio.h>
#include <Python.h>

/**
 * print_python_int - a C function that prints Python integers
 * @p: pointer
 */
void print_python_int(PyObject *p)
{
	ssize_t i, x, v;
	unsigned long num = 0;

	setbuf(stdout, NULL);
	if (!PyLong_Check(p))
	{
		printf("Invalid Int Object\n");
		return;
	}
	x = ((PyVarObject *)p)->ob_size;
	v = x < 0;
	x = v ? -x : x;
	if (x > 3 || (x == 3 && ((PyLongObject *)p)->ob_digit[2] > 0xf))
	{
		printf("C unsigned long int overflow\n");
		return;
	}
	for (i = 0; i < x; i++)
	{
		int sh = PyLong_SHIFT * i;
		unsigned long sub =
			((unsigned long)((PyLongObject *)p)->ob_digit[i]) * (1UL << (sh));
		num += sub;
	}
	if (v)
		printf("-");
	printf("%lu\n", num);
}
