#include <stdbool.h>
#include "builder.h"

static bool	is_valid(int num, int **sudoku, int row, int col)
{
	int	idx;
	int	sector_row;
	int	sector_col;

	idx = 0;
	while (idx < SUDOKU_DIM)
	{
		if (sudoku[row][idx] == num)
			return (false);
		if (sudoku[idx][col] == num)
			return (false);
		idx++;
	}
	sector_row = 3 * (row / 3);
	sector_col = 3 * (col / 3);
	if (sudoku[((row + 2) % 3) + sector_row][((col + 2) % 3) + sector_col] == num)
		return (false);
	if (sudoku[((row + 4) % 3) + sector_row][((col + 2) % 3) + sector_col] == num)
		return (false);
	if (sudoku[((row + 2) % 3) + sector_row][((col + 4) % 3) + sector_col] == num)
		return (false);
	if (sudoku[((row + 4) % 3) + sector_row][((col + 4) % 3) + sector_col] == num)
		return (false);
	return (true);
}

bool		solve_sudoku(int **sudoku, int row, int col)
{
	int	nextnum;

	if (row == 9)
		return (true);
	if (sudoku[row][col] > 0)
	{
		if (col == 8)
		{
			if (solve_sudoku(sudoku, row + 1, 0))
				return (true);
		}
		else
		{
			if (solve_sudoku(sudoku, row, col + 1))
				return (true);
		}
		return (false);
	}
	nextnum = 1;
	while (nextnum < 10)
	{
		if (is_valid(nextnum, sudoku, row, col))
		{
			sudoku[row][col] = nextnum;
			if (col == 8)
			{
				if (solve_sudoku(sudoku, row + 1, 0))
					return (true);
			}
			else
			{
				if (solve_sudoku(sudoku, row, col + 1))
					return (true);
			}
			sudoku[row][col] = 0;
		}
		nextnum++;
	}
	return (false);
}
