/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 14:20:24 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 15:12:00 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int		object_print_can_display(t_params *params, t_object *object
		, t_symbol *symbol)
{
	char	c;

	c = get_symbol_letter(object, symbol);
	if (params->u_caps && (c == 'u' || c == 'U'))
		return (0);
	if (params->u && (c != 'u' && c != 'U'))
		return (0);
	if (!params->a && symbol->type & N_STAB)
		return (0);
	if (params->g && !(symbol->type & N_EXT))
		return (0);
	return (1);
}

static void		object_print_check_fname(t_env *env, char *fname)
{
	if (env->params.a_caps)
	{
		ft_putstr(fname);
		ft_putchar(' ');
	}
}

static void		object_print_check_values(t_env *env, t_object *object
		, t_symbol_list *lst)
{
	if (!env->params.j)
	{
		if (!env->params.u && !env->params.j)
		{
			object_print_symbol_value(env, object, &lst->symbol);
		}
		if (env->params.x)
		{
			print_hex_1(lst->symbol.type);
			ft_putchar(' ');
			print_hex_1(lst->symbol.sect);
			ft_putchar(' ');
			print_hex_2(lst->symbol.desc);
			ft_putchar(' ');
			print_hex_4(lst->symbol.strx);
			ft_putchar(' ');
		}
		if (!env->params.x && !env->params.u && !env->params.j)
		{
			object_print_symbol_sect_letter(object, &lst->symbol);
		}
	}
}

void			object_print(t_env *env, t_object *object, char *fname)
{
	t_symbol_list	*lst;

	lst = object->symbols;
	while (lst)
	{
		if (!object_print_can_display(&env->params, object, &lst->symbol))
		{
			lst = lst->next;
			continue;
		}
		object_print_check_fname(env, fname);
		object_print_check_values(env, object, lst);
		ft_putendl(lst->symbol.name);
		lst = lst->next;
	}
}
