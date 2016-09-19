/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_object_header_size.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 10:23:01 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/18 10:24:01 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

size_t	get_object_header_size(t_object *object)
{
	if (object->is_64)
		return (sizeof(object->header.header_64));
	return (sizeof(object->header.header_32));
}
