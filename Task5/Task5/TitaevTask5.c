# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <locale.h>
int main() {
	setlocale(LC_ALL, "RU");
	int products[9] = { 1001, 2002, 3003, 4004, 5005, 6006, 7007, 8008, 9009 };
	printf("Штрих код товаров: "); printf("футболка - "); printf("%d", products[0]); printf("\n");
	printf("Штрих код товаров: "); printf("кепка - "); printf("%d", products[1]); printf("\n");
	printf("Штрих код товаров: "); printf("шапка - "); printf("%d", products[2]); printf("\n");
	printf("Штрих код товаров: "); printf("куртка - "); printf("%d", products[3]); printf("\n");
	printf("Штрих код товаров: "); printf("ветровка - "); printf("%d", products[4]); printf("\n");
	printf("Штрих код товаров: "); printf("свитшот - "); printf("%d", products[5]); printf("\n");
	printf("Штрих код товаров: "); printf("спортивные штаны - "); printf("%d", products[6]); printf("\n");
	printf("Штрих код товаров: "); printf("джинсы - "); printf("%d", products[7]); printf("\n");
	printf("Штрих код товаров: "); printf("обувь - "); printf("%d", products[8]); printf("\n");
	// сканирование штрих кода
	int price[9] = { 700, 400, 500, 10000, 6000, 4000, 5500, 7000, 9900 };
	char array[][9] = { "t_shirt", "cap", "hat", "jacket", "kyrtka", "sweatshot", "sportpant", "jeans","shoes" };
	int basket[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int q = 1;
	int shtr = 0;
	int kol_tov = 0;
	while (q != 0) {
		printf("Введите штрих код товара ");
		scanf_s("%d", &shtr);
		kol_tov++;
		int i = 0;
		while (products[i] != shtr) {
			i++;
		}
		i++;
		basket[i] = +1;
		printf("Если вы хотите положить в корзину что-то еще, впишите 1 ");
		scanf_s("%d", &q);
	};
	for (int i = 0; i < 10; i++) {
		if (i == 0) {
			printf("ВАШ ИТОГОВЫЙ ЧЕК ЛИСТ.");
		};
		if (basket[i] != 0) {
			int sale = 0;
			float p = price[i] * basket[i];
			printf("\n"); printf(products[i]); printf(" товар с названием: "); printf(array[i]); printf(" В количестве: "); printf(basket[i]);
		};

	};
	int sale = 0;
	printf("Введите размер скидки ");
	scanf_s("%d", &sale);
	float p = (basket[1] * price[1] + basket[2] * price[2] + basket[3] * price[3] + basket[4] * price[4] + basket[5] * price[5] + basket[6] * price[6] + basket[7] * price[7] + basket[8] * price[8] + basket[9] * price[9] + basket[0] * price[0]) * (1 - (sale / 100));
	printf(" Итоговая сумма товара в вашем чеке составляет: "); printf("%d", p);
	return 0;
}