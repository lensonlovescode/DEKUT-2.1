#include "main.h"
#include <stdio.h>
int bubble_sort(int array[], int n)
{
	int i;
	int j;
	int temp;

	for(i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < 8; i++)
	{
		if (i != 7)
		{
			printf("%d, ", array[i]);
		}
		else
		{
			printf("%d\n",array[i]);
		}
	}

	return (0);
}
