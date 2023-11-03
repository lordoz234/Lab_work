#include <stdio.h>
#include <time.h>

int way(int x, int y, int n, int m, int labirint[n][m], int visited[n][m]) {
  if (x < 0 || y < 0 || x >= n || y >= m || visited[x][y] == 1 || labirint[x][y] == 0) {
    return 0;
  }
  if (x == n - 1 && y == m - 1) {
    visited[x][y] = 1;
    return 1;
  }
  visited[x][y] = 1;
  if (way(x + 1, y, n, m, labirint, visited) || way(x - 1, y, n, m, labirint, visited) || way(x, y+1, n, m, labirint, visited) || way(x, y - 1, n, m, labirint, visited)) {
    return 1;
  }
  visited[x][y] = 0;
  return 0;


}

int main() {
  srand(0);
  int n = rand() % 15,
      m = rand() % 15; // размер лабиринта (число столбцов и сторок)
  if (n < 5) {
    n = 5;
  }
  if (m < 5) {
    m = 5;
  }
  int visited[n][m];
  printf("n = %d m = %d \n", n, m);
  int labirint[n][m];
  for (int i = 0; i < n; i++) { // создание массива
    for (int j = 0; j < m; j++) {
      int point = rand() % 10;
      if (point < 2) {
        labirint[i][j] = 0; // ловушка
      }
      else {
        labirint[i][j] = 1; //можно ходить
      }
      visited[i][j] = 0;
    }
  }

  labirint[0][0] == 1;
  labirint[n-1][m-1] == 1;



  int x = 0, y = 0;
  if (way(x, y, n, m, labirint, visited) == 0) {
    printf("No way");
  }
  else {
    printf("The way excists");
    for (int i = 0; i < n; i++) {
        printf("\n");
        for (int j = 0; j < m; j++) {
            printf("%d ", visited[i][j]);

        }
    }
    printf("\n");
  }
    for (int i = 0; i < n; i++) { // печать массива
    printf("\n");
      for (int j = 0; j < m; j++) {
      printf("%d", labirint[i][j]);
      printf(" ");
    }
  }

}
