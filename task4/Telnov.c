#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int hod(int** pol, int x, int y, int N, int M, int **ya) {
	if (x < 0 || x >= N || y < 0 || y >= M || pol[x][y] == 0 || ya[x][y] == 1) {
		return false;
	}

	ya[x][y] = 1;

	if (x == 0 && y == M - 1) {
		return true;
	}

	if (hod(pol, x + 1, y, N, M, ya) || hod(pol, x - 1, y, N, M, ya) ||
		hod(pol, x, y + 1, N, M, ya) || hod(pol, x, y - 1, N, M, ya)) {
		return true;
	}

	ya[x][y] = 0;
	return false;
}

int main() {
	int n, m;

	printf("Vvedite razmer polya (n m) ");
	scanf_s("%d %d", &n, &m);
	int** pole = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		pole[i] = malloc(m * sizeof(int));
	}

	printf("Vvedite znacheniya (0 - lovyshka, 1 - mojno hodit) v yacheuki polya ");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%d", &pole[i][j]);         // zapolnenie idet '->' sverhy vniz 
		}
	}
	pole[n - 1][0] = 1;
	pole[0][m - 1] = 1;
	//sozdan labirint

	int** ya = malloc(n * sizeof(int));        //moi pyt    
	for (int i = 0; i < n; i++) {
		ya[i] = malloc(m * sizeof(int));
	}

	if (hod(pole, n-1, 0, n, m, ya)){
		printf("pyt nauden\n");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				printf("%d ", ya[i][j]);
			}
			printf("\n");
		}
	}
	else {
		printf("Net pyti\n");
	}
}