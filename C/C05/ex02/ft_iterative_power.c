/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 06:34:18 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/19 10:51:58 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	prod;

	if (power < 0)
		return (0);
	prod = 1;
	while (power > 0)
	{
		prod *= nb;
		power--;
	}
	return (prod);
}
