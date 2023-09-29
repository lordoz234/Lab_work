#include <stdio.h>
#include <time.h>

int f_rand(int a, int b){
    srand(time(NULL));
    int guess = rand() % ((b - a) + 1) + a;
    return guess;

}

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

        //printf("%d", num);

        printf("Guess a number(0..1000): ");
        scanf("%d", &guess);

        while (k==0){
            if (guess == num){
                printf("You did it! Its %d \n", num);
                k++;
                counter++;
            }
            else if (guess > num){
                printf("Guess lower!");
                counter++;
                scanf("%d", &guess);
            }
            else if (guess < num){
                printf("Guess higher!");
                counter++;
                scanf("%d", &guess);
            }
        }
        printf("You number of guesses is %d", counter);

    }

    if (mode == 2){ // mode 2
        printf("Mode2");
        srand(0);
        int num;
        int left = 0;
        int right = 1000;
        char ch;
        printf("Pick a number(0..1000): ");
        scanf("%d", &num);
        scanf("%c", &ch);
        //printf("%d\n", f_rand(left, right));

        if (ch == '='){
            printf("nice!");
        }
        else if(ch == '>'){
            printf("so its bigger");
        }
        else if(ch == '<'){
                printf("so its smaller");
        }
    }

    if (mode == 3) {
        char x;
        scanf("%c", &x);
    }
}
