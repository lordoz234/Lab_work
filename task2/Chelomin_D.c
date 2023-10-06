#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int m, n, g, a;

    printf("Select a mode:\n");
    scanf("%d", &m);

    if (m == 1) {
        srand(time(NULL));
        n = rand() % 1000 + 1;
        
        a = 0;
        g = 0;
        
        while (g != n) {
            printf("Enter your guess:\n");
            scanf("%d", &g);
            a++;
            
            if (g > n) {
                printf("THE HIDDEN NUMBER IS LESS\n");
            } else if (g < n) {
                printf("THE HIDDEN NUMBER IS GREATER\n");
            } else {
                printf("You guessed it in the following number of attempts: %d\n", a);
            }
        }
    } else if (m == 2) {
        int min = 0;
        int max = 1000;
        char r;
        printf("Enter the hidden number:\n ");
        scanf("%d", &n);

        while (min<=max) {
            g = (min + max)/2;
            printf("Computer offers a number: %d\n", g);
            printf("Enter the answer:\n");
            scanf(" %c", &r);
            a++;
            if (r == '>') {
                max = g - 1;
            } else if (r == '<') {
                min = g + 1;
            } else if(r == '=') {
                printf("Computer guessed the number in the following number of attempts: %d\n", a);
            }
        }
    } else {
        printf("The program has only 2 modes\n");
    }
    
    return 0;
}