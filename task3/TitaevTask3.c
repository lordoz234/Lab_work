#include <stdio.h>
#include <stdlib.h>
#pragma warning(suppress : 4996)
void sort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int kol = 0;
        for (int j = 0; j < n - 1; j++) {
            if (arr[j + 1] < arr[j]) {
                int a = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = a;
                ++kol;
            }
        }
    }
    return;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
