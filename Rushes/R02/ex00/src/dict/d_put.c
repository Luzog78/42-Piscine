/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_put.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:27:02 by kiroussa          #+#    #+#             */
/*   Updated: 2023/07/30 12:18:13 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

int	ft_dict_put(t_dict *dict, unsigned long long nb, char *name)
{
	t_pair	*array;
	int		i;

	if (!dict->items || dict->len == 0)
	{
		dict->items = malloc(sizeof(t_pair));
		dict->items[0].nb = nb;
		dict->items[0].name = name;
		dict->len = 1;
		return (1);
	}
	if (ft_exists(dict, nb))
		return (0);
	array = malloc(sizeof(t_pair) * (dict->len + 1));
	i = -1;
	while (++i < dict->len)
		array[i] = dict->items[i];
	array[dict->len].nb = nb;
	array[dict->len].name = name;
	dict->len++;
	free(dict->items);
	dict->items = array;
	return (1);
}
