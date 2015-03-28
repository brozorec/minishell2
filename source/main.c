/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 15:50:48 by bbarakov          #+#    #+#             */
/*   Updated: 2015/03/28 19:09:38 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"
#include "ft_sh1_prototypes.h"

t_res		*get_reserve(char **env)
{
	t_res				*res;

	res = 0;
	res = (t_res *)malloc(sizeof(t_res));
	res->paths = get_reserved_paths();
	res->home = take_env_var("HOME=", 0, env);
	return (res);
}

void		exit_eof(char ***cmd, char ***env, t_res **res)
{
	free_env_cmd_res(cmd, env, res);
	ft_putstr("exit\n");
	exit(0);
}

int			proceed() //char ***env, t_res **res
{
	char				*line;
	t_general			*gen_list;

	gen_list = 0;
	if (get_next_line(0, &line) == 0)
		exit(0);		// exit_eof(cmd, env, res);
	if (ft_strlen(line) == 0)
	{
		free(line);
		return (1);
	}
	if ((gen_list = get_gen_lists(line, gen_list)) == 0)
	{
		printf("%s\n", "main");
		free(line);
		return (1);
	}
	return (0);
}

int			main(void)
{
	extern char			**environ;
	char				**env;
	t_res				*res;

	// signals();
	res = get_reserve(environ);
	env = set_my_env(environ, 0, 0, 0);
	ft_putstr("@>");
	while (1)
	{
		if (proceed() == 0)   // &env, &res
			ft_putstr("@>");
	}
	return (0);
}
