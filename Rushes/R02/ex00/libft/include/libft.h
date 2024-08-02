/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 13:08:31 by kiroussa          #+#    #+#             */
/*   Updated: 2023/07/30 12:38:15 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>

/**
 * I/O operations
 */

void			ft_putchar(char c);
void			ft_putstr(char *str);

void			ft_putchar_fd(int fd, char c);
void			ft_putstr_fd(int fd, char *str);

char			*get_next_line(int fd);

/**
 * String operations
 */

int				ft_strlen(char *str);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int				ft_strcmp(char *s1, char *s2);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
char			*ft_strcat(char *dest, const char *src);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

char			*ft_strdup(char *str);
char			*ft_strdup_range(char *str, size_t start, size_t end);

char			*ft_append(char *buffer, size_t l, char append[], size_t l2);

/**
 * "Real" atoi functions, meaning matching 
 * the behaviour of the stdlib `atoi`.
 */

int				ft_ratoi_ll(char *str, long long *resptr);
int				ft_ratoi_ull(char *str, unsigned long long *resptr);

int				ft_isspace(char c);
int				ft_isdigit(char c);

/**
 * Math operations
 */

int				ft_abs(int i);

#endif
