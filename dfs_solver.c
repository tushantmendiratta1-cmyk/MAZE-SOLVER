#include "maze.h"

int dfs(int row, int col, int visited[N][N], char maze[N][N],
        char solution[N][N], int endRow, int endCol)
{
    if (row == endRow && col == endCol) {
        solution[row][col] = 'D';  // Mark destination
        return 1;
    }

    visited[row][col] = 1;
    solution[row][col] = 'D';      // Mark current path

    for (int d = 0; d < 4; d++) {
        int nr = row + dr[d];
        int nc = col + dc[d];

        if (isValid(nr, nc, visited, maze)) {
            if (dfs(nr, nc, visited, maze, solution, endRow, endCol)) {
                return 1;  // Path found
            }
        }
    }

    solution[row][col] = maze[row][col];  // Backtrack
    return 0;
}
