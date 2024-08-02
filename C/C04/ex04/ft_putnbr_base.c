/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:27:51 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/19 10:38:22 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);
int		ft_check_errors(char *base);

void	ft_putnbr_base(int nbr, char *base)
{
	long long	n;
	long long	len;

	n = (long long) nbr;
	len = 0;
	while (base[len])
		len++;
	if (len < 2 || !ft_check_errors(base))
		return ;
	else if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= len)
		ft_putnbr_base(n / len, base);
	write(1, base + (n % len), 1);
}

int	ft_check_errors(char *base)
{
	int		i;

	while (*base)
	{
		if (*base == '+' || *base == '-'
			|| *base < ' ' || *base > '~')
			return (0);
		i = 0;
		while (base[i + 1])
			if (*base == base[i + 1])
				return (0);
		else
			i++;
		base++;
	}
	return (1);
}
