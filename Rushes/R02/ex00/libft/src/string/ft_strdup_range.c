/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:47:18 by kiroussa          #+#    #+#             */
/*   Updated: 2023/07/30 11:25:57 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_range(char *str, size_t start, size_t end)
{
	char	*new;

	if (!str)
		return (NULL);
	if (start > 0)
		return (ft_strdup_range(str + start, 0, end));
	new = malloc(end + 1);
	if (new == NULL)
		return (NULL);
	new[end] = 0;
	while (end--)
		new[end] = str[end];
	return (new);
}
