/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 12:24:58 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/21 13:21:39 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

char	g_parse_error;

static int	parse_arguments_char(t_params *params, char c)
{
	if (c == 'a')
		params->a = 1;
	else if (c == 't')
		params->t = 1;
	else if (c == 'd')
		params->d = 1;
	else
		return (0);
	return (1);
}

static int	parse_arguments_string(t_params *params, char *str)
{
	int		i;

	i = 1;
	while (str[i])
	{
		if (!parse_arguments_char(params, str[i]))
		{
			g_parse_error = str[i];
			return (0);
		}
		i++;
	}
	return (1);
}

int			parse_arguments(t_params *params, int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-')
		{
			if (!parse_arguments_string(params, av[i]))
				return (0);
		}
		else
			return (i);
		++i;
	}
	return (i);
}
