/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 15:19:59 by bbarakov          #+#    #+#             */
/*   Updated: 2015/04/01 19:44:36 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh2.h"
#include "ft_sh2_prototypes.h"

void		ft_trim_quot_marks(char **str)
{
	char		*new_str;
	int			i;
	int			j;

	new_str = 0;
	i = 0;
	j = 0;
	if (*str)
	{
		new_str = ft_strnew(ft_strlen(*str));
		while ((*str)[i])
		{
			if ((*str)[i] == '"')
			{
				++i;
				continue;
			}
			new_str[j++] = (*str)[i++];
		}
		free(*str);
		*str = new_str;
	}
}

int			ft_len_to_char(char *str, char ch1, char ch2)
{
	int					i;

	i = 0;
	while (str[i] && str[i] != ch1 && str[i] != ch2)
		++i;
	return (i);
}

int			ft_count_char(char *str, int ch)
{
	int					i;
	int					count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ch == str[i])
			++count;
		++i;
	}
	return (count);
}

int			empty_line(char *line)
{
	int					i;

	i = 0;
	if (ft_strlen(line) == 0)
		return (0);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (1);
		++i;
	}
	return (0);
}
