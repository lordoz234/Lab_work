#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int n, m;
int **array;
int **visit; // массив дл€ отслеживани€ посещенных €чеек

int find(int x, int y) {
	if ((x < 0) || (y < 0) || (x >= n) || (y >= m) || (array[x][y] == 0) || (visit[x][y] == 1))
		return 0;
	visit[x][y] = 1; //отмечаем посещенную €чейку
	if (x == n - 1 && y == m -1)
		return 1;
	if (find(x - 1, y) || find(x + 1, y) || find(x, y - 1) || find(x, y + 1))
		return 1;
	return 0;
}

int main() {
	setlocale(LC_ALL, "Russian");
	printf("¬ведите размеры массива: "); // создаем массив
	scanf_s("%d %d", &n, &m);
	array = malloc(n * sizeof(int));
	visit = malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		array[i] = malloc(m * sizeof(int));
		visit[i] = malloc(m * sizeof(int));
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf_s("%d", &array[i][j]);
			visit[i][j] = 0;
		}
	}
	
	if (find(0, 0)) {
		printf("ѕуть найден!\n");
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (visit[i][j] == 1)
					printf("%d %d\n", i, j);
			}
		}
	}
	else
		printf("Ќет пути");
		
	return 0;
}