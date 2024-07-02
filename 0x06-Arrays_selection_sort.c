#include "main.h"
#include <stdio.h>
int selection_sort(int arr[], int n)
{
	int i;
	int j;
	int temp;
	int min_idx;
	min_idx = 0;

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				min_idx = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;
	}
	
	for (i = 0; i < n; i++)
	{
		if (i != n)
		{
 			printf("%d, ", arr[i]);
		}
		else
		{
			printf("%d\n",arr[i]);
		}
	}
	return (0);	
}
