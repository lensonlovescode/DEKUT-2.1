#include <stdio.h>

int main()
{
	int i;
	int array[] = {10, 20, 30, 40, 50};
	int length = sizeof(array) / sizeof(array[0]);
	
	printf("First element: %d\n", array[0]);
	printf("Second element: %d\n", array[1]);

	array[2] = 35;
	printf("Modified third element: %d\n", array[2]);

	printf("All elements in the array:\n");

	for (i = 0; i < length; i++)
	{
		printf("Element at index %d: %d\n", i, array[i]);
	}

	return 0;
}
