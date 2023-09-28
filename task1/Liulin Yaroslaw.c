#include <stdio.h>
#include <math.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Rus");
	int x1, y1, x2, y2, razny, raznx;
	scanf_s("%d %d %d %d", &x1, &y1, &x2, &y2);
	razny = y2 - y1;
	raznx = x2 - x1;

	if ((x1 == x2 && y1 != y2) || (y1 == y2 && x1 != x2))
	{
		printf("Ладья +\n");
	}
	else
	{
		printf("Ладья -\n");
	}
	if (pow(razny, 2) == pow(raznx, 2))
	{
		printf("Слон +\n");
	}
	else
	{
		printf("Слон -\n");
	}
	if ((x1 == x2 && y1 != y2) || (y1 == y2 && x1 != x2) || pow(razny, 2) == pow(raznx, 2))
	{
		printf("Ферзь +\n");
	}
	else
	{
		printf("Ферзь -\n");
	}
	if (pow(raznx, 2) <= 1 && pow(razny, 2) <= 1)
	{
		printf("Король +\n");
	}
	else
	{
		printf("Король -\n");
	}
	if (pow(raznx, 2) + pow(razny, 2) == 5)
	{
		
		printf("Конь +\n");
	}
	else
	{
		printf("Конь -\n");
	}
	return 0;
}