/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:55:56 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/30 12:59:04 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

/**
 * @brief	Free the items' array of the given dict.
*/
void	ft_dict_free(t_dict *dict)
{
	int	i;

	free(dict->and);
	if (!dict->items)
		return ;
	i = -1;
	while (++i < dict->len)
		free(dict->items[i].name);
	free(dict->items);
}
