/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:05:21 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/25 08:41:52 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		ft_atoi_base(char *str, char *base, int *is_legal);
int		ft_nbrlen_base(int nbr, char *base, int *is_legal);
void	ft_putnbr_base(int index, int nbr, char *base, char *final);
int		ft_check_base(char *base);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		atoied;
	int		len;
	char	*final;
	int		is_legal;

	is_legal = 1;
	atoied = ft_atoi_base(nbr, base_from, &is_legal);
	len = ft_nbrlen_base(atoied, base_to, &is_legal);
	if (!is_legal || len == 0)
		return (NULL);
	final = malloc(sizeof(char) * (len + 1));
	if (final == NULL)
		return (NULL);
	ft_putnbr_base(len - 1, atoied, base_to, final);
	final[len] = '\0';
	return (final);
}

int	ft_nbrlen_base(int nbr, char *base, int *is_legal)
{
	int			count;
	long long	n;
	long long	len;

	count = 0;
	n = (long long) nbr;
	len = 0;
	while (base[len])
		len++;
	if (len < 2 || !ft_check_base(base))
	{
		*is_legal = 0;
		return (0);
	}
	else if (n < 0)
	{
		count += 1;
		n = -n;
	}
	if (n >= len)
		count += ft_nbrlen_base(n / len, base, is_legal);
	count += 1;
	return (count);
}

void	ft_putnbr_base(int index, int nbr, char *base, char *final)
{
	long long	n;
	long long	len;

	n = (long long) nbr;
	len = 0;
	while (base[len])
		len++;
	if (len < 2 || !ft_check_base(base))
		return ;
	else if (n < 0)
	{
		final[0] = '-';
		n = -n;
	}
	if (n >= len && index > 0)
		ft_putnbr_base(index - 1, n / len, base, final);
	final[index] = *(base + (n % len));
}
