#include <stdio.h>
#include <math.h>
void main() {
    int x1, y1, x2, y2, k1 = 0, k2 = 0, k3 = 0;
    scanf_s("%d %d %d %d", &x1, &y1, &x2, &y2);
    if (abs(y1 - y2) <= 1 && abs(x2 - x1) <= 1) {
        printf("King    ");
        k1 = 1;
    }
    if ((abs(x1 - x2) == 1 && abs(y2 - y1) == 1) ||
        (abs(x1 - x2) == 2 && abs(y2 - y1) == 2) || 
        (abs(x1 - x2) == 3 && abs(y2 - y1) == 3) || 
        (abs(x1 - x2) == 4 && abs(y2 - y1) == 4) || 
        (abs(x1 - x2) == 5 && abs(y2 - y1) == 5) || 
        (abs(x1 - x2) == 6 && abs(y2 - y1) == 6) || 
        (abs(x1 - x2) == 7 && abs(y2 - y1) == 7)) {
        printf("Slon    ");
        k2 = 1;
    }
    if (x1 == x2 || y1 == y2) {
        printf("Lad`ya  ");
        k3 = 1;
    }
    if (k1==1 || k2==1 || k3==1) {
        printf("Ferz`   ");
    }
    if ((abs(y1 - y2) == 2 && abs(x2 - x1) == 1) || (abs(y1 - y2) == 1 && abs(x2 - x1) == 2)) {
        printf("Kon`    ");
    }
}