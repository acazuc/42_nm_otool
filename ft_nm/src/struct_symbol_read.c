/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_symbol_read.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 08:51:19 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 09:41:24 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int	struct_symbol_read_64(t_object *object, t_symbol *symbol)
{
	struct nlist_64		nlist;

	if (!buffer_read(&object->buffer, &nlist, sizeof(nlist)))
		return (0);
	if (object->byte_order == BO_LITTLE)
		struct_nlist_reverse_64(&nlist);
	symbol->name = NULL;
	symbol->strx = nlist.n_un.n_strx;
	symbol->type = nlist.n_type;
	symbol->sect = nlist.n_sect;
	symbol->desc = nlist.n_desc;
	symbol->value = nlist.n_value;
	return (1);
}

static int	struct_symbol_read_32(t_object *object, t_symbol *symbol)
{
	struct nlist		nlist;

	if (!buffer_read(&object->buffer, &nlist, sizeof(nlist)))
		return (0);
	if (object->byte_order == BO_LITTLE)
		struct_nlist_reverse_32(&nlist);
	symbol->name = NULL;
	symbol->strx = nlist.n_un.n_strx;
	symbol->type = nlist.n_type;
	symbol->sect = nlist.n_sect;
	symbol->desc = nlist.n_desc;
	symbol->value = nlist.n_value;
	return (1);
}

int			struct_symbol_read(t_object *object, t_symbol *symbol)
{
	if (object->is_64)
		return (struct_symbol_read_64(object, symbol));
	return (struct_symbol_read_32(object, symbol));
}
