// RECURSION
// #include <stdio.h>

// void fun(int n) {

//     if(n == 0)
//         return;

//     printf("%d ", n);

//     fun(n - 1);
// }

// int main() {

//     fun(5);

//     return 0;
// } 


// 2nd Code
// #include <stdio.h>

// void print(int n) {

//     if(n == 0)
//         return;

//     print(n - 1);

//     printf("%d ", n);
// }

// int main() {

//     print(5);

//     return 0;
// } 


#include <stdio.h>

void print(int n) {

    if(n == 0)
        return;

    printf("%d ", n);

    print(n - 1);
}

int main() {

    print(5);

    return 0;
}