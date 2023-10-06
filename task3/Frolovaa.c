#include <stdio.h>
#include <stdlib.h>

int ind;
int min;
int c;

void sort(int arr[], int n) {
    for (int i = 0; i<n; i++) {
        int min = arr[i];
        ind = i;
        for (int j = i+1; j < n; ++j){
            if (arr[j] < min){
                min = arr[j];
                ind = j;
            }
        }
        c = arr[i];
        arr[i] = arr[ind];
        arr[ind] = c;
    }
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