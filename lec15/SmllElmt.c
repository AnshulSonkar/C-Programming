#include <stdio.h>

int main() {
    int arr[] = {45, 12, 89, 3, 67};
    int min = arr[0];

    for(int i = 1; i < 5; i++) {
        if(arr[i] < min)
            min = arr[i];
    }

    printf("Minimum = %d", min);

    return 0;
}