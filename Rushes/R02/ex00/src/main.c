/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:54:39 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/30 22:33:49 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "error.h"
#include "argparse.h"
#include "libft.h"

void	ft_loop(unsigned long long n, t_dict dict, int depth);

int	main(int argc, char *argv[])
{
	t_dict				dict;
	unsigned long long	n;

	ft_dict_init(&dict);
	if (!ft_handle_args(&dict, &n, argc, argv))
	{
		ft_dict_free(&dict);
		return (1);
	}
	if (dict.len == 0 || dict.items == 0)
	{
		ft_putstr_fd(2, ERR_DICT);
		ft_dict_free(&dict);
		return (1);
	}
	ft_dict_sort(dict);
	ft_loop(n, dict, 0);
	ft_putchar('\n');
	ft_dict_free(&dict);
	return (0);
}
