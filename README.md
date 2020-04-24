# Clang_SudokuSolver

This project is part of a small series of small programs that help me explore the C language. It is
based on the [Rush01 assignment](https://github.com/MrRobb/42_piscine/blob/master/rush01/colle01.en.pdf) provided by the 42 network.

## Installation

The makefile provides some generic functionality. The following
make targets are available. Just running *make* will execute the *all* target.
```bash
make
make all
make sudokusolver
make clean
make fclean
make re
```

## Usage

the sudokusolver program can only solve 9x9 sudokus which have to be inputted line
by line as arguments to the program. Here is an example:
```bash
./sudokusolver "9...7...." "2...9..53" ".6..124.." "84...1.9." "5.....8.." ".31..4..." "..37..68." ".9..5.741" "47......."
```
The solved sudoku is then printed to STDOUT:
```
[9][1][4][3][7][5][2][6][8]
[2][8][7][4][9][6][1][5][3]
[3][6][5][8][1][2][4][7][9]
[8][4][6][5][2][1][3][9][7]
[5][2][9][6][3][7][8][1][4]
[7][3][1][9][8][4][5][2][6]
[1][5][3][7][4][9][6][8][2]
[6][9][8][2][5][3][7][4][1]
[4][7][2][1][6][8][9][3][5]
```