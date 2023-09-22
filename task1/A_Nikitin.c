#include <stdio.h>
#include <math.h>
int main(){
    int x1, y1, x2, y2;
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    int x3, y3;
    x3 = abs(x1 - x2);
    y3 = abs(y1 - y2);
    if ((x1 > 8) || (x2 > 8) || (y1 > 8)|| (y2 > 8)){
        printf("Input Error\n");
    } else {

        if ((abs(x1 - x2) <= 1 ) && (abs(y1 - y2) <= 1)){
            printf("King +\n");
            }
        else {
        printf("King -\n");
        }
        if ((x1 == x2) || (y1 == y2)) {
            printf("Rook +\n");
        } else {
        printf("Rook -\n");
        }
        if (x3 == y3) {
            printf("Elephant +\n");

        }else {
            printf("Elephant -\n");
        }
        if (((x1 == x2) || (y1 == y2)) || (x3 == y3))  {
            printf("Queen +\n");
        }else {
        printf("Queen -\n");
        }
        if (((x3 == 2) && (y3 == 1)) || ((y3 == 2) && (x3 == 1))) {
            printf("Horse +\n");

        }else {
        printf("Horse -\n");
        }}
        return 0;

}
