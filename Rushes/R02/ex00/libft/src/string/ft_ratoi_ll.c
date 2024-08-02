/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ratoi_ll.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 18:51:23 by kiroussa          #+#    #+#             */
/*   Updated: 2023/07/30 21:36:29 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ratoi_ll(char *str, long long *resptr)
{
	long long	result;
	int			i;
	int			mult;

	result = 0;
	i = 0;
	mult = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			mult = -mult;
	if (str[i] == '+' || str[i] == '-')
		return (2);
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	*resptr = (result * mult);
	return (str[i] != '\0');
}
