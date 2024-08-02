/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:47:31 by kiroussa          #+#    #+#             */
/*   Updated: 2023/07/30 21:00:18 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "libft.h"

void	ft_dict_init(t_dict *dict)
{
	dict->len = 0;
	dict->items = NULL;
	dict->and = ft_strdup("and");
	dict->put_ones = TRUE;
	dict->put_hyphen = TRUE;
	dict->put_comma = TRUE;
}
