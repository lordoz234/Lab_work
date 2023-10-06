#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    int temp, ind;
    for (int i=1; i<n; i++){
            temp=arr[i];
            ind=i-1;
            while (ind >= 0 && arr[ind] > temp){
                arr[ind+1]=arr[ind];
                ind--;
            }
            arr[ind+1]=temp;
    }
}


int main() {
    int n;
    printf("Input long of array\n");
    scanf("%d", &n);
    int array[n];
    printf("Input elements of array\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    sort(array, n);
    printf("Sorted array\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}
