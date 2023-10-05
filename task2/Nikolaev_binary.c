#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void main(){
    int mode;
    printf("What mode would you like?(1 or 2)\n");
    scanf("%d", &mode);

    if (mode == 1){ // mode 1
        srand(time(NULL));
        int num = rand() % 1001;
        int guess;
        int k = 0;
        int counter = 0;

        printf("Guess a number(0..1000): ");
        scanf("%d", &guess);

        while (k==0){
            if (guess == num){
                printf("You did it! Its %d \n", num);
                k++;
                counter++;
            }
            else if (guess > num){
                printf("Guess lower! ");
                counter++;
                scanf("%d", &guess);
            }
            else if (guess < num){
                printf("Guess higher! ");
                counter++;
                scanf("%d", &guess);
            }
        }
        printf("You number of guesses is %d.", counter);
    }
    
    if (mode == 2){ // mode 2
        int num;
        int left = 0;
        int right = 1000;
        int mid;
        char ch;
        int tries = 0;

        printf("Pick a number(0..1000): ");
        scanf("%d", &num);
        
        while (right - left >= 1){
            mid = (left + right) / 2;
            printf("%d ", mid);
            scanf(" %c", &ch);

            if (ch == '>'){
                left = mid;
                tries++;
            }

            if (ch == '<'){
                right = mid;
                tries++;
            }

            if (ch == '='){
                printf("Nice!\nThe number of tries is %d.", tries);
                return;
            }
            
        }
    }
}
