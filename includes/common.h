/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 10:57:53 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/21 10:59:19 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "../libft/include/libft.h"
# include <mach-o/ranlib.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/stab.h>
# include <mach-o/fat.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <errno.h>
# include <fcntl.h>

typedef struct s_file				t_file;
typedef struct s_ar_file_header		t_ar_file_header;
typedef struct s_ar_file			t_ar_file;
typedef struct s_ar_file_list		t_ar_file_list;
typedef struct s_archive			t_archive;
typedef struct s_fat				t_fat;
typedef struct s_fat_file			t_fat_file;
typedef struct s_fat_file_list		t_fat_file_list;
typedef struct s_buffer				t_buffer;
typedef struct s_object_header		t_object_header;
typedef struct s_object				t_object;
typedef struct s_segment			t_segment;
typedef struct s_segment_list		t_segment_list;
typedef struct s_section			t_section;
typedef struct s_section_list		t_section_list;
typedef struct s_symbol				t_symbol;
typedef struct s_symbol_list		t_symbol_list;

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

struct								s_object_header
{
	uint32_t						magic;
	cpu_type_t						cputype;
	cpu_subtype_t					cpusubtype;
	uint32_t						filetype;
	uint32_t						ncmds;
	uint32_t						sizeofcmds;
	uint32_t						flags;
};

struct								s_object
{
	t_object_header					header;
	enum e_byte_order				byte_order;
	char							is_64;
	t_buffer						buffer;
	t_segment_list					*segments;
	t_symbol_list					*symbols;
};

struct								s_file
{
	t_buffer						buffer;
	char							*name;
	int								fd;
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

struct								s_fat
{
	enum e_byte_order				byte_order;
	t_file							*file;
	t_fat_file_list					*files;
};

struct								s_fat_file
{
	t_object						object;
	struct fat_arch					fat_arch;
};

struct								s_fat_file_list
{
	t_fat_file						file;
	t_fat_file_list					*next;
};

struct								s_segment
{
	uint32_t						cmd;
	uint32_t						cmdsize;
	char							segname[16];
	uint64_t						vmaddr;
	uint64_t						vmsize;
	uint64_t						fileoff;
	uint64_t						filesize;
	vm_prot_t						maxprot;
	vm_prot_t						initprot;
	uint32_t						nsects;
	uint32_t						flags;
	t_section_list					*sections;
};

struct								s_segment_list
{
	t_segment						segment;
	t_segment_list					*next;
};

struct								s_section
{
	char							sectname[16];
	char							segname[16];
	uint64_t						addr;
	uint64_t						size;
	uint32_t						offset;
	uint32_t						align;
	uint32_t						reloff;
	uint32_t						nreloc;
	uint32_t						flags;
	t_buffer						buffer;
};

struct								s_section_list
{
	t_section						section;
	t_section_list					*next;
};

struct								s_symbol
{
	char							*name;
	uint32_t						strx;
	uint8_t							type;
	uint8_t							sect;
	uint16_t						desc;
	uint64_t						value;
};

struct								s_symbol_list
{
	t_symbol						symbol;
	t_symbol_list					*next;
};

#endif
