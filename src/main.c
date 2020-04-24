#include <unistd.h>
#include <stdbool.h>
#include "builder.h"
#include "solver.h"

void			print_cell(int num)
{
	char	digit;

	digit = (num + '0');
	write(1, "[", 2);
	write(1, &digit, 1);
	write(1, "]", 2);
	return ;
}

int				main(int argc, char **argv)
{
	int		**sudoku;
	int		idx;
	int		i;

	if (argc != 10)
		write(1, "Error", 6);
	else
	{
		sudoku = build_matrix(argv + 1);
		if (sudoku == NULL)
			write(1, "Error", 6);
		if (!solve_sudoku(sudoku, 0, 0))
			write(1, "Error", 6);
		else
		{
			idx = 0;
			while (idx < SUDOKU_DIM)
			{
				i = 0;
				while (i < SUDOKU_DIM)
				{
					print_cell(sudoku[idx][i]);
					i++;
				}
				write(1, "\n", 2);
				idx++;
			}
		}
	}
	return (0);
}
