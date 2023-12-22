#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

struct cell {
	int x;
	int y;
};
//стандартная рекурсия для определения, есть ли путь из точки (x,y) в (endx,endy) и придания массиву необходимого для дальнейшего поиска вида
int rec(int(x), int(y), int endx, int endy, int(wh), int(lh), int(**a), int last) {
	if (x >= wh || y >= lh || x < 0 || y < 0)
		return 0;
	if (a[x][y] != 1)
		return 0;
	if (x == endx && y == endy) {
		a[x][y] = last;
		return 1;
	}
	if (a[x][y] == 1) {
		a[x][y] = last;
		return(rec(x + 1, y, endx, endy, wh, lh, a, last + 1) + rec(x, y + 1, endx, endy, wh, lh, a, last + 1) + rec(x, y - 1, endx, endy, wh, lh, a, last + 1) + rec(x - 1, y, endx, endy, wh, lh, a, last + 1));
	}
	return 0;
}
//функция для определения длинны пути из точки (stx,sty) в точку (endx,endy)
int pre_find_way(int wh, int lh, int stx, int sty, int endx, int endy, int(**a)) {
	int res = 0, x, y, fl = 0, n = 0, i = 0;
	res = rec(stx, sty, endx, endy, wh, lh, a, 2);
	x = endx;
	y = endy;

	if (res == 0) {
		return(0);
	}
	else {
		while (x != stx || y != sty) {
			n = n + 1;
			fl = 0;
			if (x >= 1 && fl == 0) {
				if (a[x][y] - a[x - 1][y] == 1) {
					x = x - 1;
					y = y;
					fl = 1;
				}
			}
			if (x <= wh - 2 && fl == 0) {
				if (a[x][y] - a[x + 1][y] == 1) {
					x = x + 1;
					y = y;
					fl = 1;
				}
			}
			if (y >= 1 && fl == 0) {
				if (a[x][y] - a[x][y - 1] == 1) {
					x = x;
					y = y - 1;
					fl = 1;
				}
			}
			if (y <= lh - 2 && fl == 0) {
				if (a[x][y] - a[x][y + 1] == 1) {
					x = x;
					y = y + 1;
					fl = 1;
				}
			}
		}
		n = n + 1;
		return(n);
	}
}
//функция для заполнения массива структур, созданного в main, длинны n, полученного благодаря предыдущей функции
int find_way(int wh, int lh, int stx, int sty, int endx, int endy, int(**a), struct cell* way) {

	int res = 0, x, y, fl = 0, n = 0, i = 0;
	res = rec(stx, sty, endx, endy, wh, lh, a, 2);
	x = endx;
	y = endy;

	if (res == 0) {
	}
	else {
		while (x != stx || y != sty) {
			struct cell pos = { x,y };
			way[i] = pos;
			i++;
			fl = 0;
			if (x >= 1 && fl == 0) {
				if (a[x][y] - a[x - 1][y] == 1) {
					x = x - 1;
					y = y;
					fl = 1;
				}
			}
			if (x <= wh - 2 && fl == 0) {
				if (a[x][y] - a[x + 1][y] == 1) {
					x = x + 1;
					y = y;
					fl = 1;
				}
			}
			if (y >= 1 && fl == 0) {
				if (a[x][y] - a[x][y - 1] == 1) {
					x = x;
					y = y - 1;
					fl = 1;
				}
			}
			if (y <= lh - 2 && fl == 0) {
				if (a[x][y] - a[x][y + 1] == 1) {
					x = x;
					y = y + 1;
					fl = 1;
				}
			}
		}
		struct cell pos = { x,y };
		way[i] = pos;
		return 0;
	}
	return 0;
}

