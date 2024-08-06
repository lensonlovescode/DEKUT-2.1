#include <stdio.h>
#include <stdlib.h>

void displayArray(int** array, int rows, int columns) {
	int i, j;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++) {
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
}

int** mergeArrays(int** array1, int rows1, int columns1, int** array2, int rows2) {
	int totalRows = rows1 + rows2;
	int** mergedArray = (int**)malloc(totalRows * sizeof(int*));
	int i, j;

	for (i = 0; i < totalRows; i++) {
		mergedArray[i] = (int*)malloc(columns1 * sizeof(int));
	}

	for (i = 0; i < rows1; i++) {
		for (j = 0; j < columns1; j++) {
			mergedArray[i][j] = array1[i][j];
		}
	}

	for (i = 0; i < rows2; i++) {
		for (j = 0; j < columns1; j++) {
			mergedArray[rows1 + i][j] = array2[i][j];
		}
	}

	return mergedArray;
}

int main() {
	int hardcodedArray[3][3] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	int rows1 = 3, columns1 = 3;
	int i, j;
	int* hardcodedArrayPtrs[3];
	int rows2, columns2;
	int** userInputArray;
	int** mergedArray;

	hardcodedArrayPtrs[0] = hardcodedArray[0];
	hardcodedArrayPtrs[1] = hardcodedArray[1];
	hardcodedArrayPtrs[2] = hardcodedArray[2];

	printf("Hardcoded Array:\n");
	displayArray(hardcodedArrayPtrs, rows1, columns1);

	printf("\nEnter the number of rows for the array: ");
	scanf("%d", &rows2);
	printf("Enter the number of columns for the array: ");
	scanf("%d", &columns2);

	userInputArray = (int**)malloc(rows2 * sizeof(int*));
	for (i = 0; i < rows2; i++) {
		userInputArray[i] = (int*)malloc(columns2 * sizeof(int));
	}

	printf("Enter the elements of the array:\n");
	for (i = 0; i < rows2; i++) {
		for (j = 0; j < columns2; j++) {
			scanf("%d", &userInputArray[i][j]);
		}
	}

	printf("\nUser Input Array:\n");
	displayArray(userInputArray, rows2, columns2);

	mergedArray = mergeArrays(hardcodedArrayPtrs, rows1, columns1, userInputArray, rows2);

	printf("\nMerged Array:\n");
	displayArray(mergedArray, rows1 + rows2, columns1);

	for (i = 0; i < rows2; i++) {
		free(userInputArray[i]);
	}
	free(userInputArray);

	for (i = 0; i < rows1 + rows2; i++) {
		free(mergedArray[i]);
	}
	free(mergedArray);

	return 0;
}

