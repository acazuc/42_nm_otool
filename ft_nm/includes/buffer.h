/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:34:21 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/23 14:35:28 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H

typedef struct		s_buffer
{
	unsigned char	*data;
	size_t			offset;
}					t_buffer;

#endif
