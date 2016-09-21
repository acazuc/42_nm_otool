/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 11:16:02 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/21 12:37:00 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

char	g_parse_error = '\0';

static int	run_parse_arguments(t_params *params, int ac, char **av)
{
	int		ret;

	if (!(ret = parse_arguments(params, ac, av)))
	{
		ft_putstr_fd("ft_otool: Unknown command line argument '-", 2);
		ft_putchar_fd(g_parse_error, 2);
		ft_putendl_fd("'.", 2);
		return (0);
	}
	return (ret);
}

static int	check_params(t_params *params)
{
	if (!params->a && !params->s_caps && !params->f && !params->h
			&& !params->l && !params->t && !params->d)
	{
		ft_putendl_fd("You must specify at least one of -aSfhltd", 2);
		return (0);
	}
	return (1);
}

int			main(int ac, char **av)
{
	t_env	env;
	int		j;
	int		i;

	ft_bzero(&env, sizeof(env));
	if (ac < 2)
		ft_putendl_fd("ft_otool: at least one file must by specified", 2);
	else
	{
		i = run_parse_arguments(&env.params, ac, av);
		j = i;
		if (!check_params(&env.params) || !i)
			return (EXIT_FAILURE);
		if (i >= ac)
			ft_putendl_fd("ft_otool: at least one file must by specified", 2);
		else
		{
			while (i < ac)
			{
				ft_otool(&env, av[i], j == i);
				i++;
			}
		}
	}
}
