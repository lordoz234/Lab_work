#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Russian");
    printf("Введите номер режима 1 или 2\n");
    int p;
    scanf("%d", &p);
    while (p!=1 && p!=2){
        printf("Hет режима с таким номером, введите ещё раз\n");
        scanf("%d",&p);
        }

    if (p==1){                  //первый режим
        printf("Введите предпологаемое число\n");
        int m,x;
        int k = 0;
        scanf("%d",&m);
        srand(time(NULL));
        x = abs(rand())%1000;
        while (m!=x){
            if (m<x){
                printf("Загаданное число больше\n");
                scanf("%d",&m);
                k++;
            }
            if (m>x){
                printf("Загаданное число меньше\n");
                scanf("%d",&m);
                k++;
            }
            if (m==x){
                printf("Угадали! Количество попыток:\n");
                printf("%d",k);
                break;
            }
        }
    }
    
    if (p==2){              //второй режим
        int left = 0;
        int right = 1000;
        int m = 500;
        int k = 0;
        printf("500: Больше(>), меньше(<) или равно(=)\n");
        char t;
        scanf("%c",&t);
        while (t != '='){
            scanf("%c",&t);
            if (t=='<'){
                right = m;
                m = (right + left)/2;
                printf("%d\n",m);
                k+=1;
            }
            if (t=='>'){
                left = m;
                m = (right + left)/2;
                printf("%d\n",m);
                k+=1;
            }
            if (t=='='){
                printf("Угадал. количество попыток:\n");
                printf("%d",k);
            }
            if (right == left){
                break;
            }
        }
    }
}