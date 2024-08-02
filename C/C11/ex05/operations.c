/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:09:22 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/26 10:09:23 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr(int n);
void	ft_putstr(char *str);

void	add(int a, int b)
{
	ft_putnbr(a + b);
}

void	sub(int a, int b)
{
	ft_putnbr(a - b);
}

void	mul(int a, int b)
{
	ft_putnbr(a * b);
}

void	div(int a, int b)
{
	if (b == 0)
		ft_putstr("Stop : division by zero");
	else
		ft_putnbr(a / b);
}

void	mod(int a, int b)
{
	if (b == 0)
		ft_putstr("Stop : modulo by zero");
	else
		ft_putnbr(a % b);
}
