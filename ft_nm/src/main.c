/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 09:34:32 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 12:51:29 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

char	g_parse_error = '\0';

static int	run_parse_arguments(t_params *params, int ac, char **av)
{
	int		ret;

	if (!(ret = parse_arguments(params, ac, av)))
	{
		ft_putstr_fd("ft_nm: Unknown command line argument '-", 2);
		ft_putchar_fd(g_parse_error, 2);
		ft_putendl_fd("'.", 2);
		return (0);
	}
	return (ret);
}

int		main(int ac, char **av)
{
	t_env	env;
	int		i;

	if (ac == 1)
		ft_nm("a.out", 0);
	else if (ac > 1)
	{
		i = run_parse_arguments(&env.params, ac, av);
		if (!i)
			return (EXIT_FAILURE);
		if (i >= ac)
			ft_nm("a.out", 0);
		else
		{
			while (i < ac)
			{
				ft_nm(av[i], ac > 2);
				i++;
			}
		}
	}
}
