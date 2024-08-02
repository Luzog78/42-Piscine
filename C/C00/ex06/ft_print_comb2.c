/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 06:26:20 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/12 06:26:25 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);
void	ft_print_nums(int nums[2], int *print);
void	ft_putnbr(int n);

void	ft_print_comb2(void)
{
	int	print;
	int	nums[2];

	print = 0;
	nums[0] = 0;
	while (nums[0] <= 98)
	{
		nums[1] = nums[0] + 1;
		while (nums[1] <= 99)
		{
			ft_print_nums(nums, &print);
			nums[1]++;
		}
		nums[0]++;
	}
}

void	ft_print_nums(int nums[2], int *print)
{
	if (!*print)
		*print = 1;
	else
		write(1, ", ", 2);
	if (nums[0] < 10)
		write(1, "0", 1);
	ft_putnbr(nums[0]);
	write(1, " ", 1);
	if (nums[1] < 10)
		write(1, "0", 1);
	ft_putnbr(nums[1]);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-n);
	}
	else if (n < 10)
	{
		c = n + 48;
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}
