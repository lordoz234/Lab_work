#include <stdio.h>
#include <stdlib.h>

#define ARG 50

int maze[ARG][ARG];
int visited[ARG][ARG];
int path[ARG][ARG];
int n, m;

int valid(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 1 && visited[x][y] == 0) {
        return 1;
    }
    return 0;
}
int find_path(int x, int y) {
    if (x == n - 1 && y == m - 1) {
        path[x][y] = 1;
        return 1;
    }
    if (valid(x, y)) {
        visited[x][y] = 1;
        path[x][y] = 1;
        
        if (find_path(x + 1, y) || find_path(x, y + 1)) {
            return 1;
        }
        
        path[x][y] = 0;
    }
    return 0;
}

int main() {
    printf("enter n: ");
    scanf("%d", &n);
    
    printf("enter m: ");
    scanf("%d", &m);
    
    printf("enter the maze (0 - trap, 1 - walkable):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &maze[i][j]);
        }
    }
    if (find_path(0, 0)) {
        printf("path found!\n");
        printf("path is:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%d ", path[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("path not found!\n");
    }
    return 0;
}
