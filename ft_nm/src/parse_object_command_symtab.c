/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_command_symtab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 11:43:57 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 10:24:34 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int	parse_object_command_symtab(t_object *object)
{
	struct symtab_command	symtab_command;
	t_symbol				symbol;
	uint32_t				i;

	if (!buffer_read(&object->buffer, &symtab_command, sizeof(symtab_command)))
		return (0);
	i = -1;
	if (!buffer_set_position(&object->buffer, symtab_command.symoff))
		return (0);
	while (++i < symtab_command.nsyms)
	{
		if (!struct_symbol_read(object, &symbol))
			return (0);
		if (symbol.strx)
			symbol.name = (char*)(object->buffer.data
					+ symtab_command.stroff + symbol.strx);
		if (!object_symbols_push_back(&object->symbols, symbol))
			return (0);
	}
	return (1);
}
