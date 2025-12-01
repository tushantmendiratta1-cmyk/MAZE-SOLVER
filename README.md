# Maze Solver Project (DFS & BFS)

This project demonstrates the implementation of two classical graph traversal algorithms to solve a maze:

- **Depth First Search (DFS)** – finds any valid path.
- **Breadth First Search (BFS)** – finds the shortest path in an unweighted maze.

The maze is represented using a 2D matrix where:
- `S` = Start
- `E` = End/Goal
- `0` = Free path
- `1` = Wall/Obstacle

 Files Included

- `maze.h` – Header file containing declarations and constants
- `utils.c` – Common utility functions (validation, printing)
- `dfs_solver.c` – DFS implementation
- `bfs_solver.c` – BFS implementation with parent tracking
- `main.c` – Main driver code to run both solvers
- `PBLreport.pdf` – The project report 


## ⚙️ How to Compile & Run (GCC)

Run the following commands:
gcc main.c utils.c dfs_solver.c bfs_solver.c -o maze
./maze


## Output

The program prints:
- Original maze  
- DFS path (marked with `D`)
- BFS shortest path (marked with `B`)

## Project Summary

This project was created as part of the **Design and Analysis of Algorithms (DAA) PBL** and demonstrates concepts such as:

- Recursion  
- Queue-based traversal  
- Graph search  
- Time & space complexity  
- Divide & Conquer  
- Path reconstruction  

## Author

*Tushant*  
*CSE/ DFCS/1/23/SET/BCS/521.*