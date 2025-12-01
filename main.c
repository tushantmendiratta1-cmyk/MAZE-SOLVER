#include <stdio.h>
#include <string.h>
#include "maze.h"

int dfs(int row, int col, int visited[N][N], char maze[N][N],
        char solution[N][N], int endRow, int endCol);

int bfs(int row, int col, int endRow, int endCol,
        char maze[N][N], char solution[N][N]);

int main() {

    char maze[N][N] = {
        {'S','0','1','0','0'},
        {'1','0','1','0','1'},
        {'0','0','0','0','0'},
        {'1','1','1','1','0'},
        {'0','0','0','0','E'}
    };

    int startRow, startCol, endRow, endCol;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (maze[i][j] == 'S') {
                startRow = i;
                startCol = j;
            }
            if (maze[i][j] == 'E') {
                endRow = i;
                endCol = j;
            }
        }
    }

    printf("Original Maze:\n");
    printMaze(maze);

    int visitedDFS[N][N] = {0};
    char dfsSolution[N][N];
    memcpy(dfsSolution, maze, sizeof(maze));

    if (dfs(startRow, startCol, visitedDFS, maze, dfsSolution, endRow, endCol)) {
        printf("\nDFS Path Found:\n");
        printMaze(dfsSolution);
    } else {
        printf("\nNo DFS path found.\n");
    }

    char bfsSolution[N][N];
    memcpy(bfsSolution, maze, sizeof(maze));

    if (bfs(startRow, startCol, endRow, endCol, maze, bfsSolution)) {
        printf("\nBFS Shortest Path Found:\n");
        printMaze(bfsSolution);
    } else {
        printf("\nNo BFS path found.\n");
    }

    return 0;
}