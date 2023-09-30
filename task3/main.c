#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    return;
}

int main() {
    int n;
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    sort(array, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i] + 1);
    }
    return 0;
}
