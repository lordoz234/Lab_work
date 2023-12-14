#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include "Windows.h"

int check(int(x), int(y), int(xe), int(ye), int(m), int(**a)) { //функция для проверки наличия пути
	if ((x >= m) || (y >= m) || (x < 0) || (y < 0)) return 0;
	if (a[x][y] == 2 || a[x][y] == 0) return 0;
	if (x == xe && y == ye) return 1;
	if (a[x][y] == 1) {
		a[x][y] = 2;
		return check(x + 1, y, xe, ye, m, a) + check(x, y + 1, xe, ye, m, a) + check(x - 1, y, xe, ye, m, a) + check(x, y - 1, xe, ye, m, a);
	}
}

struct coordinates {
	int x;
	int y;
};

void delete_other(int(m), int(**a)) { //функция для удаления элементов массива, не являющихся частью пути
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) if (a[j][i]==1) a[j][i]=0;
	}
}

int local_check(int(x), int(y), int(m), int(**a)) { //функция для проверки наличия пути из точки
	int s = 0;
	if (x < m - 1) if ((a[x + 1][y] == 1)) s++;
	if (x > 0) if ((a[x - 1][y] == 1)) s++;
	if (y < m - 1) if ((a[x][y + 1] == 1)) s++;
	if (y > 0) if ((a[x][y - 1] == 1)) s++;
	return s;
}

void reset_arr(int(m), int(**a), int(**b)) {
	for (int i = 0; i < m; i++) for (int j = 0; j < m; j++) a[j][i] = b[j][i];
}

void print_arr(int(m), int(**a)) {
	printf("\n");
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) printf("%d ", a[j][i]);
		printf("\n");
	}
	printf("\n");
}

