#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int findSmallest (const int array[], int len) {
    int smallest = array[0];
    int smallestIndex = 0;
    for (int i = 1; i < len; i++) {
        if (array[i] < smallest) {
            smallest = array[i];
            smallestIndex = i;
        }
    }
    return smallestIndex;
}

int *selectionSort (int array[], int len) {
    int *newArray = (int *)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        int smallest = findSmallest(array, len);
        newArray[i] = array[smallest];
        array[smallest] = INT_MAX;
    }
    return newArray;
}

int main() {
    int size = 0;
    int *array = NULL;
    int val;
    printf("Enter int numbers to be sorted:\n");

    while (scanf("%d", &val) == 1) {
        array = realloc(array, (size+1) * sizeof(int));
        array[size++] = val;
    }

    int len = size;
    int *sortedArray = selectionSort(array, len);
    printf("\nSorted array:\n");
    for (int i = 0; i < len; i++) {
        printf("%d\n", sortedArray[i]);
    }
    free(array);
    return 0;
}
