#include <stdio.h>
#include <math.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
int otgp=10000;
char vvp = 'f';
void f1(zagk) {
	int kpop;
	kpop = 0;
	otgp = 10000;
	while (otgp != zagk) {
		++kpop;
		printf("Попытка %d \n",kpop);
		printf("Введите предполагаемое число (для выхода: 9999): ");
		otgp = 10000;
		scanf_s("%d", &otgp);
		if (otgp >=10000 || otgp <=0) {
			printf("Ошибка ввода\n");
			vvp = '9';
			otgp = 9999;
			break;
		}
		if (otgp == 9999) {
			printf("Игра окончена\n");
			break;
		}
		else if (otgp < zagk) {
			printf("больше\n");
		}
		else if (otgp > zagk) {
			printf("меньше\n");
		}
		else if (otgp == zagk) {
			printf("число, загаданное компьютером было %d \n", zagk);
			printf("количество попыток: %d \n", kpop);
		}
	}
}
void f2() {
	int otgk,sotgk, code,c;
	sotgk = 1000;
	otgk = 500;
	code = 1;
	vvp = 'f';
	while (vvp != '=') {
		printf("Компьютер предположил: %d \n", otgk);
		printf("введите = если число отгадано, > если число больше предположенного, < если число меньше предположенного \n");
		printf("(для выхода введите 9): ");
		vvp = 'f';
		scanf_s(" %c", &vvp, 1);
		printf("%c", vvp);
		if (vvp == '9') {
			printf("Выход из 2 режима \n");
			break;
		}
		if (vvp == '>') {
			c = otgk;
			if (sotgk != otgk) {
				otgk = otgk + abs(sotgk - otgk) / 2;
			}
			else {
				otgk = otgk + 1;
			}
			sotgk = c;
		}
		else if (vvp == '<') {
			c = otgk;
			if (sotgk != otgk) {
				otgk = otgk - abs(sotgk - otgk) / 2;
			}
			else {
				otgk = otgk - 1;
			}
			sotgk = c;
			}
		else if (vvp == '=') {
			printf("Загаданное число было: %d \n", otgk);
			}
		else {
			printf("Не верный ввод \n");
		}
	}
}
void main() {
	int res, zagk, zagp;
	srand(time(NULL));
	
	zagp = 10000;
	setlocale(LC_ALL, "RU");
	otgp == 10000;
	vvp = 'f';
	printf("Эта программа имеет два режима: в первом режиме программа загадывает число, \nа пользователь должен его угадать, во 2 режиме пользователь загадывает число, а программа пытается его отгадать\n");
	while (otgp!=9999 || vvp != '9'){
		printf("Введите 1 для первого режима и 2 для второго режима (для выхода 9): ");
		res = 99;
		scanf_s("%d", &res);
		zagk = rand() % 1000;
		if (res == 99) {
			printf("Ошибка ввода");
			break;
		}
		if (res == 9999) {
			printf("Игра окончена");
		}
		else if (res == 1) {
			f1(zagk);
		}
		else if (res == 2) {
			f2();
		}
		else if (res == 9) {
			printf("Выход");
			break;
		}
		else {
			printf("Не верный режим  \n");
		}
	}
}