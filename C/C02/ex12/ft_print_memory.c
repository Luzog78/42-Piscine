/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 06:24:21 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/21 07:01:21 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_print_memory(void *addr, unsigned int size);
void	ft_print_mem_val(void *addr, unsigned int size);
void	ft_print_mem_cont(void **addr, unsigned int *size);
void	ft_print_int2hex(long long int n, int size);
void	ft_print_single_hex(int n);

void	*ft_print_memory(void *addr, unsigned int size)
{
	while (size / 16 + (size % 16 != 0))
	{
		ft_print_int2hex((long long)(addr + 0L), 16);
		write(1, ": ", 2);
		ft_print_mem_val(addr, size);
		ft_print_mem_cont(&addr, &size);
		write(1, "\n", 1);
	}
	return (addr + size);
}

void	ft_print_mem_val(void *addr, unsigned int size)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (size == 0)
			write(1, "  ", 2);
		else
		{
			ft_print_int2hex((unsigned char)(*(char *)(addr + i)), 2);
			size--;
		}
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
}

void	ft_print_mem_cont(void **addr, unsigned int *size)
{
	int		i;
	char	c;

	i = 0;
	while (i < 16)
	{
		if (*size == 0)
			break ;
		else
		{
			c = *(char *)*addr;
			if (' ' <= c && c <= '~')
				write(1, &c, 1);
			else
				write(1, ".", 1);
			*addr += 1;
			*size -= 1;
		}
		i++;
	}
}

void	ft_print_int2hex(long long n, int size)
{
	int			i;
	int			j;
	long long	pow;
	long long	div;

	i = size - 1;
	while (i >= 0)
	{
		j = 0;
		pow = 1;
		while (j < i)
		{
			pow *= 16;
			j++;
		}
		div = n / pow;
		ft_print_single_hex(div);
		n -= div * pow;
		i--;
	}
}

void	ft_print_single_hex(int n)
{
	if (n < 10)
		write(1, &(char){'0' + n}, 1);
	else
		write(1, &(char){'a' + n - 10}, 1);
}
