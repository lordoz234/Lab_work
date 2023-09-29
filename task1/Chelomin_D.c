#include <stdio.h>
#include <math.h>
#include <locale.h>
int main(void){
    setlocale(LC_ALL, "Rus");
    int x1,y1,x2,y2;
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    if (x1<=8 && y1<=8 && x2<=8 && y2<=8){
        if  (x1 == x2  y1 == y2){
            printf("Ладья\n");}
        if (abs(x1 - x2) == abs(y1 - y2)){
            printf("Слон\n");}
        if (abs(x1-x2) <= 1 && abs(y1-y2) <= 1){
            printf("Король\n");}
        if (abs(x1-x2) <= 1 && abs(y1-y2) <= 1  x1 == x2  y1 == y2){
            printf("Ферзь\n");}
        if ((x1 - 1 == x2  x1 + 1 == x2) && (y1 - 2 == y2  y1 + 2 == y2)){
            printf("Конь\n");}
        if ((x1 - 2 == x2  x1 + 2 == x2) && (y1 - 1 == y2 || y1 + 1 == y2)){
            printf("Конь\n");}
    
    } else {
        printf("Неверно выбраны координаты");
    }
    return 0;}