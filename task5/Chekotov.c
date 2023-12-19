#include <stdio.h>
#include <stdlib.h>
int main()
{
    int hgt1, hgt2, wdt1, wdt2;
    int** a;
    int** b;
    int** c;
    printf("Введите количество строк первой матрицы: ");
    scanf("%d", &hgt1);
    printf("Введите количество столбцов первой матрицы: ");
    scanf("%d", &wdt1);
    printf("Введите количество строк второй матрицы: ");
    scanf("%d", &hgt2);
    printf("Введите количество столбцов второй матрицы: ");
    scanf("%d", &wdt2);
    if (wdt1 != hgt2) {
        printf("Умножение невозможно!");
    }

    a = malloc(hgt1 * sizeof(int*));
    printf("Введите элементы первой матрицы:\n");
    for (int i = 0; i < hgt1; i++) {
        a[i] = (int*)malloc(wdt1 * sizeof(int));
        for (int j = 0; j < wdt1; j++) {
            printf("%d %d: ", i, j);
            scanf("%d\n", &a[i][j]);
        }
    }

    printf("Первая матрица: \n");
    for (int i = 0; i < hgt1; i++) {
        for (int j = 0; j < wdt1; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    b = malloc(hgt2 * sizeof(int*));
    printf("Введите элементы второй матрицы:\n");
    for (int i = 0; i < hgt2; i++) {
        b[i] = (int*)malloc(wdt2 * sizeof(int));
        for (int j = 0; j < wdt2; j++) {
            printf("%d %d: ", i, j);
            scanf("%d\n", &b[i][j]);
        }
    }

    printf("Вторая матрица: \n");
    for (int i = 0; i < hgt2; i++) {
        for (int j = 0; j < wdt2; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    c = malloc(hgt1 * sizeof(int*));
    for (int i = 0; i < hgt1; i++) {
        c[i] = (int*)malloc(wdt2 * sizeof(int));
        for (int j = 0; j < wdt2; j++) {
            c[i][j] = 0;
            for (int k = 0; k < wdt1; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }

    printf("Матрица произведения:\n");
    for (int i = 0; i < hgt1; i++) {
        for (int j = 0; j < wdt2; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
}