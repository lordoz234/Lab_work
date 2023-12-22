#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
int step(int** a, int x, int y, int n, int m) {
	if (x == (n - 1) && y == (m - 1)) return 1;
	if ((x >= n) || (y >= m) || (x < 0) || (y < 0)) return 0;
	if (a[x][y] == 0) return 0;
	if (a[x][y] == 1) {
		a[x][y] = 0;
		return step(a, x + 1, y, n, m) + step(a, x, y + 1, n, m) +
			step(a, x - 1, y, n, m) + step(a, x, y - 1, n, m);
	}
}
int main() {
	setlocale(LC_ALL, "RU");
	printf("¬ведите размеры пол€, где первое число - строки, а второе - столбики\n");
	int m, n;
	int x = 0;
	int y = 0;
	scanf("%d %d", &m, &n);
	int** a = malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		a[i] = (int*)malloc(m * sizeof(int));
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("¬ведите значени€ 0 или 1 в €чейку ");
			printf("%d %d", i + 1, j + 1);
			scanf("%d", &a[i][j]);
		}
	}
	a[0][0] = 1;
	a[n - 1][m - 1] = 1;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d ", a[j][i]);
		}
		printf("\n");
	}
	if (step(a, x, y, n, m) > 0) {
		printf("ѕуть существует");
	}
	else {
		printf("Ќевозможно пройти");
	}
}