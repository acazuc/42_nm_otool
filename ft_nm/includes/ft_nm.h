/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 09:21:30 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/19 11:46:15 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# include "../../libft/includes/libft.h"
# include <mach-o/ranlib.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/stab.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <fcntl.h>

typedef struct s_file				t_file;
typedef struct s_buffer				t_buffer;
typedef struct s_object				t_object;
typedef struct s_ar_file_header		t_ar_file_header;
typedef struct s_ar_file_list		t_ar_file_list;
typedef struct s_ar_file			t_ar_file;
typedef struct s_archive			t_archive;
typedef struct s_segment_cmd		t_segment_cmd;
typedef struct s_object_cmd			t_object_cmd;
typedef struct s_section			t_section;
typedef struct s_section_list		t_section_list;
typedef struct s_symbol				t_symbol;
typedef struct s_symbol_list		t_symbol_list;

void								ft_nm(char *file_name
		, int print_name);
void								parse_file(t_file *file
		, int print_name);
int									parse_file_header(t_file *file);
void								print_file(t_file *file);
int									buffer_read(t_buffer *buffer
		, void *addr, size_t len);
int									buffer_set_position(t_buffer *buffer
		, size_t pos);
void								file_error(t_file *file
		, char *message);
int									parse_archive(t_file *file);
int									parse_archive_file_header(t_file *file
		, t_ar_file_header *f);
int									archive_files_push_back(
		t_ar_file_list **list, t_ar_file file);
void								archive_print(t_archive *archive);
int									parse_object(t_object *object);
void								print_object(t_object *object);
size_t								get_object_header_size(t_object *object);
int									parse_object_segments(t_object *object);
int									parse_object_command_symtab(t_object *object
		, t_object_cmd *o);
int									parse_object_command_segment_32(
		t_object *object, t_object_cmd *o);
int									parse_object_command_segment_64(
		t_object *object, t_object_cmd *o);
int									buffer_read_string(
		t_buffer *buffer, char **addr);
void								print_hex_4(uint32_t val);
void								print_hex_8(uint64_t val);
int									object_sections_push_back(
		t_section_list **list, t_section section);
int									object_symbols_push_back(
		t_symbol_list **list, t_symbol symbol);
int									archive_parse_symdef(
		t_archive *archive, t_ar_file *file);

enum								e_byte_order
{
	BO_LITTLE,
	BO_BIG
};

struct								s_buffer
{
	unsigned char					*data;
	size_t							position;
	size_t							length;
};

struct								s_file
{
	t_buffer						buffer;
	char							*name;
	int								fd;
};

union								u_header
{
	struct mach_header				header_32;
	struct mach_header_64			header_64;
	uint32_t						magic;
};

struct								s_object
{
	union u_header					header;
	enum e_byte_order				byte_order;
	char							is_64;
	t_buffer						buffer;
	t_section_list					*sections;
	t_symbol_list					*symbols;
};

struct								s_ar_file_header
{
	char							identifier[17];
	char							modif_ts[13];
	char							owner_id[7];
	char							group_id[7];
	char							mode[9];
	char							size[11];
	char							end[3];
};

struct								s_ar_file
{
	char							*name;
	size_t							name_length;
	uint32_t						ran_strx;
	t_object						object;
	t_ar_file_header				header;
};

struct								s_ar_file_list
{
	t_ar_file						file;
	t_ar_file_list					*next;
};

struct								s_archive
{
	t_file							*file;
	t_ar_file_list					*files;
};

union								u_segment_cmd
{
	struct segment_command		segment_cmd_32;
	struct segment_command_64	segment_cmd_64;
};

struct								s_segment_cmd
{
	union u_segment_cmd				segment_cmd;
};

struct								s_object_cmd
{
	struct load_command				load_command;
	char							*data;
	size_t							length;
};

struct								s_section
{
	char							*name;
};

struct								s_section_list
{
	t_section						section;
	t_section_list					*next;
};

struct								s_symbol
{
	char							*name;
	uint64_t						value;
	uint8_t							section;
	uint8_t							external;
};

struct								s_symbol_list
{
	t_symbol						symbol;
	t_symbol_list					*next;
};

#endif
