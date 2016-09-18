/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 10:25:45 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/23 14:35:43 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include "byte_order.h"

typedef struct				s_file
{
	struct mach_header		header;
	struct mach_header_64	header_64;
	t_byte_order			byte_order;
	uint32_t				is_64;
	t_buffer				buffer;
	char					*name;
	int						fd;
}							t_file;

#endif
