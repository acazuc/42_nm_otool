/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_section_reverse.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 10:37:16 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 11:02:34 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	struct_section_reverse_32(struct section *section)
{
	section->addr = ft_swap_uint(section->addr);
	section->size = ft_swap_uint(section->size);
	section->offset = ft_swap_uint(section->offset);
	section->align = ft_swap_uint(section->align);
	section->reloff = ft_swap_uint(section->reloff);
	section->nreloc = ft_swap_uint(section->nreloc);
	section->flags = ft_swap_uint(section->flags);
}

void	struct_section_reverse_64(struct section_64 *section)
{
	section->addr = ft_swap_ulong(section->addr);
	section->size = ft_swap_ulong(section->size);
	section->offset = ft_swap_uint(section->offset);
	section->align = ft_swap_uint(section->align);
	section->reloff = ft_swap_uint(section->reloff);
	section->nreloc = ft_swap_uint(section->nreloc);
	section->flags = ft_swap_uint(section->flags);
}
