#include <stdio.h>
#include <time.h>

void main(){
    int mode;
    printf("What mode would you like?(1 or 2)\n");
    scanf("%d", &mode);

    if (mode == 1){ // mode 1
        srand(500);
        int num = rand() % 1001;
        int guess;
        int k = 0;

        printf("%d", num);

        printf("Guess a number(0..1000): ");
        scanf("%d", &guess);

        while (k==0){
            if (guess == num){
                printf("You did it! Its %d", num);
                k++;
            }
            else if (guess > num){
                printf("Guess lower!");
                scanf("%d", &guess);
            }
            else if (guess < num){
                printf("Guess higher!");
                scanf("%d", &guess);
            }
        }

    }

    if (mode == 2){ // mode 2
        srand(0);

    }
}
