#include <stdio.h>
#include <math.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
void f1(zagk) {
	int otgp,kpop;
	kpop = 0;
	otgp = 10000;
	while (otgp != zagk) {
		++kpop;
		printf("Попытка %d \n",kpop);
		printf("Введите предполагаемое число : ");
		
		scanf_s("%d", &otgp);
		if (otgp == 9999) {
			printf("Игра окончена");
			break;
		}
		if (otgp < zagk) {
			printf("больше\n");
		}
		if (otgp > zagk) {
			printf("меньше\n");
		}
	}
	if (otgp == zagk) {
		printf("число, загаданное компьютером было %d \n", zagk);
		printf("количество попыток %d", kpop);
	}
}
f2() {
	int otgk,sotgk;
	char vvp;
	vvp = 'f';
	sotgk = 1000;
	otgk = 500;
	while (vvp!= '=') {
		printf("%d \n",otgk);
		printf("введите = если число отгадано, > если число больше предположенного, < если число меньше предположенного: ");
		scanf_s("%s", &vvp);
		if (vvp == '>') {
			otgk = otgk + abs(sotgk - otgk) / 2;
		}
		else if (vvp == '<') {
			otgk = otgk - abs(sotgk - otgk) / 2;
		}
		else if (vvp == '=') {
			printf("загаданое число было %d", otgk);
		}
	}
}
void main() {
	int res,zagk,zagp;
	srand(0);
	zagk = rand() % 1000;
	printf("%d", zagk);
	zagp = 10000;
	setlocale(LC_ALL, "RU");
	printf("Введите 1 для первого режима и 2 для второго режима для выхода в любой момент введите 9999: ");
	scanf_s("%d", &res);
	if (res == 9999) {
		printf("Игра окончена");
	}
	else if (res == 1) {
		f1(zagk);
	}
	else if (res == 2) {
		f2();
	}
	else {
		printf("Не верный режим");
	}
}