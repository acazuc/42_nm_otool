/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mach_header_reverse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 16:20:17 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/19 16:23:54 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	mach_header_reverse(struct mach_header_64 *mach_header)
{
	mach_header->magic = ft_swap_uint(mach_header->magic);
	mach_header->cputype = ft_swap_int(mach_header->cputype);
	mach_header->cpusubtype = ft_swap_int(mach_header->cpusubtype);
	mach_header->filetype = ft_swap_uint(mach_header->filetype);
	mach_header->ncmds = ft_swap_uint(mach_header->ncmds);
	mach_header->sizeofcmds = ft_swap_uint(mach_header->sizeofcmds);
	mach_header->flags = ft_swap_uint(mach_header->flags);
}
