/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_exists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:20:09 by kiroussa          #+#    #+#             */
/*   Updated: 2023/07/30 12:22:01 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

int	ft_exists(t_dict *dict, unsigned long long nb)
{
	int	i;

	i = -1;
	while (++i < dict->len)
		if (dict->items[i].nb == nb)
			return (1);
	return (0);
}
