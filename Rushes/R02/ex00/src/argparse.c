/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:09:35 by kiroussa          #+#    #+#             */
/*   Updated: 2023/07/30 18:28:25 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argparse.h"

int	ft_validate_ratoi_ull(char *str)
{
	unsigned long long	dummy;

	return (ft_ratoi_ull(str, &dummy) == 0);
}

char	*ft_prompt(char *prompt, int (*validate)(char *))
{
	char	*result;
	char	*no_nl;

	while (1)
	{
		ft_putstr(prompt);
		result = get_next_line(0);
		if (!result)
			ft_putstr_fd(2, ERROR_WRONG_ARG);
		if (!result)
			continue ;
		no_nl = ft_strdup_range(result, 0, ft_strlen(result) - 1);
		free(result);
		if ((validate != NULL && (ft_strlen(no_nl) == 0 || !validate(no_nl))))
		{
			ft_putstr_fd(2, ERROR_INVALID_ARG);
			free(no_nl);
			continue ;
		}
		return (no_nl);
	}
	return (NULL);
}

int	ft_handle_stdin(t_dict *dict, unsigned long long *n)
{
	char	*entry;

	entry = ft_prompt(PROMPT1, &ft_validate_ratoi_ull);
	if (!entry)
		return (0);
	if (ft_ratoi_ull(entry, n))
	{
		free(entry);
		return (0);
	}
	free(entry);
	entry = ft_prompt(PROMPT2, NULL);
	if (entry && ft_strlen(entry) == 0)
	{
		free(entry);
		entry = ft_strdup("numbers.dict");
	}
	if (!ft_dict_parse(dict, entry))
	{
		ft_putstr_fd(2, ERR_DICT);
		free(entry);
		return (0);
	}
	free(entry);
	return (1);
}

int	ft_handle_nb(unsigned long long *n, char *argv[])
{
	unsigned long long	result;

	if (ft_ratoi_ull(argv[1], &result))
	{
		ft_putstr_fd(2, ERR_NEG_INPUT);
		return (0);
	}
	*n = result;
	return (1);
}

int	ft_handle_args(t_dict *dict, unsigned long long *n, int argc, char *argv[])
{
	if (argc == 1)
		return (ft_handle_stdin(dict, n));
	if (!ft_handle_nb(n, argv))
		return (0);
	if (argc == 2)
	{
		if (!ft_dict_parse(dict, DEFAULT_DICT_FILE))
		{
			ft_putstr_fd(2, ERR_DICT);
			return (0);
		}
		return (1);
	}
	else if (argc == 3)
	{
		if (!ft_dict_parse(dict, argv[2]))
		{
			ft_putstr_fd(2, ERR_DICT);
			return (0);
		}
		return (1);
	}
	ft_putstr_fd(2, ERR_TOO_MANY_ARGS);
	return (0);
}
