/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_command_symtab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 11:43:57 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/19 08:45:56 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int	parse_object_command_symtab_32(t_object *object
		, t_object_cmd *object_cmd)
{
	struct symtab_command	*symtab_command;
	struct nlist			nlist;
	t_symbol				symbol;
	long long				i;

	symtab_command = (struct symtab_command*)object_cmd->data;
	i = -1;
	while (++i < symtab_command->nsyms)
	{
		if (!(buffer_set_position(&object->buffer
						, symtab_command->symoff + sizeof(nlist) * i)))
			return (0);
		if (!(buffer_read(&object->buffer, &nlist, sizeof(nlist))))
			return (0);;
		if (nlist.n_un.n_strx == 0 || nlist.n_type & N_STAB)
			continue;
		if (!(symbol.name = ft_strdup((char*)(object->buffer.data
						+ symtab_command->stroff + nlist.n_un.n_strx))))
			return (0);
		symbol.value = nlist.n_value;
		symbol.section = nlist.n_sect;
		if (!object_symbols_push_back(&object->symbols, symbol))
			return (0);
	}
	return (1);
}

static int	parse_object_command_symtab_64(t_object *object
		, t_object_cmd *object_cmd)
{
	struct symtab_command	*symtab_command;
	struct nlist_64			nlist;
	t_symbol				symbol;
	long long				i;

	symtab_command = (struct symtab_command*)object_cmd->data;
	i = -1;
	while (++i < symtab_command->nsyms)
	{
		if (!(buffer_set_position(&object->buffer, symtab_command->symoff
						+ sizeof(nlist) * i)))
			return (0);
		if (!(buffer_read(&object->buffer, &nlist, sizeof(nlist))))
			return (0);
		if (nlist.n_un.n_strx == 0 || nlist.n_type & N_STAB)
			continue;
		if (!(symbol.name = ft_strdup((char*)(object->buffer.data
							+ symtab_command->stroff + nlist.n_un.n_strx))))
			return (0);
		symbol.value = nlist.n_value;
		symbol.section = nlist.n_sect;
		symbol.external = nlist.n_type & N_EXT;
		if (!object_symbols_push_back(&object->symbols, symbol))
			return (0);
	}
	return (1);
}

int			parse_object_command_symtab(t_object *object
		, t_object_cmd *object_cmd)
{
	if (object->is_64)
		return (parse_object_command_symtab_64(object, object_cmd));
	return (parse_object_command_symtab_32(object, object_cmd));
}