#include <stdio.h>

int check(int** field, int** road, int x, int y, int x_s, int y_s)
{
	if (x < 0 || x >= x_s || y < 0 || y >= y_s || field[x][y] == 0 || road[x][y] == 1)
	{
		return 0;
	}
	road[x][y] = 1;
	if (x == 0 && y == y_s - 1)
	{
		return 1;
	}
	if (check(field, road, x + 1, y, x_s, y_s) || check(field, road, x - 1, y, x_s, y_s) || check(field, road, x, y + 1, x_s, y_s) || check(field, road, x, y - 1, x_s, y_s))
	{
		return 1;
	}
	road[x][y] = 0;
	return 0;
}

void main()
{
	printf("Enter field size\n");
	int x_s, y_s;
	scanf_s("%d%d", &x_s, &y_s);
	int** field = malloc(x_s * sizeof(int*));
	for (int i = 0; i < x_s; i++) 
	{
		field[i] = malloc(y_s * sizeof(int));
	}
	
	printf("Filling out the field \n");
	printf("0 - trap, 1 - free field\n");
	for (int i = 0; i < x_s; i++)
	{
		for (int j = 0; j < y_s; j++)
		{
			scanf_s("%d", &field[i][j]);
		}
	}
	field[x_s - 1][0] = 1;
	field[0][y_s - 1] = 1;

	int** road = malloc(x_s * sizeof(int*));
	for (int i = 0; i < x_s; i++)
	{
		road[i] = malloc(y_s * sizeof(int));
	};

	if (check(field, road, x_s - 1, 0, x_s, y_s)) 
	{
		printf("The road has been found\n");
		for (int i = 0; i < x_s; i++) 
		{
			for (int j = 0; j < y_s; j++) 
			{
				if (road[i][j] != 1) 
				{
					road[i][j] = 0;
				}
			}
		}
		for (int i = 0; i < x_s; i++) 
		{
			for (int j = 0; j < y_s; j++) 
			{
				printf("%d ", road[i][j]);
			}
			printf("\n");
		}
	}
	else 
	{
		printf("There is no road\n");
	}
}
