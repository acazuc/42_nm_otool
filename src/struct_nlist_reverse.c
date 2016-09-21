/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_nlist_reverse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 09:15:12 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 09:17:26 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	struct_nlist_reverse_32(struct nlist *nlist)
{
	nlist->n_un.n_strx = ft_swap_uint(nlist->n_un.n_strx);
	nlist->n_desc = ft_swap_short(nlist->n_desc);
	nlist->n_value = ft_swap_uint(nlist->n_value);
}

void	struct_nlist_reverse_64(struct nlist_64 *nlist)
{
	nlist->n_un.n_strx = ft_swap_uint(nlist->n_un.n_strx);
	nlist->n_desc = ft_swap_ushort(nlist->n_desc);
	nlist->n_value = ft_swap_ulong(nlist->n_value);
}
