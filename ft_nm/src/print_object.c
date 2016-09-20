/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 14:20:24 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 13:43:18 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int		print_object_can_display(t_params *params, t_object* object
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
	return (1);
}

void			print_object(t_env *env, t_object *object)
{
	t_symbol_list	*lst;

	lst = object->symbols;
	while (lst)
	{
		if (!print_object_can_display(&env->params, object, &lst->symbol))
		{
			lst = lst->next;
			continue;
		}
		if (!env->params.u && !env->params.j)
		{
			print_object_symbol_value(object, &lst->symbol);
			ft_putchar(' ');
		}
		if (!env->params.u && !env->params.j)
		{
			print_object_symbol_sect_letter(object, &lst->symbol);
			ft_putchar(' ');
		}
		ft_putendl(lst->symbol.name);
		lst = lst->next;
	}
}
