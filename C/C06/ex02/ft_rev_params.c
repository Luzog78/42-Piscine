/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:37:03 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/18 13:37:04 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;

	i = ac;
	while (--i > 0)
	{
		while (*(av[i]))
			write(1, av[i]++, 1);
		write(1, "\n", 1);
	}
	return (0);
}
