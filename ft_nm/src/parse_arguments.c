/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 12:24:58 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 13:26:54 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

char	g_parse_error;

static int	parse_arguments_char_2(t_params *params, char c)
{
	if (c == 'l')
		params->l = 1;
	else if (c == 'f')
		params->f = 1;
	else if (c == 'A')
		params->a_caps = 1;
	else if (c == 'P')
		params->p_caps = 1;
	else if (c == 'L')
		params->l_caps = 1;
	else
		return (0);
	return (1);
}

static int	parse_arguments_char(t_params *params, char c)
{
	if (c == 'a')
		params->a = 1;
	else if (c == 'g')
		params->g = 1;
	else if (c == 'n')
		params->n = 1;
	else if (c == 'o')
		params->o = 1;
	else if (c == 'p')
		params->p = 1;
	else if (c == 'r')
		params->r = 1;
	else if (c == 'u')
		params->u = 1;
	else if (c == 'u')
		params->u_caps = 1;
	else if (c == 'm')
		params->m = 1;
	else if (c == 'x')
		params->x = 1;
	else if (c == 'j')
		params->j = 1;
	return (parse_arguents_char_2(params, c));
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
