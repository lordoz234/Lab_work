#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
int main() {
	// выбор режима работы 1(комп загадывает число) или 2(чел загадывает число)
	setlocale(LC_ALL, "Russian");
	int V;
	int W;
	int robot=0;
	int A=0;
	int right;
	int left;
	int array[1001];
	printf("Введите границы поиска");
	scanf("%d%d", &left, &right);
	printf("Введите какую из двух программ вы хотите запустить. 1 - комп загадывает число, 2 - вы загадываете ");
	scanf("%d", &V);
	if (V == 1) {
		robot = rand() % 1000;
		while (A!= robot) {
			printf("введите число из диапазона");
			scanf("%d", &A);
			if (A > robot) {
				printf("Заданное компуктером число меньше вашего");
			}
			else if (A < robot) {
				printf("Заданное компуктером число больше вашего");
			}
			else if (A == robot) {
				printf("Вы угадали заданное число");
			};
		}
	}
	else {
		printf("Введите число, которое загадали");
		scanf("%d", &A);
		robot = (right + left) / 2;
		while (robot != A) {
			printf("Робот предлагает число ");
			printf("%d", robot);
			printf(" Если ваше число больше, введите 2. Если ваше число меньше, введите 1. Если число угадано то 0) ");
			scanf("%d", &W);
			if (W == 1) {
				right = robot;
				robot = (right+left) / 2;
			}
			else if (W == 2) {
				left = robot;
				robot = (right + left) / 2
			}
		};
		printf("Число угадано, ваше число = ");
		printf("%d", robot);
	};
	return 0;
}