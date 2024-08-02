/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 07:07:15 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/21 05:58:16 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_ten_queens_puzzle(void);
void	ft_recursion(int *solutions, int *cols, int index);
void	ft_reset_following(int *cols, int starting_index);
int		ft_is_aligned(int *cols, int col, int row);
int		ft_abs(int n);

int	ft_ten_queens_puzzle(void)
{
	int	solutions;
	int	cols[10];

	solutions = 0;
	ft_reset_following(cols, 0);
	ft_recursion(&solutions, cols, 0);
	return (solutions);
}

void	ft_recursion(int *solutions, int *cols, int index)
{
	int	choice;

	choice = 0;
	while (choice < 10)
	{
		ft_reset_following(cols, index);
		if (!ft_is_aligned(cols, index, choice))
		{
			cols[index] = choice;
			if (index >= 9)
			{
				*solutions += 1;
				index = -1;
				while (++index < 10)
					write(1, &(char){cols[index] + '0'}, 1);
				write(1, "\n", 1);
			}
			else
			{
				ft_recursion(solutions, cols, index + 1);
			}
		}
		choice++;
	}
}

void	ft_reset_following(int *cols, int starting_index)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (i >= starting_index)
			cols[i] = -1;
		i++;
	}
}

int	ft_is_aligned(int *cols, int col, int row)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (cols[i] != -1 && (cols[i] == row
				|| ft_abs(i - col) == ft_abs(cols[i] - row)))
			return (1);
		i++;
	}
	return (0);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
