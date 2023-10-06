#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){
    srand(time(NULL));
    int rezhim;
    printf("Select the mode 1 or 2 ");
    scanf("%d",&rezhim);
    if(rezhim==1){
        int x,y,cnt;

        cnt=0;

        x = rand()%1000;
        printf("Computer guessed a number %d \n",x);



        do{
            printf("Enter the number \n");
        scanf("%d",&y);
        if (y<x){
                printf("the number is greater\n");

                cnt ++;
            }
            else if (y>x){
                printf("The number is less\n");
                cnt++;
            }
            else{
                cnt++;
                printf("That's right,number = %d\n",x);
                printf("Attempts %d",cnt);

            }

        }
        while(x!=y);
    }



        if (rezhim==2){
            int lv=0;
            int prv=1000;
            int count=0;
            int cntr=0;
            char Symbol;


            printf("Guess the number\n");
            while((prv-lv)>=1){
                int center = (lv+prv)/2;
                cntr=center;

                printf("Computer think that your number %d\n",cntr);
                printf("More or less?/</>/=\n");
                scanf("%c",&Symbol);
                if (Symbol == '>'){
                count++;
                lv=center;


                }
                else if (Symbol== '<'){
                    printf("The number is less\n");
                    count++;
                    prv=center;
                }
                else if (Symbol == '='){
                    count++;
                    printf("The computer guessed the number\n ");
                    printf("Attempts %d\n",count);
                    break;


                }


            }
        }
    }

