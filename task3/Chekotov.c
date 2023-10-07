# include <stdio.h>

void sort(int a[], int n) {
    for (int i = 0; i < n; ++i){
        int j = i - 1;
        int x = a[i];
        while ((j >= 0) && (a[j] > x)){
            int x = a[j + 1];
            a[j + 1] = a[j];
            a[j] = x;
            --j;
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
