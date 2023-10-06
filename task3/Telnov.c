#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {            //sortirovka pyzirkom
    for (int i = 0; i < n; i++){
        int k = 0;
        for (int j = 0; j < n; j++){
            if (arr[j + 1] < arr[j]){
                int c = arr[j];
                arr[j]= arr[j + 1];
                arr[j + 1]=c;
                ++k;
            }
        }
        if (k == 0){
            break;
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
