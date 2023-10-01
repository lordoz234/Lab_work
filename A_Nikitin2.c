#include <stdio.h>
#include <time.h>
int main() {
    srand(0);
    int left = 0;
    int right = 1000;
    int mode;
    int k = 1; // number of operations
    int x; // random number(1) or users number(2)
    printf("Choose mode: ");
    scanf("%d", &mode);
    if (mode == 1) {
        x = rand() % 1000;
        int add_num;
        scanf("%d", &add_num);
        while (add_num != x) {
            k++;
            if (add_num > x) {
                printf("The hidden number is less\n");
            }
            else if (add_num < x) {
                printf("The hidden number is greater\n");

            }
            scanf("%d", &add_num);
        }
        printf("You guessed the number\n");
        printf("Number of operations %d\n", k);
    }
    else if (mode == 2) {
        x = 500;
        int status;
        printf("If your number is greater, print 1\n");
        printf("If your number is less, print 2\n");
        printf("If computer guessed your number, print 3\n");
        printf("Is your number is %d ?\n", x);
        scanf("%d", &status);
        while (status != 3) {
            k++;
            if (status == 1) {
                left = x;
                x = (left + right) / 2;
            }
            else if (status == 2) {
                right = x;
                x = (left + right) / 2;
            }
            printf("Is your number is %d ?\n", x);
            scanf("%d", &status);
        }
        printf("I guessed your number!\n");
        printf("Number of operations: %d \n", k);
    }
    return 0;
}