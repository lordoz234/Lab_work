#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int mode;
	printf("Choose mode 1 or 2:\n ");
	scanf_s("%d", &mode);
	if (mode == 1) {
			printf("Your choose a mode with random num\n");
			printf("Try to guess a number:\n");
			srand(time(NULL));
			int a = rand() % 1000, n = 0, an, k = 0, m = 0, res = 0;
			while (n == 0) {
				scanf_s("%d", &an);
				if (an > a) {
					printf("Less\n");
					k++;
				}
				else if (an < a) {
					printf("More\n");
					m++;
				}
				else {
					printf("Right\n");
					n = 1;
					res = k + m;
					printf("Total attempt: %d;\n", res);
					return 0;
				}
			}
			return 0;
		}

		else if (mode == 2) {
			printf("Your choose a mode where computer try to guess your number\n");
			printf("Write a number:\n");
			int a, mid, left = 1, right = 1000;
			int k = 0, m = 0, res = 0;
			char clue;
			scanf_s("%d", &a);

			//Два раза пишет одно и то же хз почему.Я уже как не вертел этот принт 
			while (right - left > 1) {
				mid = (left + right) / 2;
				printf("PC think it is number: %d\n", mid);
				printf("Guess a clue:\n");
				scanf_s("%c", &clue);
				switch (clue) {
				case '>':
					left = mid;
					k++;
					break;
				case '<':
					right = mid;
					m++;
					break;
				case '=':
					printf("Number: %d\n", mid);
					res = k + m + 1;
					printf("Iteration: %d", res);
					return 0;
				}
			}

			return 0;

		}




}





