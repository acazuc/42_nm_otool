/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 11:26:56 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/19 11:29:12 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

void	ft_nm(char *file_name, int print_name);
void	parse_file(t_file *file, int print_name);
int		parse_file_header(t_file *file);
void	print_file(t_file *file);
int		buffer_read(t_buffer *buffer, void *addr, size_t len);
int		buffer_set_position(t_buffer *buffer, size_t pos);
void	file_error(t_file *file, char *message);
int		parse_archive(t_file *file);
int		parse_archive_file_header(t_file *file, t_ar_file_header *f);
int		archive_files_push_back(t_ar_file_list **list, t_ar_file file);
void	archive_print(t_archive *archive);
int		parse_object(t_object *object);
void	print_object(t_object *object);
size_t	get_object_header_size(t_object *object);
int		parse_object_segments(t_object *object);
int		parse_object_command_symtab(t_object *object, t_object_cmd *o);
int		parse_object_command_segment_32(t_object *object, t_object_cmd *o);
int		parse_object_command_segment_64(t_object *object, t_object_cmd *o);
int		buffer_read_string(t_buffer *buffer, char **addr);
void	print_hex_4(uint32_t val);
void	print_hex_8(uint64_t val);
int		object_sections_push_back(t_section_list **list, t_section section);
int		object_symbols_push_back(t_symbol_list **list, t_symbol symbol);
int		archive_parse_symdef(t_archive *archive, t_ar_file *file);

#endif
