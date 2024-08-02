/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbreton <jbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:49:36 by jbreton           #+#    #+#             */
/*   Updated: 2023/07/23 16:46:48 by jbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	int	*presets;
	int	**tab;

	if (argc == 2)
	{
		presets = ft_fetch_presets(argv[1]);
		if (presets != 0)
		{
			tab = ft_create_2d_array();
			if (tab != 0)
			{
				if (!ft_backtracking(tab, presets, 0, 0))
					write(1, "Error.\n", 7);
				ft_free_2d_array(tab);
				free(presets);
				return (0);
			}
			free(presets);
		}
	}
	write(1, "Error.\n", 7);
	return (1);
}
