#include <stdio.h>
#include <stdlib.h>

//-----------------ПУЗЫРЕК---------------------------------------------------
// void sort(int arr[], int n) {
//     for (int i = 0; i<n; ++i){
//         for (int j = 0; j<n; ++j) {
//             if (arr[i] <= arr[j]) {
//                 int c;
//                 c = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = c;

//             }
//         }

//     }
//     return arr;
// }
// int main() {
//     int n;
//     scanf("%d", &n);
//     int array[n];
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &array[i]);
//     }
//     sort(array, n);
//     for (int i = 0; i < n; i++) {
//         printf("%d ", array[i]);
//     }
//     return 0;
// }
//--------------------------------------------------------------------

//-------------------БЫСТРАЯ-------------------------------------------------------
// void recurs(int array[], int first, int last)
// {

//     int l = first;
//     int r = last;
//     int pivot = array[(first + last) / 2];
//     if (first > last)
//         return;

//     while (l <= r)
//     {
//         while (array[l] < pivot)
//             l++;
//         while (array[r] > pivot)
//             r--;
//         if (l <= r)
//         {
//             int smth = array[l];
//             array[l] = array[r];
//             array[r] = smth;
//             l++;
//             r--;
//         }
//     }
//     recurs(array, first, r);
//     recurs(array, l, last);
// }

// int main() {
//     int n;
//     scanf("%d", &n);
//     int array[n];
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &array[i]);
//     }
//     recurs(array, 0, n-1);
//     for (int i = 0; i < n; i++) {
//         printf("%d ", array[i]);
//     }
//     return 0;
// }

//--------------------------------------------------------------------------
