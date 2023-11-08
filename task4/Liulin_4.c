#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int maze[MAX_SIZE][MAX_SIZE];
int way[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
int n, m;



int is_valid(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 1 && visited[x][y] == 0) {
        return 1;
    }
    return 0;
}

int find_path(int x, int y) {
    if (x == n - 1 && y == m - 1) {
        way[x][y] = 1;
        return 1; 
    }

    if (is_valid(x, y)) {
        visited[x][y] = 1; 
        way[x][y] = 1;

        
        if (find_path(x + 1, y)) {
            way[x][y] = 1;
            return 1; 
            
        }
        if (find_path(x, y + 1)) {
            way[x][y] = 1;
            return 1; 
        }
        if (find_path(x - 1, y)) {
            way[x][y] = 1;
            return 1; 
        }
        if (find_path(x, y - 1)) {
            way[x][y] = 1;
            return 1;
        }

        visited[x][y] = 0; 
    }

    return 0;
}
int main() {
    printf("Input width of maze\n");
    scanf_s("%d", &n);
    printf("Input height of maze\n");
    scanf_s("%d", &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%d", &maze[i][j]);
        }
    }

    printf("Your maze is\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", maze[i][j]);
        }
    printf("\n");
    }

    printf("\n");

    if (find_path(0, 0)) {
        printf("Way is found!\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%d ", way[i][j]);
            }
            printf("\n");
        }
    }
    else {
        printf("Way is not found!\n");
    }

    

    return 0;
}