#include <stdio.h>

struct nested {
	int c;
	int d;
};

struct data {
	int a;
	int b;
	struct nested nested;
};

void
toggle_a(struct data *data)
{
	data->a++;
	data->a %= 2;
}

void
toggle_c(struct data *data)
{
	data->nested.c++;
	data->nested.c %= 2;
}

int
main(void)
{
	struct data data;
	struct data *ptr;

	/* data.a = 0; */
	/* data.b = 0; */
	/* printf("a: %i\nb: %i\n", data.a, data.b); */
	/* toggle_a(&data); */
	/* printf("a: %i\nb: %i\n", data.a, data.b); */

	/* ptr = &data; */
	/* ptr->a = 0; */
	/* ptr->b = 0; */
	/* printf("a: %i\nb: %i\n", ptr->a, ptr->b); */
	/* toggle_a(ptr); */
	/* printf("a: %i\nb: %i\n", ptr->a, ptr->b); */

	/* data.nested.c = 0; */
	/* printf("c: %i\n", data.nested.c); */
	/* toggle_c(&data); */
	/* printf("c: %i\n", data.nested.c); */

	ptr = &data;
	ptr->nested.c = 0;
	printf("c: %i\n", data.nested.c);
	printf("c: %i\n", ptr->nested.c);
	toggle_c(ptr);
	printf("c: %i\n", data.nested.c);
	printf("c: %i\n", ptr->nested.c);
}
