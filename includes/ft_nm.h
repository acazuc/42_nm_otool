/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 09:21:30 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/21 10:59:42 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# include "common.h"

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

#endif
