#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	printf("����� ������: \n 1)���������� ���������\n 2)���������� ������������\n");

	int mode;
	srand(time(0));
	do 
	{
		scanf_s("%d", &mode);
	} while (mode != 1 && mode != 2);

	if (mode == 1)
	{
		int number = rand() % 1000;
		int count = 0;
		int valid = 0;
		int guess;
		while (valid != 1)
		{
			printf("������� �����: ");
			scanf_s("%d", &guess);
			printf("\n");
			if (guess > number)
			{
				printf("���������� ����� ������\n");
				++count;
			}
			else if (guess < number)
			{
				printf("���������� ����� ������\n");
				++count;
			}
			else
			{
				printf("�������\n");
				printf("��� - �� ������� = ");
				printf("%d", count);
				return 1;
			}
		}

	}
	else
	{
		int numbers[1000];
		for (int i = 0; i < 1000; ++i)
		{
			numbers[i] = i + 1;
		};
		printf("������� �����: ");
		printf("\n");
		int number, index;
		scanf_s("%d", &index);
		number = numbers[index - 1];
		int count = 0;
		int f_index = 0;
		int p_index = 999;
		int valid = 0;
		int guess = 0;
		int guess_p = 0;		
		while (valid != 1)
		{
			printf("����������: ");
			printf("%d", number);
			printf("\n");
			printf("�������������: ");
			guess = numbers[f_index + rand() % p_index];
			printf("%d", guess);
			printf("\n\n");
 			printf("1)>\n2)<\n3)=\n");
			do{
				scanf_s("%d", &guess_p);
				printf("\n");
				if (guess_p == 1)
				{
					p_index = guess;
					++count;
				}
				else if (guess_p == 2)
				{
					f_index = guess;
					++count;
				}
				else
				{

					printf("��������� �������\n");
					printf("��� - �� ������� = ");
					printf("%d", count);
					return 2;
				}
			} while (guess_p != 1 && guess_p != 2 && guess_p != 3);
		}

	};
	return 0;
}