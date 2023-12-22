#include <SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#define MAX_LEN 100 //максимальная длина змеи
#define SCREEN_HEIGHT 480
#define SCREEN_WIDTH 640
#define CELL_SIZE 20 //размер сегмента змеи
#define FOOD_SIZE 20
#define MAX_LEN 100

//структура координат
struct coord {
	int x;
	int y;
};
// структура змеи
struct Snake {
	struct coord body[MAX_LEN]; // массив с координатами тела змеи
	int length; // длина змеи
	int move; // направление змеи 
};

//структура еды
struct Food {
	struct coord pos; // координаты еды
};

//инициализация начального положения змеи
void init_snake(struct Snake* snake) {
	//начальная длина и движение вправо при старте
	snake->length = 1;
	snake->move = 1;

	//установка начального положения змеи
	snake->body[0].x = SCREEN_WIDTH / 2;
	snake->body[0].y = SCREEN_HEIGHT / 2;

}


//инициализация начального положения еды
void init_food(struct Food* food) {
	food->pos.x = rand() % (SCREEN_WIDTH / FOOD_SIZE) * FOOD_SIZE;
	food->pos.y = rand() % (SCREEN_HEIGHT / FOOD_SIZE) * FOOD_SIZE;
}

//обработка клавиш,котрые нажимает пользователь
void moving(struct Snake* snake) {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			exit(0); // Выход из программы при закрытии окна
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_UP:
				if (snake->move != 2) {
					snake->move = 0;
				}
				break;
			case SDLK_RIGHT:
				if (snake->move != 3) {
					snake->move = 1;
				}
				break;
			case SDLK_DOWN:
				if (snake->move != 0) {
					snake->move = 2;
				}
				break;
			case SDLK_LEFT:
				if (snake->move != 1) {
					snake->move = 3;
				}
				break;
			}
			break;
		}
	}
}
//обновление положения змеи
void upd_snake(struct Snake* snake, struct Food* food) {
	struct coord prevHead = snake->body[0];
	struct coord newHead = prevHead;

	// Обновление положения головы змеи
	switch (snake->move) {
	case 0:
		newHead.y -= CELL_SIZE;
		break;
	case 1:
		newHead.x += CELL_SIZE;
		break;
	case 2:
		newHead.y += CELL_SIZE;
		break;
	case 3:
		newHead.x -= CELL_SIZE;
		break;
	}

	// Перемещение тела змеи
	for (int i = snake->length - 1; i > 0; i--) {
		snake->body[i] = snake->body[i - 1];
	}

	// Установка новой головы
	snake->body[0] = newHead;

	// Проверка столкновения с границами экрана
	if (newHead.x < 0 || newHead.x >= SCREEN_WIDTH || newHead.y < 0 || newHead.y >= SCREEN_HEIGHT) {
		exit(0); // Завершение программы при столкновении с границами
	}

	// Проверка столкновения с самой собой
	for (int i = 1; i < snake->length; i++) {
		if (newHead.x == snake->body[i].x && newHead.y == snake->body[i].y) {
			exit(0); // Завершение программы при столкновении с самой собой
		}
	}

	// Проверка поедания еды
	if (newHead.x == food->pos.x && newHead.y == food->pos.y) {
		snake->length++;
		init_food(food);
	}


}

//отображение змеи
void create_snake(SDL_Renderer* renderer, struct Snake* snake) {
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	for (int i = 0; i < snake->length; i++) {
		SDL_Rect rect = { snake->body[i].x, snake->body[i].y, CELL_SIZE, CELL_SIZE };
		SDL_RenderFillRect(renderer, &rect);
	}
}

//отображение еды
void create_food(SDL_Renderer* renderer, struct Food* food) {
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_Rect rect = { food->pos.x, food->pos.y, FOOD_SIZE, FOOD_SIZE };
	SDL_RenderFillRect(renderer, &rect);
}

//отображение игрового поля
void create_window(SDL_Renderer* renderer, struct Snake* snake, struct Food* food) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 153, 255);
	SDL_RenderClear(renderer);

	create_snake(renderer, snake);
	create_food(renderer, food);

	SDL_RenderPresent(renderer);
}

int main() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "SDL_Init failed:%s\n", SDL_GetError());
		return -1;
	}
	//создание окна
	SDL_Window* window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!window) {
		fprintf(stderr, "Window creation failed:%s\n", SDL_GetError());
		return -1;
	}

	//Создание рендерера
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		fprintf(stderr, "Renderer failed:%s\n", SDL_GetError());
		return -1;
	}

	//Инициализаци змеи и еды
	struct Snake snake;
	struct Food food;
	init_snake(&snake);
	init_food(&food);

	//инициализация генератора рандомных чисел
	srand(time(NULL));
	//игровой цикл
	while (1) {
		//обработка ввода пользователя
		moving(&snake);

		//обновление положения змеи
		upd_snake(&snake, &food);

		//отображение игрового поля
		create_window(renderer, &snake, &food);


		SDL_Delay(300);


	}
	//освобождение памяти
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;


}