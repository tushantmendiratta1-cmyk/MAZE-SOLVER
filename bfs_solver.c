#include <stdlib.h>
#include <string.h>
#include "maze.h"

struct Node {
    int row, col;
    struct Node *next;
};

struct Queue {
    struct Node *front, *rear;
};

struct Node* createNode(int row, int col) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = row;
    newNode->col = col;
    newNode->next = NULL;
    return newNode;
}

void initQueue(struct Queue *q) {
    q->front = q->rear = NULL;
}

int isEmpty(struct Queue *q) {
    return q->front == NULL;
}

void enqueue(struct Queue *q, int row, int col) {
    struct Node *newNode = createNode(row, col);
    if (!q->rear) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

struct Node* dequeue(struct Queue *q) {
    if (isEmpty(q)) return NULL;
    struct Node *temp = q->front;
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    return temp;
}

int bfs(int startRow, int startCol, int endRow, int endCol,
        char maze[N][N], char solution[N][N])
{
    int visited[N][N] = {0};
    int parent[N][N][2];
    memset(parent, -1, sizeof(parent));

    struct Queue q;
    initQueue(&q);

    enqueue(&q, startRow, startCol);
    visited[startRow][startCol] = 1;

    int found = 0;

    while (!isEmpty(&q)) {
        struct Node* curr = dequeue(&q);
        int row = curr->row;
        int col = curr->col;
        free(curr);

        if (row == endRow && col == endCol) {
            found = 1;
            break;
        }

        for (int d = 0; d < 4; d++) {
            int nr = row + dr[d];
            int nc = col + dc[d];

            if (isValid(nr, nc, visited, maze)) {
                enqueue(&q, nr, nc);
                visited[nr][nc] = 1;
                parent[nr][nc][0] = row;
                parent[nr][nc][1] = col;
            }
        }
    }

    if (found) {
        int r = endRow, c = endCol;
        while (r != -1 && c != -1) {
            solution[r][c] = 'B';  // Mark BFS path
            int pr = parent[r][c][0];
            int pc = parent[r][c][1];
            r = pr; 
            c = pc;
        }
        return 1;
    }

    return 0;
}