/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:42:17 by kiroussa          #+#    #+#             */
/*   Updated: 2023/07/29 19:52:28 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Ajoute à la fin du `buffer` le second buffer `c`.
 *
 * @param	buffer	Le buffer précédent, peut être `NULL`.
 * @param	buf_len	Pointeur vers la taille précédente du `buffer`.
 * @param	c		Tableau de nouveaux caractères à rajouter à `buffer`.
 * @param	n		Taille du nouveau tableau `c`.
 *
 * @return	char*	Le nouveau buffer, concaténant `buffer` et `c`.
 */
char	*ft_append(char *buffer, size_t buf_len, char c[], size_t nread)
{
	char	*new_buffer;
	int		i;

	if (buffer == NULL)
	{
		buffer = malloc(nread);
		if (buffer == NULL)
			return (NULL);
		ft_strncpy(buffer, c, nread);
		return (buffer);
	}
	new_buffer = malloc(buf_len + nread);
	if (new_buffer == NULL)
		return (NULL);
	i = -1;
	while (((unsigned int)(++i)) < buf_len)
		new_buffer[i] = buffer[i];
	free(buffer);
	ft_strncpy(new_buffer + buf_len, c, nread);
	return (new_buffer);
}
