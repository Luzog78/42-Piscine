/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:55:56 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/30 22:34:07 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dict.h"

char	*ft_int_string(char *line)
{
	int		i;
	int		sign_found;

	i = -1;
	sign_found = (*line == '+' || *line == '-');
	while (++i < ft_strlen(line))
	{
		if (i == 0 && !sign_found)
			if (!ft_isdigit(line[i]))
				return (NULL);
		if (i == 1 && sign_found)
			if (!ft_isdigit(line[i]))
				return (NULL);
		if (i > 0)
			if (!ft_isdigit(line[i]))
				break ;
	}
	return (ft_strdup_range(line, 0, i));
}

int	ft_parse_value(char *line, int nb_len, int line_len, char **resptr)
{
	int		passed_colon;
	int		i;
	char	*value;

	passed_colon = 0;
	i = nb_len - 1;
	while (++i < line_len)
	{
		if (line[i] != ' ' && passed_colon)
			break ;
		if (line[i] == ':' && !passed_colon)
			passed_colon = 1;
		if (line[i] != ' ' && !passed_colon)
			return (0);
	}
	if (!line[i])
		return (0);
	value = line + i;
	*resptr = ft_strdup_range(value, 0, ft_strlen(value) - 1);
	return (1);
}

int	ft_handle_magic(t_dict *dict, char *line)
{
	long long	magic;
	char		*magic_str;
	char		*value;
	int			handled;

	magic_str = ft_int_string(line);
	if (!magic_str)
		return (0);
	ft_ratoi_ll(magic_str, &magic);
	if (!ft_parse_value(line, ft_strlen(magic_str), ft_strlen(line), &value))
	{
		free(magic_str);
		return (0);
	}
	free(magic_str);
	handled = ft_dict_handle_magic(dict, magic, value);
	if (magic != -1)
		free(value);
	free(line);
	return (handled);
}

/**
 * @brief	Parses a single line and adds it to the dict; 
 * 			also `free`s the line.
 *
 * @return	int	1 if the parsing went well, 0 if an error occured.
 */
int	ft_parse_line(t_dict *dict, char *line)
{
	unsigned long long	nb;
	char				*value;
	char				*nb_str;
	int					nb_len;

	if (*line == '-')
		return (ft_handle_magic(dict, line));
	if (!ft_isdigit(*line) && *line != '+')
		return (0);
	nb_str = ft_int_string(line);
	if (ft_ratoi_ull(nb_str, &nb))
	{
		free(nb_str);
		return (0);
	}
	nb_len = ft_strlen(nb_str);
	free(nb_str);
	if (!ft_parse_value(line, nb_len, ft_strlen(line), &value))
		free(line);
	if (value == NULL)
		return (0);
	free(line);
	return (ft_dict_put(dict, nb, value));
}

/**
 * @brief	Initialize dict variables from the .dict file.
 * 
 * @param	dict	Pointer to a single dict (not an array).
 * @param	file	The file name to be parsed.
 *
 * @return	int		1 if the parsing went well, 0 if dict error.
*/
int	ft_dict_parse(t_dict *dict, char *file_name)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file_name, O_RDWR);
	if (fd < 0)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		i = -1;
		while (++i < ft_strlen(line) - 1)
			if (i != ' ')
				break ;
		if (i == ft_strlen(line) - 1)
			free(line);
		if (i == ft_strlen(line) - 1)
			continue ;
		if (!ft_parse_line(dict, line))
			return (0);
	}
	close(fd);
	return (1);
}
