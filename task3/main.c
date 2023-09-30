#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    const int* num1 = (const int*)a;
    const int* num2 = (const int*)b;

    return (*num1 - *num2);
}

int main() {
    int n;
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    qsort(array, n, sizeof(int), compare);
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}
