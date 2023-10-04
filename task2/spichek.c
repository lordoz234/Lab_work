#include <stdio.h>
#include <locale.h>
#include <time.h>

void f2() {   //2 режим
	int answer, left, right, mid, ch, otvet, k, zagadch;
	char znak;
	right = 1000;
	k = 1;
	left = 1;
	otvet = -1;

	do {
		printf("Введите число, которое хотите загадать (от 1 до 1000)\n");
		scanf_s("%d", &zagadch);
		if ((zagadch < 1) || (zagadch > 1000)) while (ch = getchar() != '\n');
	} while ((zagadch < 1) || (zagadch > 1000));

	while (ch = getchar() != '\n');

	while (right - left > 2) {
		mid = (left + right) / 2 + (left + right) % 2;

		///printf("%d %d %d\n", left, mid, right);

		do {
			printf("Заданное число больше %d? (Введите >, < или =)\n", mid);
			scanf_s("%c", &znak);
			answer = znak;
			if ((answer > 62) || (answer < 60)) while (ch = getchar() != '\n');
		} while ((answer > 62) || (answer < 60));

		if (answer == 62) {
			left = mid + 1;
		}
		else {
			if (answer == 60) {
				right = mid - 1;
			}
			else {
				otvet = mid;
				break;
			}
		}

		while (ch = getchar() != '\n');

		k++;
	}


	if (otvet == -1) {
		mid = (left + right) / 2;

		//printf("%d %d %d\n", left, mid, right);


		do {
			//printf("> < =\n");
			printf("Заданное число больше %d? (Введите >, < или =)\n", mid);
			scanf_s("%c", &znak);
			answer = znak;
			if ((answer > 62) || (answer < 60)) while (ch = getchar() != '\n');
		} while ((answer > 62) || (answer < 60));

		if (answer == 62) {
			otvet = right;
		}
		else {
			if (answer == 60) {
				otvet = left;
			}
			else otvet = mid;
		}

		while (ch = getchar() != '\n');
	}
	if (zagadch != otvet) {
		printf("Программе не удалось угадать число\n");
		printf("Программа отгадала число %d\n", otvet);
		printf("Вы загадали число %d\n", zagadch);
	}
	else printf("Программа отгадала загаданное вами число %d\n", otvet);
	printf("Число попыток: %d\n", k);
}


void f1() {
	int answer, user, ch, k;
	
	k = 0;
	/*srand(0);
	answer = rand()%1000 + 1;*/
	
	srand(time(NULL));
	answer = rand() % 1000 + 1;

	do {
		do {
			printf("Введите предполагаемое число (от 1 до 1000)\n");
			scanf_s("%d", &user);
			if ((user < 1) || (user > 1000)) while (ch = getchar() != '\n');
		} while ((user < 1) || (user > 1000));
		
		if (user != answer) {
			if (user > answer) printf("Загаданное число меньше\n");
			else printf("Загаданное число больше\n");
		}
		k += 1;
	} while (user != answer);

	printf("Вы угадали\n");
	printf("Было загадано число %d\n", answer);
	printf("Число попыток: %d\n", k);
}

void main() {
	int flag, rez, ch;
	flag = 0;
	setlocale(LC_ALL, "Rus");

	printf("Режим 1. Программа «загадывает» случайное число из диапазона от 1 до 1000. Пользователь\nдолжен вводить отгадки, на которые программа сообщает : «загаданное число больше»,\nзагаданное число меньше», «угадали».Работа завершается, когда пользователь угадает\n число.Также программа должна подсчитывать число попыток и выводить его в конце работы.\n");
	printf("\n");
	printf("Режим 2. Пользователь загадывает число из диапазона от 1 до 1000 и вводит его. Программа\nпытается «угадать» число, выводя на экран отгадки, на которые пользователь вводит > , < или = .\nРабота завершается, когда программа угадает число.Также программа должна подсчитывать\n");
	printf("\n");

	do {
		printf("Выберите режим (Введите 1 или 2)\n");
		scanf_s("%d", &rez);
		if (rez < 1 || rez>2) while (ch = getchar() != '\n');
	} while (rez < 1 || rez>2);
	
	if (rez == 2) f2();
	else f1();
}