void route(int(x), int(y), int(xs), int(ys), int(xe), int(ye), int(xl), int(yl), int(m), int(**a), int(c)) { //функция для создания маршрута
	if ((x >= 0) && (y >= 0) && (x < m) && (x < m) && (a[x][y] > 0)) {
		if ((x == xe) && (y == ye)) {
			if (c > 2) a[x][y] = c + 1;
			else a[x][y] = 2;
		}
		else if (local_check(x, y, m, a) == 0) {
			a[x][y] = 0;
			x = xl;
			y = yl;
			a[x][y] = 1;
			c = c - 1;
			if (local_check(x, y, m, a) == 0) {
				if ((xl < m - 1) && (a[xl + 1][yl] == c - 1)) xl++;
				else if ((xl > 0) && (a[xl - 1][yl] == c - 1)) xl--;
				else if ((yl < m - 1) && (a[xl][yl + 1] == c - 1)) yl++;
				else if ((yl > 0) && (a[xl][yl - 1] == c - 1)) yl--;
			}
			else
				xl = yl = -1;
			route(x, y, xs, ys, xe, ye, xl, yl, m, a, c);
		}
		else if (a[x][y]==1 || (x==xs && y==ys)) {
			a[x][y] = c++;
			if (((x == xe) && (y == (ye - 1))) || ((x == xe) && (y == (ye + 1))) || ((y == ye) && (x == (xe - 1))) || ((y == ye) && (x == (xe - 1)))) a[xe][ye] = c++;
			else 
				if ((x - xe > 0) && (y - ye > 0)) {
					if ((x > 0) && (x - 1 != xl) && (a[x - 1][y] == 1)) route(x - 1, y, xs, ys, xe, ye, x, y, m, a, c);
					else if ((y > 0) && (y - 1 != yl) && (a[x][y - 1] == 1)) route(x, y - 1, xs, ys, xe, ye, x, y, m, a, c);
					else if ((y < m - 1) && (y + 1 != yl) && (a[x][y + 1] == 1)) route(x, y + 1, xs, ys, xe, ye, x, y, m, a, c);
					else if ((x < m - 1) && (x + 1 != xl) && (a[x + 1][y] == 1)) route(x + 1, y, xs, ys, xe, ye, x, y, m, a, c);
				}
				else if ((x - xe > 0) && (y - ye < 0)) {
					if ((x > 0) && (x - 1 != xl) && (a[x - 1][y] == 1)) route(x - 1, y, xs, ys, xe, ye, x, y, m, a, c);
					else if ((y < m - 1) && (y + 1 != yl) && (a[x][y + 1] == 1)) route(x, y + 1, xs, ys, xe, ye, x, y, m, a, c);
					else if ((y > 0) && (y - 1 != yl) && (a[x][y - 1] == 1)) route(x, y - 1, xs, ys, xe, ye, x, y, m, a, c);
					else if ((x < m - 1) && (x + 1 != xl) && (a[x + 1][y] == 1)) route(x + 1, y, xs, ys, xe, ye, x, y, m, a, c);
				}
				else if ((x - xe < 0) && (y - ye > 0)) {
					if ((x < m - 1) && (x + 1 != xl) && (a[x + 1][y] == 1)) route(x + 1, y, xs, ys, xe, ye, x, y, m, a, c);
					else if ((y > 0) && (y - 1 != yl) && (a[x][y - 1] == 1)) route(x, y - 1, xs, ys, xe, ye, x, y, m, a, c);
					else if ((y < m - 1) && (y + 1 != yl) && (a[x][y + 1] == 1)) route(x, y + 1, xs, ys, xe, ye, x, y, m, a, c);
					else if ((x > 0) && (x - 1 != xl) && (a[x - 1][y] == 1)) route(x - 1, y, xs, ys, xe, ye, x, y, m, a, c);
				}
				else if ((x - xe < 0) && (y - ye < 0)) {
					if ((x < m - 1) && (x + 1 != xl) && (a[x + 1][y] == 1)) route(x + 1, y, xs, ys, xe, ye, x, y, m, a, c);
					else if ((y < m - 1) && (y + 1 != yl) && (a[x][y + 1] == 1)) route(x, y + 1, xs, ys, xe, ye, x, y, m, a, c);
					else if ((y > 0) && (y - 1 != yl) && (a[x][y - 1] == 1)) route(x, y - 1, xs, ys, xe, ye, x, y, m, a, c);
					else if ((x > 0) && (x - 1 != xl) && (a[x - 1][y] == 1)) route(x - 1, y, xs, ys, xe, ye, x, y, m, a, c);
				}
				else if ((x - xe > 0) && (y - ye == 0)) {
					if ((x > 0) && (x - 1 != xl) && (a[x - 1][y] == 1)) route(x - 1, y, xs, ys, xe, ye, x, y, m, a, c);
					else if ((x < m - 1) && (x + 1 != xl) && (a[x + 1][y] == 1)) route(x + 1, y, xs, ys, xe, ye, x, y, m, a, c);
					else if ((y > 0) && (y - 1 != yl) && (a[x][y - 1] == 1)) route(x, y - 1, xs, ys, xe, ye, x, y, m, a, c);
					else if ((y < m - 1) && (y + 1 != yl) && (a[x][y + 1] == 1)) route(x, y + 1, xs, ys, xe, ye, x, y, m, a, c);
				}
				else if ((x - xe == 0) && (y - ye > 0)) {
					if ((y > 0) && (y - 1 != yl) && (a[x][y - 1] == 1)) route(x, y - 1, xs, ys, xe, ye, x, y, m, a, c);
					else if ((y < m - 1) && (y + 1 != yl) && (a[x][y + 1] == 1)) route(x, y + 1, xs, ys, xe, ye, x, y, m, a, c);
					else if ((x < m - 1) && (x + 1 != xl) && (a[x + 1][y] == 1)) route(x + 1, y, xs, ys, xe, ye, x, y, m, a, c);
					else if ((x > 0) && (x - 1 != xl) && (a[x - 1][y] == 1)) route(x - 1, y, xs, ys, xe, ye, x, y, m, a, c);
				}
				else if ((x - xe < 0) && (y - ye == 0)) {
					if ((x < m - 1) && (x + 1 != xl) && (a[x + 1][y] == 1)) route(x + 1, y, xs, ys, xe, ye, x, y, m, a, c);
					else if ((x > 0) && (x - 1 != xl) && (a[x - 1][y] == 1)) route(x - 1, y, xs, ys, xe, ye, x, y, m, a, c);
					else if ((y > 0) && (y - 1 != yl) && (a[x][y - 1] == 1)) route(x, y - 1, xs, ys, xe, ye, x, y, m, a, c);
					else if ((y < m - 1) && (y + 1 != yl) && (a[x][y + 1] == 1)) route(x, y + 1, xs, ys, xe, ye, x, y, m, a, c);
				}
				else if ((x - xe == 0) && (y - ye < 0)) {
					if ((y < m - 1) && (y + 1 != yl) && (a[x][y + 1] == 1)) route(x, y + 1, xs, ys, xe, ye, x, y, m, a, c);
					else if ((y > 0) && (y - 1 != yl) && (a[x][y - 1] == 1)) route(x, y - 1, xs, ys, xe, ye, x, y, m, a, c);
					else if ((x < m - 1) && (x + 1 != xl) && (a[x + 1][y] == 1)) route(x + 1, y, xs, ys, xe, ye, x, y, m, a, c);
					else if ((x > 0) && (x - 1 != xl) && (a[x - 1][y] == 1)) route(x - 1, y, xs, ys, xe, ye, x, y, m, a, c);
				}
		}
	}
}

