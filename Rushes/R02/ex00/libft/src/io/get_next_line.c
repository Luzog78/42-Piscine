/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:29:41 by kiroussa          #+#    #+#             */
/*   Updated: 2023/07/30 17:54:53 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define GNL_BUFFER_LENGTH 1

/**
 * @brief	Lis la prochaine ligne du fichier.
 *
 * @param	fd	Le descripteur du fichier à lire (ou 0 pour stdin)
 *
 * @return	char*	La chaine de caractère.
 */
char	*get_next_line(int fd)
{
	char			*line;
	unsigned int	buf_len;
	char			tmp[GNL_BUFFER_LENGTH];
	int				nread;

	line = NULL;
	buf_len = GNL_BUFFER_LENGTH;
	while (--buf_len)
		tmp[buf_len] = 0;
	while (1)
	{
		nread = read(fd, &tmp, GNL_BUFFER_LENGTH);
		if (nread <= 0)
			break ;
		line = ft_append(line, buf_len, tmp, nread);
		buf_len += nread;
		if (line == NULL || tmp[nread - 1] == '\n')
			break ;
	}
	if ((nread < 0 || line == NULL) && buf_len > 0)
		free(line);
	if (nread < 0 || line == NULL)
		return (NULL);
	line = ft_append(line, (size_t) buf_len, "\0", (size_t) 1);
	return (line);
}
