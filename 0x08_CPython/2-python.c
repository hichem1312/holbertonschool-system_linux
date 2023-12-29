#include <Python.h>

/**
 * print_python_bytes - C functions that print info about Python bytes objects
 * @p: Python object
 */
void print_python_bytes(PyObject *p)
{
	int i;
	Py_ssize_t size, byte;
	char *s = NULL;

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}
	
	size = ((PyVarObject *)(p))->ob_size;
	printf("  size: %li\n", size);

	s = ((PyBytesObject *)(p))->ob_sval;
	printf("  trying string: %s\n", s);

	byte = (size + 1 >= 10) ? 10 : size + 1;
	printf("  first %li bytes:", byte);
	for (i = 0; i < byte; i++)
		printf(" %02x", (unsigned char)(s[i]));
	putchar('\n');
}
/**
 * print_python_list - C functions that print info using macros
 * @p: Python object
 */
void print_python_list(PyObject *p)
{
	PyObject *item;
	Py_ssize_t size = PyList_Size(p);
	Py_ssize_t i;

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %lu\n", size);
	printf("[*] Allocated = %lu\n", ((PyListObject *)p)->allocated);

	for (i = 0; i < size; i++)
	{
		item = ((PyListObject *)(p))->ob_item[i];
		printf("Element %ld: %s\n", i, item->ob_type->tp_name);
		if (PyBytes_Check(item))
			print_python_bytes(item);
	}
}
