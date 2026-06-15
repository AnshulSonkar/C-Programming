#include <stdio.h>

int firstOccurrence(int arr[], int n, int key) {
    int low = 0, high = n - 1, ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            ans = mid;
            high = mid - 1;
        }
        else if (key < arr[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return ans;
}

int lastOccurrence(int arr[], int n, int key) {
    int low = 0, high = n - 1, ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            ans = mid;
            low = mid + 1;
        }
        else if (key < arr[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {

    int arr[] = {1, 2, 2, 2, 2, 3, 4};
    int n = 7;
    int key = 2;

    int first = firstOccurrence(arr, n, key);
    int last = lastOccurrence(arr, n, key);

    printf("Count = %d", last - first + 1);

    return 0;
}