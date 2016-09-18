/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_header.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 10:40:01 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/18 07:34:31 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int		parse_file_header(t_file *file)
{
	/*uint32_t magic = file->header.magic;
	if (magic == MH_MAGIC)
		ft_putendl("MH_MAGIC");
	else if (magic == MH_MAGIC_64)
		ft_putendl("MH_MAGIC_64");
	else if (magic == MH_CIGAM)
		ft_putendl("MH_CIGAM");
	else if (magic == MH_CIGAM_64)
		ft_putendl("MH_CIGAM_64");
	if (magic & MH_OBJECT)
		ft_putendl("MH_OBJECT");
	if (magic & MH_EXECUTE)
		ft_putendl("MH_EXECUTE");
	if (magic & MH_DYLIB)
		ft_putendl("DYLIB");
	if (magic & MH_DYLIB_STUB)
		ft_putendl("MH_DYLIB_STUB");
	file->is_64 = magic == MH_MAGIC_64 || magic == MH_CIGAM_64;
	file->byte_order = (magic == MH_MAGIC || magic == MH_MAGIC_64) ? BO_BIG : BO_LITTLE;*/
	(void)file;
	return (1);
}
