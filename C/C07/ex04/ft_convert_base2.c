/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:05:23 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/24 16:40:29 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi_base(char *str, char *base, int *is_legal);
int		ft_index_of(char *str, char c);
char	*ft_init_atoi_vars(char *str, char *base,
			int *base_len, int *negative_multiplier);
int		ft_check_base(char *base);
int		ft_is_whitespace(char c);

int	ft_atoi_base(char *str, char *base, int *is_legal)
{
	int		base_len;
	int		sum;
	int		negative_multiplier;

	str = ft_init_atoi_vars(str, base, &base_len, &negative_multiplier);
	if (str == 0)
	{
		*is_legal = 0;
		return (0);
	}
	sum = 0;
	while (ft_index_of(base, *str) != -1)
	{
		sum = sum * base_len + ft_index_of(base, *str);
		str++;
	}
	return (sum * negative_multiplier);
}

int	ft_index_of(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i] == c)
			return (i);
	else
		i++;
	return (-1);
}

char	*ft_init_atoi_vars(char *str, char *base,
	int *base_len, int *negative_multiplier)
{
	*base_len = 0;
	while (base[*base_len])
		*base_len += 1;
	if (*base_len < 2 || !ft_check_base(base))
		return (0);
	while (ft_is_whitespace(*str))
		str++;
	*negative_multiplier = 1;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*negative_multiplier *= -1;
		str++;
	}
	return (str);
}

int	ft_check_base(char *base)
{
	int	i;

	while (*base)
	{
		if (*base == '+' || *base == '-'
			|| ft_is_whitespace(*base)
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

int	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}
