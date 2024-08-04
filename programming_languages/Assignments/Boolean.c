#include <stdio.h>

int main() {
	int a, b;

	printf("Enter the first number (a): ");
	scanf("%d", &a);

	printf("Enter the second number (b): ");
	scanf("%d", &b);

	if ((a > 0) && (b > 0)) {
		printf("Both a and b are positive numbers.\n");
	} else {
		printf("Either a or b is not a positive number.\n");
	}

	if ((a > 0) || (b > 0)) {
		printf("At least one of a or b is a positive number.\n");
	} else {
		printf("Neither a nor b is a positive number.\n");
	}

	if (!(a > 0)) {
		printf("a is not a positive number.\n");
	} else {
		printf("a is a positive number.\n");
	}

	return 0;
}

