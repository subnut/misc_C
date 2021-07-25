#include <stdio.h>
enum bool {false, true};
enum Month {
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December,
};

void
check(enum bool *bool)
{
	if (*bool) puts("yes");
	else       puts("no");
	printf("%d\n", *bool);
}

int
main(void)
{
	static enum bool bool;
	/* printf("%d\n", January); */

	/* bool = True; */
	/* check(&bool); */

	bool = false;
	check(&bool);
	bool++;
	check(&bool);
	bool++;
	check(&bool);

	return 0;
}
