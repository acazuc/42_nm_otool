/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 06:34:00 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 11:52:58 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int		buffer_read(t_buffer *buffer, void *addr, size_t len)
{
	if (buffer->position + len > buffer->length)
		return (0);
	ft_memcpy(addr, buffer->data + buffer->position, len);
	buffer->position += len;
	return (1);
}

int		buffer_read_le(t_buffer *buffer, void *addr, size_t len)
{
	size_t	i;
	char	tmp;

	if (!(buffer_read(buffer, addr, len)))
		return (0);
	i = 0;
	while (i < len / 2)
	{
		tmp = ((char*)addr)[i];
		((char*)addr)[i] = ((char*)addr)[len - i - 1];
		((char*)addr)[len - i - 1] = tmp;
		i++;
	}
	return (1);
}

int		buffer_set_position(t_buffer *buffer, size_t pos)
{
	if (pos > buffer->length)
		return (0);
	buffer->position = pos;
	return (1);
}
