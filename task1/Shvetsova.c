#include <stdio.h>
#include <math.h>

void main()
{
    char v1, v2;
    int p1, p2, intv1, intv2;
    scanf(" %c %c", &v1, &v2);
    scanf(" %d %d", &p1, &p2);
    intv1 = (int)v1;
    intv2 = (int)v2;
    if ((p2 > 0 && p2 < 9) && (p1 > 0 && p1 < 9) && (intv1 > 96 && intv1 < 105) && (intv2 > 96 && intv2 < 105))
    {

        if (((v1 == v2) && (p1 != p2)) || ((p1 == p2) && (v1 != v2)))
        {
            printf("Rook, Queen");
            return;
        }
        if ((abs(intv2 - intv1) == 1 && abs(p2 - p1) <= 1) || (abs(p2 - p1) == 1) && abs(intv2 - intv1) <= 1)
        {
            if (p2 != p1 && intv1 != intv2)
            {
                printf("King, Elephant, Queen");
                return;
            }
            printf("King, Qeen");
            return;
        }
        if ((abs(p2 - p1) == 2 && abs(intv2 - intv1) == 1) || (abs(intv2 - intv1) == 2 && abs(p2 - p1) == 1))
        {
            printf("Horse");
            return;
        }
        if (abs(p2 - p1) == abs(intv2 - intv1))
        {
            printf("Elephant, Queen");
            return;
        }
        else
        {
            printf("none");
            return;
        }
    }
    else
    {
        printf("wrong value");
    }
}