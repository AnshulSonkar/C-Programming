#include <stdio.h>

int main() {
    int arr[] = {12, 45, 23, 67, 89};
    int n = 5, key = 67;
    int found = -1;

    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            found = i;
            break;
        }
    }

    if(found != -1)
        printf("Found at index %d", found);
    else
        printf("Not Found");

    return 0;
}