/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:20:37 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/18 09:08:44 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int	ft_strlen(char *str);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	full_size;
	unsigned int	counter;
	unsigned int	i;

	i = 0;
	while (dest[i] && i < size)
		i++;
	full_size = ft_strlen(src) + i;
	if (size > 0)
	{
		counter = ft_strlen(dest);
		i = 0;
		while (counter < size - 1 && src[i] != '\0')
		{
			dest[counter] = src[i];
			counter++;
			i++;
		}
		dest[counter] = '\0';
	}
	return (full_size);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
