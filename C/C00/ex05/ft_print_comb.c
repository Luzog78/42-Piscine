/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 06:26:20 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/12 06:26:25 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);
void	ft_print_nums(char c[3], int *print);

void	ft_print_comb(void)
{
	int		print;
	char	c[3];

	print = 0;
	c[0] = '0';
	while (c[0] <= '9')
	{
		c[1] = '0';
		while (c[1] <= '9')
		{
			c[2] = '0';
			while (c[2] <= '9')
			{
				if (c[0] < c[1] && c[1] < c[2])
					ft_print_nums(c, &print);
				c[2]++;
			}
			c[1]++;
		}
		c[0]++;
	}
}

void	ft_print_nums(char c[3], int *print)
{
	if (!*print)
		*print = 1;
	else
		write(1, ", ", 2);
	write(1, &c[0], 1);
	write(1, &c[1], 1);
	write(1, &c[2], 1);
}
