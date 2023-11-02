#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
int shag(int** a, int x, int y, int N, int M) {
    if (x == (N - 1) && y == (M - 1)) return 1;
    if ((x >= N) || (y >= M) || (x < 0) || (y < 0)) return 0;
    if (a[x][y] == 0) return 0;
    if (a[x][y] == 1) {
        a[x][y] = 0;
        return shag(a, x + 1, y, N, M) + shag(a, x, y + 1, N, M) +
            shag(a, x - 1, y, N, M) + shag(a, x, y - 1, N, M);
    }
}
int main() {
    setlocale(LC_ALL, "RU");
    int M = 0;
    int N = 0;
    int x = 0;
    int y = 0;
    printf("Введите размер лаберинта\n");
    scanf_s("%d%d", &M, &N);
    int** array = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        array[i] = (int*)malloc(M * sizeof(int));
    };
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            array[i][j] = rand() % 2;
        }
    };
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; ++j) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    if (shag(array, x, y, N, M) > 0) {
        printf("Путь найден");
    }
    else {
        printf("Нет пути");
    }

    return 0;
}