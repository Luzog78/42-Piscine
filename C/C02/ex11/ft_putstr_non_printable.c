/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:36:19 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/21 06:59:38 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str);
void	ft_put_hex(unsigned char i);

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (' ' <= *str && *str <= '~')
			write(1, str, 1);
		else
			ft_put_hex((unsigned char) *str);
		str++;
	}
}

void	ft_put_hex(unsigned char i)
{
	write(1, "\\", 1);
	write(1, &"0123456789abcdef"[i / 16], 1);
	write(1, &"0123456789abcdef"[i % 16], 1);
}
