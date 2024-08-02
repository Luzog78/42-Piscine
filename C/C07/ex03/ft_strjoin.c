/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:05:17 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/24 16:22:09 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_full_len(int size, char **strs, char *sep);
void	ft_fill(int size, char **strs, char *sep, char *joined);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*joined;

	joined = malloc(sizeof(char) * (ft_full_len(size, strs, sep) + 1));
	if (joined != NULL)
		ft_fill(size, strs, sep, joined);
	return (joined);
}

int	ft_full_len(int size, char **strs, char *sep)
{
	int	full_len;
	int	i;
	int	j;
	int	sep_len;

	sep_len = 0;
	i = -1;
	while (sep[++i])
		sep_len++;
	full_len = 0;
	i = 0;
	while (i < size)
	{
		if (i != 0)
			full_len += sep_len;
		j = 0;
		while (strs[i][j])
		{
			full_len++;
			j++;
		}
		i++;
	}
	return (full_len);
}

void	ft_fill(int size, char **strs, char *sep, char *joined)
{
	int	i;
	int	j;
	int	cursor;

	cursor = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (i != 0 && sep[j])
		{
			joined[cursor] = sep[j];
			cursor++;
			j++;
		}
		j = 0;
		while (strs[i][j])
		{
			joined[cursor] = strs[i][j];
			cursor++;
			j++;
		}
		i++;
	}
	joined[cursor] = '\0';
}
