#include <stdio.h>
#include <stdlib.h>

int sort(int arr[], int n) {
    int z;
    for (int k = 0; k < n; k++)
        for (int i = k; i > 0 && arr[i - 1] > arr[i]; i--) {
            z = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = z;
        }
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
        printf("%d ", array[i]);
    }
    return 0;
}