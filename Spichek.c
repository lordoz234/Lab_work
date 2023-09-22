#include <stdio.h>
#include <math.h>
int main(){
    int x1,y1,x2,y2;
    printf("Input coordinates of first point\n");
    scanf("%d %d",&x1,&y1);
    printf("Input coordinates of second point\n");
    scanf("%d %d",&x2,&y2);
    if (x1<1 || x1>8 || x2<1 || x2>8 || y1<1 || y1>8 || y2<1 || y2>8){
        printf("Incorrect input");
    }
    else{
        //Êîðîëü
        if (abs(x1-x2)<2 && abs(y1-y2)<2){
            printf("Korol mojet popast\n");
        }
        else{
            printf("Korol ne mojet popast\n");
        }

        //Ëàäüÿ
        if ((x1==x2) || (y1==y2)){
            printf("Ladja mojet popast\n");
        }
        else{
            printf("Ladja ne mojet popast\n");
        }

        //Êîíü
        if (((abs(x1-x2)==1) && (abs(y1-y2)==2)) || ((abs(x1-x2)==2) && (abs(y1-y2)==1))){
            printf("Kon mojet popast\n");
        }
        else{
            printf("Kon ne mojet popast\n");
        }

        //Ñëîí
        if (abs(x1-x2)==abs(y1-y2)){
            printf("Slon mojet popast\n");
        }
        else{
            printf("Slon ne mojet popast\n");
        }

        //Ôåðçü
        if ((abs(x1-x2)==abs(y1-y2)) || (x1==x2) || (y1==y2)){
            printf("Ferz mojet popast\n");
        }
        else{
            printf("Ferz ne mojet popast\n");
        }
    }
}
