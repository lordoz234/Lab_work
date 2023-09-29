#include <stdio.h>
#include <time.h>

void odin();
void second();

void main(){
    srand(time(NULL));
    int rej;
    printf("kakou` rejim vi hotite? 1 ili 2 ");
    scanf_s("%d", &rej);
    if (rej == 1){
        odin();
    }
    else {
        second();
    }
}

void odin(){
    int random = (rand() % 1000) + 1;
    int tr = 1;
    int k = 0;
    while (tr == 1){
        int x;
        printf("vvedite predpolojenie   ");
        scanf_s("%d", &x);
        if (x < random){
            printf("zagadannoe chislo bol'she\n");
            k += 1;
        }
        else if (x > random){
            printf("zagadannoe chislo men'she\n");
            k += 1;
        }
        else if (x == random){
            printf("vi ygadali\n chislo popitok: %d",k);
            tr = 0;
        }
    }
}

void second(){
    int x;
    int k = 0;
    char znak;
    int left = 0;
    int right = 1000;
    printf("zagadau`te chislo ot 1 do 1000  ");
    scanf_s("%d",&x);
    while (right - left >= 1){
        int mid=left+(right-left) / 2;
        printf("Moe predpolojenie: %d   ", mid);
        printf("\n");
        printf("vvedite znak >, <, = (vashe chislo ....)    ");
        scanf_s("%c", &znak);
        if (znak == '>'){
            left = mid;
            k += 1;
        }
        else if (znak == '<'){
            right = mid;
            k += 1;
        }
        else if (znak == '='){
            printf("vashe chislo: %d \n chislo popitok: %d", mid, k);
            right = 0;
        }
    }
}
