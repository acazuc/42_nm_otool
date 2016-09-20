/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 09:21:30 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 15:59:03 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# include "../../libft/include/libft.h"
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
typedef struct s_env				t_env;
typedef struct s_params				t_params;

void								ft_nm(t_env *env, char *file_name
		, int print_name);
void								file_parse(t_env *env, t_file *file
		, int print_name);
int									file_parse_header(t_file *file);
void								file_print(t_file *file);
int									buffer_read(t_buffer *buffer
		, void *addr, size_t len);
int									buffer_read_le(t_buffer *buffer
		, void *addr, size_t len);
int									buffer_set_position(t_buffer *buffer
		, size_t pos);
void								file_error(t_file *file
		, char *message);
t_archive							*archive_parse(t_env *env
		, t_file *file);
int									archive_parse_file_header(t_file *file
		, t_ar_file_header *f);
int									archive_files_push_back(
		t_ar_file_list **list, t_ar_file file);
void								archive_print(t_env *env
		, t_archive *archive);
int									object_parse(t_env *env
		, t_object *object);
int									object_parse_commands(t_env *env
		, t_object *object);
int									object_parse_command_symtab(
		t_env *env, t_object *object);
int									object_parse_command_segment_32(
		t_object *object);
int									object_parse_command_segment_64(
		t_object *object);
void								object_print(t_env *env
		, t_object *object, char *fname);
void								object_print_symbol_value(
		t_env *env, t_object *object, t_symbol *symbol);
void								object_print_symbol_sect_letter(
		t_object *object, t_symbol *symbol);
t_section							*get_section_by_index(
		t_segment_list *list, uint8_t index);
char								get_symbol_letter(
		t_object *object, t_symbol *symbol);
void								print_hex_1(uint8_t val);
void								print_hex_2(uint16_t val);
void								print_hex_4(uint32_t val);
void								print_hex_8(uint64_t val);
int									archive_parse_symdef(
		t_archive *archive, t_ar_file *file);
t_fat								*fat_parse(t_env *env, t_file *file);
void								fat_print(t_env *env, t_fat *fat);
void								fat_header_reverse(
		struct fat_header *fat_header);
void								fat_arch_reverse(
		struct fat_arch *fat_arch);
int									fat_files_push_back(
		t_fat *fat, t_fat_file fat_file);

void								struct_mach_header_reverse_32(
		struct mach_header *mach_header);
void								struct_mach_header_reverse_64(
		struct mach_header_64 *mach_header);

int									struct_object_header_read(
		t_object *object, t_object_header *object_header);

int									struct_symbol_read(
		t_object *object, t_symbol *symbol);
int									struct_symbol_list_push_back(
		t_env *env, t_symbol_list **list, t_symbol symbol);
void								struct_symbol_list_reverse(
		t_symbol_list **list);

void								struct_nlist_reverse_32(
		struct nlist *nlist);
void								struct_nlist_reverse_64(
		struct nlist_64 *nlist);

int									struct_segment_read_32(
		t_object *object, t_segment *segment);
int									struct_segment_read_64(
		t_object *object, t_segment *segment);
void								struct_segment_command_reverse_32(
		struct segment_command *command);
void								struct_segment_command_reverse_64(
		struct segment_command_64 *command);
int									struct_segment_list_push_back(
		t_segment_list **list, t_segment segment);
void								struct_segment_free(
		t_segment_list *segment);

int									struct_section_read_32(
		t_object *object, t_section *section);
int									struct_section_read_64(
		t_object *object, t_section *section);
void								struct_section_reverse_32(
		struct section *section);
void								struct_section_reverse_64(
		struct section_64 *section);
int									struct_section_list_push_back(
		t_section_list **list, t_section section);
void								struct_section_free(
		t_section_list *section);

void								struct_object_free(
		t_object *object);
void								struct_archive_free(
		t_archive *archive);
void								struct_fat_free(
		t_fat *fat);

int									parse_arguments(
		t_params *params, int ac, char **av);

enum								e_byte_order
{
	BO_LITTLE,
	BO_BIG
};

struct								s_params
{
	char							a;
	char							g;
	char							n;
	char							o;
	char							p;
	char							r;
	char							u;
	char							u_caps;
	char							x;
	char							j;
	char							a_caps;
};

struct								s_env
{
	t_params						params;
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
