/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 06:34:00 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/18 15:13:00 by acazuc           ###   ########.fr       */
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

int		buffer_set_position(t_buffer *buffer, size_t pos)
{
	if (pos > buffer->length)
		return (0);
	buffer->position = pos;
	return (1);
}

int		buffer_read_string(t_buffer *buffer, char **addr)
{
	char	tmp[2];
	char	*str;
	char	c;

	tmp[1] = '\0';
	if (!(str = malloc(sizeof(*str))))
		return (0);
	str[0] = '\0';
	while (buffer_read(buffer, &c, sizeof(c)))
	{
		if (c == '\0')
		{
			*addr = str;
			return (1);
		}
		tmp[0] = c;
		if (!(str = ft_strjoin_free1(str, tmp)))
			return (0);
	}
	return (0);
}
