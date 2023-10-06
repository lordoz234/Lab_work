#include <stdio.h>
#include <stdlib.h>

int sort(int array[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (array[j+1] < array[j]) {
                int c = array[j + 1];
                array[j+1] = array[j];
                array[j] = c;
            }
        }
    }
    return array;
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
