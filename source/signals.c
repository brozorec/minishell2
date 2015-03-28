/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 13:03:19 by bbarakov          #+#    #+#             */
/*   Updated: 2015/03/28 17:45:16 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"
#include "ft_sh1_prototypes.h"

void		sig_handler(int sig)
{
	printf("%d\n", sig); //
	if (sig == 11)
	{
		ft_putstr("exit\n");
		exit(0);
	}
	if (sig != 20)
	{
		ft_putstr("\n@>");
		return ;
	}
	else
		return ;
}

void		signals(void)
{
	int			i;

	i = 1;
	while (i <= 31 && i != 2)   // remove 2nd condition
	{
		signal(i, sig_handler);
		++i;
	}
}
