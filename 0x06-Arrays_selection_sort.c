#include <stdio.h>
void selection_sort(int arr[], int n)
{
	int i;
	int j;
	int temp;
	int min_idx;

	for (i = 0; i < n-1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min_idx])
			{
				min_idx = j;
			}
			if (min_idx != i)
			{
				temp = arr[min_idx];
				arr[min_idx] = arr[i];
				arr[i] = temp;
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		if (i != 6)
		{
                        printf("%d, ", arr[i]);
                }
                else
                {
                        printf("%d\n",arr[i]);
                }
	}
}