void main() {
	srand(time(NULL));
	setlocale(LC_ALL, "RU");

	int m, x, y, x1, y1, xs, ys, xs1, ys1, xe, ye, xe1, ye1;
	int l1 = 0, l2 = 0, lmax;
	int xl, yl;
	int mode;
	int check1 = 0, check2 = 0;
	int c = 2;

	do {
		printf("Введите размер поля\n");
		scanf_s("%d", &m);
	} while (m < 2);

	int** a = malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++) a[i] = (int*) malloc(m * sizeof(int));

	int** a1 = malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++) a1[i] = (int*)malloc(m * sizeof(int));

	int** a2 = malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++) a2[i] = (int*)malloc(m * sizeof(int));

	int** b = malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++) b[i] = (int*) malloc(m * sizeof(int));

	for (int i = 0; i < m; i++) for (int j = 0; j < m; j++) b[j][i] = a[j][i] = 0;

	do {
		printf("Выберите способ задания лабиринта (1 - вручную, 2 - случайным образом)\n");
		scanf_s("%d", &mode);
	} while ((mode < 0) && (mode > 1));

	if (mode == 1) {
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++) {
				do {
					printf("Введите значение элемента массива (0 или 1) c координатами %d %d\n", j, i);
					scanf_s("%d", &a[j][i]);
				} while (a[j][i] < 0 || a[j][i]>1);
				b[j][i] = a[j][i];
			}
	}
	else {
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++) {
				a[j][i] = ((rand()) % 6) % 2;
				b[j][i] = a[j][i];
			}
	}

	print_arr(m, a);

	do {
		printf("Введите координаты начала пути первого робота\n");
		scanf_s("%d %d", &xs, &ys);
	} while ((xs < 0) && (ys < 0) && (xs >= m) && (ys >= m));

	do {
		printf("Введите координаты начала пути второго робота\n");
		scanf_s("%d %d", &xs1, &ys1);
	} while ((xs1 < 0) && (ys1 < 0) && (xs1 >= m) && (ys1 >= m));

	do {
		printf("Введите координаты конца пути роботов\n");
		scanf_s("%d %d", &xe, &ye);
	} while ((xe < 0) && (ye < 0) && (xe >= m) && (ye >= m));

//	Поиск пути для первого робота
	
	x = xs;
	y = ys;
	xl = -1;
	yl = -1;

	if ((a[xs][ys] != 0) && (a[xe][ye] != 0) && (check(x, y, xe, ye, m, a) > 0)) {
		check1 = 1;
		printf("Для первого робота есть путь\n");
		reset_arr(m, a, b);
		x = xs;
		y = ys;
		route(x, y, xs, ys, xe, ye, xl, yl, m, a, c);
		for (int i = 0; i < m; ++i) for (int j = 0; j < m; ++j) if (a[j][i] > l1) l1 = a[j][i];
		l1--;
		delete_other(m, a);
		reset_arr(m, a1, a);
	}
	else printf("Нет пути для первого робота\n");

