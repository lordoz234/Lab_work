#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<math.h>
int f1(void){
    srand(0);
    int t;
    t=rand () % 1001;
    printf ("Я загадал число. Введите свой вариант:");
    int c;
    int k=0;
    scanf ("%d", &c);
    while (t!=c) {
        if (t>c) {
            printf ("Неверно, заданное число больше введенного.\n");
            k++;
        }
        if (t<c) {
            printf ("Неверно, загаданное число меньше введенного.\n");
            k++;
        }
        scanf ("%d",&c);
    }
    if (t==c){
            k++;
            printf("Вы отгадали. Поздравляю!\n");
            printf("Количество попыток:%d", k);
            }
    return 0;
}
int f2(void){
   int left = 0;
   int right = 1000;
   char p;
   int u=0;
   int mid;
   printf ("Загадайте число от 0 до 1000.\n");
   while (right - left >=1){
        double b = (left + right)/2;
        mid = (int) b;
        printf("Я думаю, что загаданное число = %d.\n Введите >, < или =.\n", mid);
        scanf(" %c", &p);
        if (p=='<'){
            right = mid;
            ++u;
        } 
        if (p=='>'){
            left = mid;
            ++u;
        }
        if (p=='='){
            ++u;
            printf ("Ура, я молодец!\n");
            printf ("Количество попыток =%d.",u);
            break;
        }
   }
   return 0;
}
int main(){
    setlocale  (LC_ALL, "Russian");
    printf ("Выберите режим: 1 или 2.\n");
    int x;
    scanf("%d", &x);
    if (x==1) {
        f1();
    }
    if (x==2) {
        f2();
    }
    return 0;
}