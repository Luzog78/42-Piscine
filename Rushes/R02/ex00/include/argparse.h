/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:08:32 by kiroussa          #+#    #+#             */
/*   Updated: 2023/07/30 18:14:31 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGPARSE_H
# define ARGPARSE_H

# include "libft.h"
# include "dict.h"
# include "error.h"

# define PROMPT1 "🔢 Please input a number to display: "
# define PROMPT2 "📖 Please provide a dictionary file (default 'numbers.dict'): "

# define ERROR_WRONG_ARG "💥 Wrong argument, try again...\n"
# define ERROR_INVALID_ARG "💔 Invalid argument, please try again...\n" 
# define ERROR_UNEXPECTED "😐 bruh.\n"

int	ft_handle_args(t_dict *dict, unsigned long long *n, int argc, char *argv[]);

#endif
