/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_print_symbol_sect_letter.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 12:22:26 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 14:18:29 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	object_print_symbol_sect_letter(t_object *object, t_symbol *symbol)
{
	ft_putchar(get_symbol_letter(object, symbol));
	ft_putchar(' ');
}
