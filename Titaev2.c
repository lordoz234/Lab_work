#include <stdio.h>
#include <math.h>
#include <locale.h>
int main() {
// выбор режима работы 1(комп загадывает число) или 2(чел загадывает число)
	setlocale(LC_ALL, "Russian");
	int V;
	int robot;
	int A;
	int right;
	int left;
	int array[1001];
	printf("Введите границы поиска/n");
	scanf("%d%d", &left, &right);
	printf("Введите какую из двух программ вы хотите запустить. 1 - комп загадывает число, 2 - вы загадываете./n");
	scanf("%V", &V);
	if ( V == 1) {
		robot = rand() % 1000;
		while (A != robot) {
			printf("введите число из диапазона/n");
			scanf("%A", &A);
			if (A > robot) {
				printf("Заданное компуктером число меньше вашего/n");
			}
			else if (A < robot) {
				printf("Заданное компуктером число больше вашего/n");
			}
			else if (A == robot) {
				printf("Вы угадали заданное число/n");
			};
		}
	}
	else {

	};
	return 0;}