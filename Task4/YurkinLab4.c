#include <stdio.h>
#include<stdlib.h>

int check(int** field, int** road, int x, int y, int z, int b)
{
	if (x < 0 || x >= z || y < 0 || y >= b || field[x][y] == 0 || road[x][y] == 1)
	{
		return 0;
	}
	road[x][y] = 1;
	if (x == 0 && y == b - 1)
	{
		return 1;
	}
	if (check(field, road, x + 1, y, z, b) || check(field, road, x - 1, y, z, b) || check(field, road, x, y + 1, z, b) || check(field, road, x, y - 1, z, b))
	{
		return 1;
	}
	road[x][y] = 0;
	return 0;
}

void main()
{
	printf("razmer polya");
	int z, b;
	scanf("%d%d", &z, &b);
	int** field = malloc(z * sizeof(int*));
	for (int i = 0; i < z; i++)
	{
		field[i] = malloc(b * sizeof(int));
	}

	printf("Zapolnite pole \n");
	printf("0 - lovuska, 1 - put\n");
	for (int i = 0; i < z; i++)
	{
		for (int j = 0; j < b; j++)
		{
			scanf("%d", &field[i][j]);
		}
	}
	field[z - 1][0] = 1;
	field[0][b - 1] = 1;

	int** road = malloc(z * sizeof(int*));
	for (int i = 0; i < z; i++)
	{
		road[i] = malloc(b * sizeof(int));
	};

	if (check(field, road, z - 1, 0, z, b))
	{
		printf("Put est");
		for (int i = 0; i < z; i++)
		{
			for (int j = 0; j < b; j++)
			{
				if (road[i][j] != 1)
				{
					road[i][j] = 0;
				}
			}
		}
		for (int i = 0; i < z; i++)
		{
			for (int j = 0; j < b; j++)
			{
				printf("%d ", road[i][j]);
			}
			printf("\n");
		}
	}
	else
	{
		printf("Net puti");
	}
}
