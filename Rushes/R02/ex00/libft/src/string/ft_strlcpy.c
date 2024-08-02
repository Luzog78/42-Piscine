/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:07:40 by kiroussa          #+#    #+#             */
/*   Updated: 2023/07/29 16:08:49 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i + 1 < size && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
		dest[i] = 0;
	while (src[i++])
		;
	return (i - 1);
}
