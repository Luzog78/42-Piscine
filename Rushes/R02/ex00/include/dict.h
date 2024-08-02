/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:52:45 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/30 21:00:13 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

# define DEFAULT_DICT_FILE "numbers.dict"

# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef struct s_pair
{
	unsigned long long	nb;
	char				*name;
}	t_pair;

typedef struct s_dict
{
	int		len;
	t_pair	*items;
	char	*and;
	t_bool	put_ones;
	t_bool	put_hyphen;
	t_bool	put_comma;
}	t_dict;

void	ft_dict_init(t_dict *dict);
int		ft_exists(t_dict *dict, unsigned long long nb);
void	ft_dict_free(t_dict *dict);
int		ft_dict_put(t_dict *dict, unsigned long long nb, char *name);
int		ft_dict_parse(t_dict *dict, char *file_name);
int		ft_dict_handle_magic(t_dict *dict, int magic, char *line);
void	ft_dict_sort(t_dict dict);

#endif
