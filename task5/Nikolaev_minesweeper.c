#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int x = 8;
int y = 8;
int bombs = 10;

bool outBounds(int pos1, int pos2) {
    return (pos1 < 0) || (pos2 < 0) || (pos1 >= x) || (pos2 >= y);
}

void printBoard(int visible_board[x][y]){
    printf("\033[0d\033[2J"); // clear screen
    printf("Current board: \n");
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            if (visible_board[i][j] == -1){
                printf("x "); // hidden cell
            }
            else if(visible_board[i][j] == 0){
                printf("o ");
            }
            else {
                printf("%d ", visible_board[i][j]);
            }
        }
        printf("\n");
    }
}

int mine_count(int pos1, int pos2, int x, int y, int mines[x][y]) {
    if (outBounds(pos1, pos2)) {
        return 0;
    }

    int count = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (outBounds(pos1 + i, pos2 + j)) continue;
            count += mines[pos1 + i][pos2 + j];
        }
    }
    return count;
}

void reveal(int row, int col, int mines[x][y], int visible_board[x][y]){
    if (outBounds(row, col) || visible_board[row][col] != -1){
        return; // the cell is already open or out of bounds
    }

    if (mines[row][col] == 1){
        printf("You've hit a bomb! Game over. \n");
        exit(0);
    }

    int count = mine_count(row, col, x, y, mines);
    visible_board[row][col] = count;

    if (count == 0){ // opening neighbouring cells if the cell itself is empty
        for (int i = -1; i <= 1; i++){
            for (int j = -1; j <= 1; j++){
                reveal(row + i, col + j, mines, visible_board);
            }
        }
    }

}

int main() {
    int mines[x][y];
    int visible_board[x][y];

    srand(time(NULL));

    // create minefield and visible board
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            mines[i][j] = 0;
            visible_board[i][j] = -1; // -1 are hidden cells
        }
    }

    int bomb_count = 0;
    while (bomb_count != bombs){
        int buffx = rand() % x;
        int buffy = rand() % y;
        if (mines[buffx][buffy] == 0){
            mines[buffx][buffy] = 1;
            bomb_count++;
        }
    }

    int row, col;
    
    while (1){
        printBoard(visible_board);

        printf("Enter row and column from 0 to 7 (e.g. 0 1): ");
        label:
        scanf("%d %d", &row, &col);

        if (outBounds(row,col) || visible_board[row][col] != -1){
            printf("Invalid move. Try again.\n");
            goto label;
        }

        reveal(row, col, mines, visible_board);

        // check winning condition
        int countHidden = 0;
        for (int i = 0; i <= x; i++){
            for (int j = 0; j <= y; j++){
                if (visible_board[i][j] == -1){
                    countHidden++;
                }
            }
        }

        if (countHidden == bombs) {
            printBoard(visible_board);
            printf("Congrats! You won.");
            break;
        }
    }
    
    return 0;
}