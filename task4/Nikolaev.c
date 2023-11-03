#include <stdio.h>
#include <time.h>
#include <stdlib.h>



int f(int x, int y, int n, int m, int maze[n][m], int visited[n][m]){

    if ((x == m-1) && (y == n-1)){
        visited[y][x] = 1;
        return 1;
    }

    if ((x < 0) || (y < 0) || (x >= m) || (y >= n)){
        return 0;
    }

    if (visited[y][x] == 1){
        return 0;
    }

    if (maze[y][x] == 0){
        return 0;
    }

    if (maze[y][x] == 1){
        visited[y][x] = 1;
        if (f(x+1, y, n, m, maze, visited) || f(x, y+1, n, m, maze, visited) || f(x-1, y, n, m, maze, visited) || f(x, y-1, n, m, maze, visited)) return 1;
    }

    visited[y][x] = 0;
    return 0;
}

void main(){
    int n = 7, m = 7;
    int k = 0;
    int maze[n][m];
    int temp;
    int visited[n][m];

    srand(time(NULL));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            temp = rand() % 10;
            if (temp < 3){
                maze[i][j] = 0;
            }
            else{
                maze[i][j] = 1;
            }
            visited[i][j] = 0;
        }
    }
    maze[0][0] = 1;
    maze[n-1][m-1] = 1;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    if (f(0, 0, n, m, maze, visited) >= 1){
        printf("There is a way out!\n");
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                printf("%d ", visited[i][j]);
            }
            printf("\n");
        }
    }
    else{
        printf("You are stuck here forever and ever and ever!");
    }

}
