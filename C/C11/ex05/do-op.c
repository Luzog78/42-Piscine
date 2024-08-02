/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:09:01 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/26 10:09:15 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	add(int a, int b);
void	sub(int a, int b);
void	mul(int a, int b);
void	div(int a, int b);
void	mod(int a, int b);
int		ft_atoi(char *str);

void	*get_operation(char *str)
{
	if (str[0] == '+' && str[1] == '\0')
		return (&add);
	else if (str[0] == '-' && str[1] == '\0')
		return (&sub);
	else if (str[0] == '*' && str[1] == '\0')
		return (&mul);
	else if (str[0] == '/' && str[1] == '\0')
		return (&div);
	else if (str[0] == '%' && str[1] == '\0')
		return (&mod);
	else
		return (0);
}

int	main(int ac, char **av)
{
	int		a;
	int		b;
	void	*(*f)(int, int);

	ac--;
	av++;
	if (ac != 3)
		return (0);
	a = ft_atoi(av[0]);
	b = ft_atoi(av[2]);
	f = get_operation(av[1]);
	if (f)
		f(a, b);
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}
