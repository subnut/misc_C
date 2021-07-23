#include <stdio.h>
#include <string.h>

void
shift(char **array, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%s <- %s\n", array[i], array[i+1]);
		memmove(array[i], array[i+1], 3);
	}
}

int
main(void)
{
	char *array[] = {"00","01","02","03","04","05","06","07"};
	char **ptr = array;

	for (int i = 0; i < (sizeof(array)/sizeof(array[0])); i++)
		printf("%i: %s\n", i, array[i]);
	puts("---");
	shift(ptr, sizeof(array)/sizeof(array[0]));
	puts("---");
	for (int i = 0; i < (sizeof(array)/sizeof(array[0])); i++)
		printf("%i: %s\n", i, array[i]);
}
