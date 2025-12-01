#include <stdio.h>
#include "maze.h"

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void printMaze(char maze[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int isValid(int row, int col, int visited[N][N], char maze[N][N]) {
    return (row >= 0 && row < N &&
            col >= 0 && col < N &&
            !visited[row][col] &&
            maze[row][col] != '1');
}