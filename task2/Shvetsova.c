#include <stdio.h>
#include <time.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL, "Russian_Rissia.1251");
    char sign;
    int insign = 0;
    int mode;
    int compval, userval;
    int cnt = 1;
    printf("choose mode(1 or 2)\n");
    scanf("%d", &mode);
    if (mode == 1)
    {
        srand(time(NULL));
        compval = rand() % 1000;
        scanf("%d", &userval);
        while (userval != compval)
        {
            if (compval > userval)
            {
                printf("More\n");
            }
            if (compval < userval)
            {
                printf("Less\n");
            }
            cnt++;
            scanf("%d", &userval);
        }
        printf("Correct!  %d %d", cnt, compval);
    }
    if (mode == 2)
    {
        printf("think of a number\n");
        scanf("%d", &userval);
        int min, max;
        min = 0;
        max = 1000;
        while (insign != 61)
        {
            compval = min + (max - min) / 2;
            printf("%d\n", compval);
            scanf(" %c", &sign);
            insign = (int)sign;
            if (insign == 62)
            {
                min = compval;
            }
            if (insign == 60)
            {
                max = compval;
            }
            cnt++;
        }

        printf("%d", cnt - 1);
    }
}