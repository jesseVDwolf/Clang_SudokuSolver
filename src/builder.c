#include "builder.h"
#include <stdlib.h>

static void		free_matrix(int **matrix, int nptr)
{
	int	idx;

	idx = 0;
	while (idx < nptr)
	{
		free(matrix[idx]);
		idx++;
	}
	free(matrix);
	return ;
}

static int		*split_line(char *line)
{
	int		*split;
	int		idx;

	split = malloc(SUDOKU_DIM * sizeof(int));
	if (split == NULL)
		return (NULL);
	else
	{
		idx = 0;
		while (idx < SUDOKU_DIM)
		{
			split[idx] = (line[idx] == '.') ? 0 : (line[idx] - '0');
			idx++;
		}
	}
	return (split);
}

int				**build_matrix(char **lines)
{
	int		**matrix;
	int		idx;

	matrix = malloc(SUDOKU_DIM * sizeof(int*));
	if (matrix == NULL)
		return (NULL);
	else
	{
		idx = 0;
		while (idx < SUDOKU_DIM)
		{
			matrix[idx] = split_line(lines[idx]);
			if (matrix[idx] == NULL)
			{
				free_matrix(matrix, (idx + 1));
				return (NULL);
			}
			idx++;
		}
	}
	return (matrix);
}
