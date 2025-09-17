#include <stdio.h>

int binarySearch(int arr[], int low, int high, int item) {
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == item) {
        return mid;
    }

    if (item < arr[mid]) {
        return binarySearch(arr, low, mid - 1, item);
    } else {
        return binarySearch(arr, mid + 1, high, item);
    }
}

int main() {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int item, n, result;

    n = sizeof(arr) / sizeof(arr[0]);

    printf("Enter the element you want to search: ");
    scanf("%d", &item);

    result = binarySearch(arr, 0, n - 1, item);

    if (result != -1) {
        printf("%d found at index %d (position %d)\n", item, result, result + 1);
    } else {
        printf("%d not found\n", item);
    }

    return 0;
}
