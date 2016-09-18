/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 09:22:36 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/23 14:38:16 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "buffer.h"
# include "file.h"

void	ft_nm(char *file_name, int print_name);
int		parse_file(t_file *file);
int		parse_file_header(t_file *file);
void	print_file(t_file *file);
void	buffer_read(t_buffer *buffer, void *dst, size_t len);

#endif
