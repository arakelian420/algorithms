#include<stdio.h>

int binarySearch (int list[], int item, int len) {
    int lowestIndex = 0;
    int highestIndex = len;

    while (lowestIndex <= highestIndex) {
        int midIndex = (lowestIndex + highestIndex) / 2;
        int guess = list[midIndex];
        if (guess == item) {
            return midIndex;
        } else if (guess > item) {
            highestIndex = midIndex-1;
        } else if (guess < item) {
            lowestIndex = midIndex+1;
        }
    }
    return -1; // when number is not in the list
}

int main () {
    int mylist[] = {2,3,6,8,10,13,15};
    int len = sizeof(mylist) / sizeof(mylist[0]); // cuz every element have same size
    int number;
    scanf("%d", &number);
    printf("The index is: %d\n", binarySearch(mylist, number, len));
}
