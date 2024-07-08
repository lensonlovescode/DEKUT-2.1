#include <stdio.h>
#include <stdlib.h>
#include "main.h"
int main()
{
	int i;
	int my_array[7];

	printf("Enter 7 array elements\n");
	for (i = 0; i < 7; i++)
	{
		scanf("%d", &my_array[i]);
	}

	selection_sort(my_array, 7);
	return (0);
}
