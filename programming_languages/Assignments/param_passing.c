#include <stdio.h>
void pass_by_value(int x);
void pass_by_reference(int *x);

int main()
{
	int a = 10;
	int b = 20;

	printf("Original value of a: %d\n", a);
	printf("Original value of b: %d\n", b);

	pass_by_value(a);
	printf("Value of a after pass_by_value: %d\n", a);

	pass_by_reference(&b);
	printf("Value of b after pass_by_reference: %d\n", b);

	return 0;
}
void pass_by_value(int x) {
	x = 50;
	printf("Value inside pass_by_value: %d\n", x);
}
void pass_by_reference(int *x) {
	*x = 100;
	printf("Value inside pass_by_reference: %d\n", *x);
}
