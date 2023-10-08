#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1 - i;++j) {
            if (arr[j + 1] < arr[j]) {
                int c = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = c;
            }
        }

    }
    return;
}

int main() {
    int n;
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &array[i]);
    }
    sort(array, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}
