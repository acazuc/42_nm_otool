/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_print_symbol_value.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 12:19:57 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 14:42:45 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	object_print_symbol_value(t_env *env
		, t_object *object, t_symbol *symbol)
{
	if (symbol->sect == 0)
	{
		if (env->params.x)
		{
			if (object->is_64)
				ft_putstr("0000000000000000");
			else
				ft_putstr("00000000");
		}
		else
		{
			if (object->is_64)
				ft_putstr("                ");
			else
				ft_putstr("        ");
		}
	}
	else
	{
		if (object->is_64)
			print_hex_8(symbol->value);
		else
			print_hex_4(symbol->value);
	}
	ft_putchar(' ');
}
