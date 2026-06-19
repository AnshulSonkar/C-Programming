// #include <stdio.h>
// #include <stdlib.h>

// int main() {

//     int *ptr;

//     ptr = (int *)malloc(5 * sizeof(int));

//     for(int i = 0; i < 5; i++) {
//         ptr[i] = i + 1;
//     }

//     for(int i = 0; i < 5; i++) {
//         printf("%d ", ptr[i]);
//     }

//     free(ptr);

//     return 0;
// } 


// User Input Array Using malloc()
#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;

    printf("Enter Size: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}