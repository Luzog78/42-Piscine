/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 06:26:20 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/12 06:26:25 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n);
void	ft_increment_last(int n, char nums[9], int index);
int		ft_check(int n, char nums[9]);
void	ft_print_nums(int n, char nums[9], int *print);

void	ft_print_combn(int n)
{
	int		print;
	int		cursor;
	char	nums[9];

	print = 0;
	cursor = 0;
	while (cursor < 9)
	{
		nums[cursor] = '0' + cursor;
		cursor++;
	}
	while (nums[0] <= '9' - n + 1)
	{
		if (ft_check(n, nums))
			ft_print_nums(n, nums, &print);
		ft_increment_last(n, nums, n - 1);
	}
}

void	ft_increment_last(int n, char nums[9], int index)
{
	if (nums[index] >= '9' && index > 0)
	{
		nums[index] = '0';
		ft_increment_last(n, nums, index - 1);
	}
	else
		nums[index]++;
}

int	ft_check(int n, char nums[9])
{
	int	i;

	i = 1;
	while (i < n)
	{
		if (nums[i] <= nums[i - 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_print_nums(int n, char nums[9], int *print)
{
	int	i;

	if (!*print)
		*print = 1;
	else
		write(1, ", ", 2);
	i = 0;
	while (i < n)
		write(1, &(char){nums[i++]}, 1);
}
