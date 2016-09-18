/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 09:21:30 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/18 12:56:04 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# include "../../libft/includes/libft.h"

# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/stab.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <fcntl.h>

typedef struct s_file			t_file;
typedef struct s_buffer			t_buffer;
typedef struct s_object			t_object;
typedef struct s_ar_file_header	t_ar_file_header;
typedef struct s_ar_file_list	t_ar_file_list;
typedef struct s_ar_file		t_ar_file;
typedef struct s_archive		t_archive;
typedef struct s_segment_cmd	t_segment_cmd;
typedef struct s_object_cmd		t_object_cmd;

void		ft_nm(char *file_name, int print_name);
void		parse_file(t_file *file, int print_name);
int			parse_file_header(t_file *file);
void		print_file(t_file *file);
int			buffer_read(t_buffer *buffer, void *addr, size_t len);
int			buffer_set_position(t_buffer *buffer, size_t pos);
void		file_error(t_file *file, char *message);
void		parse_archive(t_file *file);
int			parse_archive_file_header(t_file *file, t_ar_file_header *file_header);
int			archive_files_push_back(t_ar_file_list **list, t_ar_file file);
void		archive_print(t_archive *archive);
int			parse_object(t_object *object);
void		print_object(t_object *object);
size_t		get_object_header_size(t_object *object);
int			parse_object_segments(t_object *object);
int			parse_object_command_symtab(t_object *object, t_object_cmd *object_cmd);
int			buffer_read_string(t_buffer *buffer, char **addr);
void		print_hex_4(uint32_t val);

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

struct								s_object
{
	union
	{
		struct mach_header			header_32;
		struct mach_header_64		header_64;
		uint32_t					magic;
	}								header;
	enum e_byte_order				byte_order;
	char							is_64;
	t_buffer						buffer;
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
	char							name[21];
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

struct								s_segment_cmd
{
	union
	{
		struct segment_command		segment_cmd_32;
		struct segment_command_64	segment_cmd_64;
	}								segment_cmd;
};

struct								s_object_cmd
{
	struct load_command				load_command;
	char							*data;
	size_t							length;

};

#endif
