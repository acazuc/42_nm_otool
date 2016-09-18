/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 09:21:30 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/18 09:32:45 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# include "../../libft/includes/libft.h"

# include <mach-o/loader.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/mman.h>

typedef struct s_file			t_file;
typedef struct s_buffer			t_buffer;
typedef struct s_object			t_object;
typedef struct s_ar_file_header	t_ar_file_header;
typedef struct s_ar_file_list	t_ar_file_list;
typedef struct s_ar_file		t_ar_file;
typedef struct s_archive		t_archive;

void	ft_nm(char *file_name, int print_name);
void	parse_file(t_file *file);
int		parse_file_header(t_file *file);
void	print_file(t_file *file);
int		buffer_read(t_buffer *buffer, void *addr, size_t len);
int		buffer_set_position(t_buffer *buffer, size_t pos);
void	file_error(t_file *file, char *message);
void	parse_archive(t_file *file);
int		parse_archive_file_header(t_file *file, t_ar_file_header *file_header);
int		archive_files_push_back(t_ar_file_list **list, t_ar_file file);
void	archive_print(t_archive *archive);
int		parse_object(t_object *object);
void	print_object(t_object *object);

enum							e_byte_order
{
	BO_LITTLE,
	BO_BIG
};

enum							e_file_type
{
	TYPE_OBJECT,
	TYPE_ARCHIVE
};

struct							s_buffer
{
	unsigned char				*data;
	size_t						position;
	size_t						length;
};

struct							s_file
{
	uint32_t					magic;
	enum e_file_type			file_type;
	t_buffer					buffer;
	char						*name;
	char						is_object;
	int							fd;
};

struct							s_object
{
	union
	{
		struct mach_header		header_32;
		struct mach_header_64	header_64;
		uint32_t				magic;
	} header;
	enum e_byte_order			byte_order;
	char						is_64;
	t_buffer					buffer;
};

struct							s_ar_file_header
{
	char						identifier[17];
	char						modif_ts[13];
	char						owner_id[7];
	char						group_id[7];
	char						mode[9];
	char						size[11];
	char						end[3];
};

struct							s_ar_file
{
	char						name[21];
	t_object					object;
	t_ar_file_header			header;
};

struct							s_ar_file_list
{
	t_ar_file					file;
	t_ar_file_list				*next;
};

struct							s_archive
{
	t_file						*file;
	t_ar_file_list				*files;
};

#endif
