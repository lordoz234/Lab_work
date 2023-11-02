#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int f(int x, int y, int n, int m, int maze[n][m]){

    if ((x == m-1) && (y == n-1)){
        return 1;
    }

    if ((x < 0) || (y < 0) || (x >= m) || (y >= n)){
        return 0;
    }

    if (maze[y][x] == 0){
        return 0;
    }
    
    if (maze[y][x] == 1){
        return f(x+1, y, n, m, maze)+f(x, y+1, n, m, maze)+f(x-1, y, n, m, maze)+f(x, y-1, n, m, maze);
    }
}

void main(){
    int n = 5, m = 5;
    int k = 0;
    int maze[n][m];
    int temp;

    srand(time(NULL));
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            temp = rand() % 10;
            if (temp < 2){
                maze[i][j] = 0;
            }
            else{
                maze[i][j] = 1;
            }
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

    if (f(0, 0, n, m, maze) >= 1){
        printf("There is a way out!");
    }
    else{
        printf("You are stuck here forever and ever and ever!");
    }

}
