/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_header.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 10:40:01 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/23 11:34:25 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int		parse_file_header(t_file *file)
{
	uint32_t	magic;

	ft_memcpy(&magic, file->data, sizeof(magic));
	if (magic != HM_MAGIC && magic != HM_MAGIC_64
			&& magic != HM_CIGAM && magic != HM_CIGAM_64)
		return (0);
	file->is_64 = magic == MH_MAGIC_64 || magic == MH_CIGAM_64;
	file->byte_order = (magic == MH_MAGIC || magic == MH_MAGIC_64) ? BIG : LITTLE;
	return (1);
}
