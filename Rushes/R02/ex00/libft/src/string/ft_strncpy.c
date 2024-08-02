/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:12:13 by kiroussa          #+#    #+#             */
/*   Updated: 2023/07/29 15:31:13 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*orig_dest;

	orig_dest = dest;
	while (*src && n)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	while (n--)
		*dest++ = '\0';
	return (orig_dest);
}
