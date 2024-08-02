/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 06:26:20 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/21 05:50:34 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	prod;

	if (nb < 0)
		return (0);
	prod = 1;
	while (nb > 1)
	{
		prod *= nb;
		nb--;
	}
	return (prod);
}