int main() {
	FILE *inputf = NULL, *outputf = NULL;
	errno_t error=fopen_s(&inputf,"input.txt", "r");
	if (error !=0){
		printf("Не удалось открыть файл.");
	}
	error=fopen_s(&outputf,"output.txt", "w");
	if (error != 0) {
		printf("Не удалось открыть файл.");
	}
	srand(time(NULL));
	char inp[8];
	int wh = 0, lh = 0, n1, n2, i, stx1, stx2, sty1, sty2, endx, endy;
	fread(inp, sizeof(inp[0]), 8, inputf);
	stx1 = inp[0]-'0';
	sty1 = inp[1]-'0';
	stx2 = inp[2]-'0';
	sty2 = inp[3]-'0';
	wh = inp[4]-'0';
	lh = inp[5]-'0';
	endx = inp[6] - '0';
	endy = inp[7] - '0';
	printf("%d %d %d %d %d %d %d %d\n", stx1, stx2, sty1, sty2, wh, lh,endx,endy);
	//создание массивов а и а1
	int** a = malloc(wh * sizeof(int*));
	for (int i = 0; i < wh; i++) {
		a[i] = malloc(lh * sizeof(int));
	}
	int** a1 = malloc(wh * sizeof(int*));
	for (int i = 0; i < wh; i++) {
		a1[i] = malloc(lh * sizeof(int));
	}
	//заполнение массивов а и а1 одинаковыми числами
	for (int i = 0; i < wh; i++) {
		for (int j = 0; j < lh; j++) {
			a[i][j] = rand() % 10;
			if (a[i][j] == 0) {
				a[i][j] = 0;
				a1[i][j] = 0;
			}
			else {
				a[i][j] = 1;
				a1[i][j] = 1;
			}
		}
	}
	a[stx1][sty1] = 1;
	a1[stx1][sty1] = 1;
	a[stx2][sty2] = 1;
	a1[stx2][sty2] = 1;
	a[wh-1][lh - 1] = 1;
	a1[wh-1][lh - 1] = 1;
	for (int i = 0; i < wh; i++) {
		for (int j = 0; j < lh; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	//определение длинны пути для 1 робота
	n1 = pre_find_way(wh, lh, stx1, sty1, endx, endy, a);
	//возвращение массива а в изначальное состояние
	for (int i = 0; i < wh; i++) {
		for (int j = 0; j < lh; j++) {
			a[i][j] = a1[i][j];
		}
	}
	//создание временного массива пути для 1 робота
	struct cell* way = malloc(n1 * sizeof(struct cell));
	if (way == NULL) {
		return 1;
	}
	printf("%d \n", n1);
	//заполнение 1 временного массива пути
	i = find_way(wh, lh, stx1, sty1, endx, endy, a, way);
	//создание постоянного массива
	struct cell* way1 = malloc(n1 * sizeof(struct cell));
	if (way1 == NULL) {
		return 1;
	}
	//заполнение постоянного массива пути перевернутым временным массивом
	for (int i = 0; i < n1; i++) {
		way1[n1 - i - 1] = way[i];
	}
	free(way);
	//возвращение массива а в изначальное состояние
	for (int i = 0; i < wh; i++) {
		for (int j = 0; j < lh; j++) {
			a[i][j] = a1[i][j];
		}
	}
	//определение длинны пути для 2 робота
	n2 = pre_find_way(wh, lh, stx2, sty2, endx, endy, a);
	//возвращение массива а в изначальное состояние
	for (int i = 0; i < wh; i++) {
		for (int j = 0; j < lh; j++) {
			a[i][j] = a1[i][j];
		}
	}
	//создание временного массива пути для 2 робота
	struct cell* wayy = malloc(n2 * sizeof(struct cell));
	if (wayy == NULL) {
		return 1;
	}
	printf("%d \n", n2);
	//заполнение 2 временного массива пути
	i = find_way(wh, lh, stx2, sty2, endx, endy, a, wayy);
	//создание постоянного массива
	struct cell* way2 = malloc(n2 * sizeof(struct cell));
	if (way2 == NULL) {
		return 1;
	}
	//заполнение постоянного массива пути перевернутым временным массивом
	for (int i = 0; i < n2; i++) {
		way2[n2 - i - 1] = wayy[i];
	}
	free(wayy);
	//возвращение массива а в изначальное состояние
	for (int i = 0; i < wh; i++) {
		for (int j = 0; j < lh; j++) {
			a[i][j] = a1[i][j];
		}
	}
	free(a);
	free(a1);
	char *sup1 = malloc((2 * n1+1) * sizeof(char));
	if (sup1 == NULL) {
		return 1;
	}
	
	char *sup2= malloc(2 * n2 * sizeof(char));
	if (sup2 == NULL) {
		return 1;
	}
	for (int i = 0; i < n1; i++) {
		sup1[i] = way1[i].x+'0';
		sup1[n1+i] = way1[i].y + '0';
		printf("%c,%c; ", sup1[i], sup1[n1+i]);
	}
	printf("\n");
	sup1[2 * n1] = '\n';
	for (int i = 0; i < n2; i++) {
		sup2[i] = way2[i].x + '0';
		sup2[n2+i] = way2[i].y + '0';
		printf("%c,%c; ", sup2[i], sup2[n2 + i]);
	}
	fwrite(sup1, sizeof(char), n1 * 2+1, outputf);
	fwrite(sup2, sizeof(char), n2 * 2, outputf);
	fclose(outputf);
	fclose(inputf);
}
