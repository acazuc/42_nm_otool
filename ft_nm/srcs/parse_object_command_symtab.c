/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_command_symtab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 11:43:57 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/18 13:08:55 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int		parse_object_command_symtab(t_object *object, t_object_cmd *object_cmd)
{
	struct symtab_command	*symtab_command;
	struct nlist_64			nlist;
	unsigned long			i;

	symtab_command = (struct symtab_command*)object_cmd->data;
	ft_putnbr(symtab_command->nsyms);
	ft_putchar('\n');
	ft_putnbr(symtab_command->stroff);
	ft_putchar('\n');
	ft_putnbr(symtab_command->strsize);
	ft_putchar('\n');
	i = 0;
	while (i < symtab_command->nsyms)
	{
		if (!(buffer_set_position(&object->buffer, symtab_command->symoff + sizeof(nlist) * i)))
			return (0);
		if (!(buffer_read(&object->buffer, &nlist, sizeof(nlist))))
			return (0);
		ft_putstr("\nnlist:");
		ft_putstr("x_strx: ");
		ft_putul(nlist.n_un.n_strx);
		ft_putchar('\n');
		ft_putstr("type: ");
		ft_putnbr(nlist.n_type);
		ft_putchar('\n');
		ft_putstr("sect: ");
		ft_putnbr(nlist.n_sect);
		ft_putchar('\n');
		ft_putstr("desc: ");
		ft_putnbr(nlist.n_desc);
		ft_putchar('\n');
		ft_putstr("value: ");
		ft_putnbr(nlist.n_value);
		ft_putchar('\n');
		print_hex_8(nlist.n_value);
		ft_putchar(' ');
		if (nlist.n_sect == 0)
			ft_putstr("U ");
		else
			ft_putstr("O ");
		ft_putendl((char*)(object->buffer.data + symtab_command->stroff + nlist.n_un.n_strx));
		i++;
	}
	return (1);
}
