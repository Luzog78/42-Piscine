/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbreton <jbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 09:17:18 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/23 16:50:43 by jbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define SIZE 4

# include <unistd.h>
# include <stdlib.h>

int		ft_backtracking(int **tab, int *presets, int x, int y);
int		ft_apply_recursivity(int **tab, int *presets, int x, int y);

int		ft_check_dupli(int **tab);
int		ft_check_dupli_col(int **tab, int x);
int		ft_check_dupli_row(int **tab, int y);

int		ft_check_presets(int *presets, int **tab);
int		ft_check_presets_col_asc(int *presets, int **tab, int x);
int		ft_check_presets_col_desc(int *presets, int **tab, int x);
int		ft_check_presets_line_asc(int *presets, int **tab, int y);
int		ft_check_presets_line_desc(int *presets, int **tab, int y);

int		*ft_fetch_presets(char *str);
int		**ft_create_2d_array(void);
void	ft_free_2d_array(int **arr);
void	ft_write_array(int **arr);
void	ft_reset_following(int **arr, int x, int y);

#endif
