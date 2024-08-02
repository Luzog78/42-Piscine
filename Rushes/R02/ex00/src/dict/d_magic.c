/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_magic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 20:57:00 by kiroussa          #+#    #+#             */
/*   Updated: 2023/07/30 21:02:04 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

int	ft_dict_handle_magic(t_dict *dict, int magic, char *value)
{
	if (magic == -1)
	{
		free(dict->and);
		dict->and = value;
	}
	else if (magic == -2)
		dict->put_ones = *value == '1';
	else if (magic == -3)
		dict->put_hyphen = *value == '1';
	else if (magic == -5)
		dict->put_comma = *value == '1';
	else
		return (0);
	return (1);
}
