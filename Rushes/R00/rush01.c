/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:41:52 by vtruflan          #+#    #+#             */
/*   Updated: 2023/07/16 13:43:15 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_tab(int cur_x, int cur_y, int x, int y)
{
	while (++cur_x < x)
	{
		if (cur_y == 0 || cur_y == y - 1)
			if (cur_x == 0 && cur_y == 0)
				ft_putchar('/');
		else if (cur_x == x - 1 && cur_y == 0)
			ft_putchar('\\');
		else if (cur_x == 0 && cur_y == y - 1)
			ft_putchar('\\');
		else if (cur_x == x - 1 && cur_y == y - 1)
			ft_putchar('/');
		else
			ft_putchar('*');
		else if (cur_x == 0 || cur_x == x - 1)
			ft_putchar('*');
		else
			ft_putchar(' ');
		if (cur_x == x - 1)
			ft_putchar('\n');
	}
}

void	rush(int x, int y)
{
	int	cur_x;
	int	cur_y;

	cur_y = -1;
	while (++cur_y < y)
	{
		cur_x = -1;
		print_tab(cur_x, cur_y, x, y);
	}
}
