/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 08:39:38 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/19 08:40:39 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	section_free(t_section_list *list)
{
	free(list->section.name);
	free(list);
}

void	symbold_free(t_symbol_list *list)
{
	free(list->symbol.name);
	free(list);
}
