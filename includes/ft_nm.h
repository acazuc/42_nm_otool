/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 09:21:30 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/21 11:08:33 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# include "common.h"

void								ft_nm(t_env *env, char *file_name
		, int print_name);
void								object_print_symbol_value(
		t_env *env, t_object *object, t_symbol *symbol);
void								object_print_symbol_sect_letter(
		t_object *object, t_symbol *symbol);
t_section							*get_section_by_index(
		t_segment_list *list, uint8_t index);
char								get_symbol_letter(
		t_object *object, t_symbol *symbol);

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
