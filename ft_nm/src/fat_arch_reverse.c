/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat_arch_reverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 14:12:57 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/19 14:36:17 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	fat_arch_reverse(struct fat_arch *fat_arch)
{
	fat_arch->cputype = ft_swap_uint(fat_arch->cputype);
	fat_arch->cpusubtype = ft_swap_uint(fat_arch->cpusubtype);
	fat_arch->offset = ft_swap_uint(fat_arch->offset);
	fat_arch->size = ft_swap_uint(fat_arch->size);
	fat_arch->align = ft_swap_uint(fat_arch->align);
}
