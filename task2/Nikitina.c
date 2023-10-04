#include <stdio.h>
#include <locale.h>
#include <time.h>
void main() {
	setlocale(LC_ALL, "Rus");
	int mode,num2; // режим
	int flag = 0;
	int k = 0;// кол-во попыток
	
	printf("Выберите режим: ");
	scanf_s("%d", &mode);
	// 1 режим
	if (mode == 1) {
		srand(time(NULL));
		int num1 = rand() % 1000; // загаданное число
		int x; // число, которое пользователь вводит
		do {
			flag = 0;
			printf("Введите число:");
			scanf_s("%d", &x);
			if (x < num1) {
				printf("Загаданное число больше\n");
				k++;
				flag = 1;
			}
			else if (x > num1) {
				printf("Загаднное число меньше\n");
				k++;
				flag = 1;
			}
		} while (flag); 
		 
		if (x == num1) {
			k++;
			printf("Угадали!\n");
			printf("Количество попыток: %d", k);
		}
		
		
	}// 2 режим
	if (mode == 2) {
		char c = '0';
		int right = 1001; // границы
		int left = 0;
		int mid = (right + left) / 2;
		
		printf("Введите ваше число: ");
		scanf_s("%d", &num2);
		
		while (c!='=') {
			printf("Это число %d?\n", mid);
			printf("Введите подсказку: ");
			scanf_s("\n%c", &c);
			k++;
			if (c == '=') {
				printf("Число отгадано!\nКоличество попыток: %d", k);
				break;
			}
			else if (c == '<') {
				right = mid;
			
			}
			else if (c == '>') {
				left = mid;

			}
			mid = (right + left) / 2;
			
			
		}
	}
	
	
}