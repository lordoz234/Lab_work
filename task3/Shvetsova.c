#include <stdio.h>
#include <stdlib.h>
//-------------------БЫСТРАЯ-------------------------------------------------------
void sort(int array[], int first, int last)
{

    int l = first;
    int r = last;
    int pivot = array[(first + last) / 2];
    if (first > last)
        return;

    while (l <= r)
    {
        while (array[l] < pivot)
            l++;
        while (array[r] > pivot)
            r--;
        if (l <= r)
        {
            int smth = array[l];
            array[l] = array[r];
            array[r] = smth;
            l++;
            r--;
        }
    }
    sort(array, first, r);
    sort(array, l, last);
}

int main()
{
    int n;
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    sort(array, 0, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}