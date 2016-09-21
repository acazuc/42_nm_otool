/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat_header_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 14:11:52 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/19 14:29:29 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	fat_header_reverse(struct fat_header *fat_header)
{
	fat_header->magic = ft_swap_uint(fat_header->magic);
	fat_header->nfat_arch = ft_swap_uint(fat_header->nfat_arch);
}