//	Поиск пути для второго робота

	x = xs1;
	y = ys1;
	xl = -1;
	yl = -1;
	reset_arr(m, a, b);

	if (check(x, y, xe, ye, m, a) > 0) {
		check2 = 1;
		printf("Для второго робота есть путь\n");
		reset_arr(m, a, b);
		x = xs1;
		y = ys1;
		route(x, y, xs1, ys1, xe, ye, xl, yl, m, a, c);
		for (int i = 0; i < m; ++i) for (int j = 0; j < m; ++j) if (a[j][i] > l2) l2 = a[j][i];
		l2--;
		delete_other(m, a);
		reset_arr(m, a2, a);
	}
	else printf("Нет пути для второго робота\n");

	x = xs1;
	y = ys1;
	xl = -1;
	yl = -1;
	reset_arr(m, a, b);

	


	if ((check1 == 1) && (check2 == 1)) {	//Есть путь для обоих роботов
		//Создание массива, содержащего маршрут первого робота
		struct coordinates* route1 = malloc(l1 * sizeof(struct coordinates));
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < m; ++j)
				if (a1[j][i] > 0) {
					route1[a1[j][i] - 2].x = j;
					route1[a1[j][i] - 2].y = i;
				}
		//Создание массива, содержащего маршрут второго робота
		struct coordinates* route2 = malloc(l2 * sizeof(struct coordinates));
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < m; ++j)
				if (a2[j][i] > 0) {
					route2[a2[j][i] - 2].x = j;
					route2[a2[j][i] - 2].y = i;
				}
		int cur_pos1 = -1, cur_pos2 = -1;
		while ((cur_pos1 < l1-1) || (cur_pos2 < l2-1)) {
			if ((route1[cur_pos1].x != xe) || (route1[cur_pos1].y != ye)) cur_pos1++;
			if (((route2[cur_pos2].x != xe) || (route2[cur_pos2].y != ye)) && (((route1[cur_pos1].x == xe) && (route1[cur_pos1].y == ye)) || ((route2[cur_pos2 + 1].x != route1[cur_pos1].x) && (route2[cur_pos2 + 1].y != route1[cur_pos1].y)))) cur_pos2++;
			system("cls");
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < m; ++j) {
					if ((j == xe) && (i == ye)) printf("F  ");
					else if ((j == route1[cur_pos1].x) && (i == route1[cur_pos1].y)) printf("P1 ");
					else if ((j == route2[cur_pos2].x) && (i == route2[cur_pos2].y)) printf("P2 ");
					else if ((j == xs) && (i == ys)) printf("S1 ");
					else if ((j == xs1) && (i == ys1)) printf("S2 ");
					else printf("%d  ", a[j][i]);
				}
				printf("\n");
			}
			Sleep(1000);
		}
	}
	else if ((check1 == 1) && (check2 == 0)) {	//Есть путь только для первого робота
		struct coordinates* route1 = malloc(l1 * sizeof(struct coordinates));
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < m; ++j)
				if (a1[j][i] > 0) {
					route1[a1[j][i] - 2].x = j;
					route1[a1[j][i] - 2].y = i;
				}

		for (int counter = 0; counter < l1;++counter) {
			system("cls");
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < m; ++j) {
					if ((j == route1[counter].x) && (i == route1[counter].y)) printf("P1 ");
					else if ((j == xs) && (i == ys)) printf("S1 ");
					else if ((j == xe) && (i == ye)) printf("F  ");
					else printf("%d  ", a[j][i]);
				}
				printf("\n");
			}
			Sleep(1000);
		}
	}
	else if ((check1 == 0) && (check2 == 1)) {	 //Есть путь только для второго робота
		struct coordinates* route2 = malloc(l2 * sizeof(struct coordinates));
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < m; ++j)
				if (a2[j][i] > 0) {
					route2[a2[j][i] - 2].x = j;
					route2[a2[j][i] - 2].y = i;
				}

		for (int counter = 0; counter < l2;++counter) {
			system("cls");
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < m; ++j) {
					if ((j == route2[counter].x) && (i == route2[counter].y)) printf("P2 ");
					else if ((j == xs) && (i == ys)) printf("S2 ");
					else if ((j == xe) && (i == ye)) printf("F  ");
					else printf("%d  ", a[j][i]);
				}
				printf("\n");
			}
			Sleep(1000);
		}
	}
	else printf("Нет путей");
}