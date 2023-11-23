#include <stdio.h>
#include <conio.h>
#include <windows.h>
   

#define HEIGHT 20
#define WIDTH 20 


int x, y, fruitX, fruitY, score, gameOver;
int tailX[100], tailY[100];
int nTail;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
enum eDirection dir;

void Setup() {
	//Изначальная настройка игры и первоначальное меню
	score = 0;
	char button;
	x = WIDTH / 2;
	y = HEIGHT / 2;
	fruitX = rand() % WIDTH;
	fruitY = rand() % HEIGHT;
	dir = STOP;

	printf("Menu:\n");
	printf("If you want to play game push button p\n");
	printf("If you want to quit push button x\n");

	scanf_s("%c", &button);
	if (button == 'p') {
		gameOver = 0;
	}
	if (button == 'x') {
		gameOver = 1;
	}
	
	
}


void Draw() {
	//Отрисовка границ, змеи и фруктов
	system("cls"); //Очистка консоли находится в windows.h
	for (int i = 0; i < WIDTH + 1 ; i++) {
		printf("#");
	}
	printf("\n");

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH ; j++) {
			if (j == 0 || j == (WIDTH - 1)) {
				printf("#");
			}
			if (i == y && j == x) {
				printf("0");
			}
			if (i == fruitY && j == fruitX) {
				printf("F");
			}
			else {
				int print = 0;
				for (int k = 0; k < nTail; k++) {
					if (tailX[k] == j && tailY[k] == i) {
						print = 1;
						printf("o");
					}
				}
				if (!print) {
					printf(" ");
				}
			}
		}
		printf("\n");
	}

	for (int i = 0; i < WIDTH + 1; i++) {
		printf("#");
	}
	printf("\n");

	printf("score: %d\n", score);
	printf("to quit push x");
}


void Input() {
	//При помощи библеотеки konio.h отслеживаем нажимаемые кнопки. Примечание: змейка двигается только, когда нажимаемые клавишы работают в нижнем регистре. 
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = 1;
			break;
		}
	}
}


void Logic() {
	//Логика игры. Здесь мы программируем движение змеи, увеличение счета, поедание фруктов.
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;

	for (int i = 1; i < nTail; i++) {
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (dir) {
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}

	if (x < 0) {
		x = WIDTH - 1;
	}
	else if (x >= WIDTH -1 ){
		x = 0;
	}
	if (y < 0) {
		y = HEIGHT - 1;
	}
	else if (y >= HEIGHT) {
		y = 0;
	}
	for (int i = 0; i < nTail; i++) {
		if (tailX[i] == x && tailY[i] == y) {
			gameOver = 1;
		}
	}
	if (x == fruitX && y == fruitY) {
		score += 10;
		fruitX = rand() % WIDTH;
		fruitY = rand() % HEIGHT;
		nTail++;
	}
}


int main() {
	//Собираем все вместе 
	Setup();
	while (!gameOver) {
		Draw();
		Input();
		Logic();
		Sleep(30); //Находиться в библеотеке windows.h делает задержку 10 миллисекунд. Добавляет плавности игре 
	}
}