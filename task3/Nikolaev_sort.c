#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n; ++i){
        int j = i - 1;
        int x = arr[i];
        while ((j >= 0) && (arr[j] > x)){
            int c = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = c;
            --j;
        }
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

