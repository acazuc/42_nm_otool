/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 11:00:04 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/21 11:37:05 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OTOOL_H
# define FT_OTOOL_H

# include "common.h"

void			ft_otool(t_env *env, char *file, int print_name);

struct			s_params
{
	char		a;
	char		s_caps;
	char		f;
	char		h;
	char		l;
	char		t;
	char		d;
};

struct			s_env
{
	t_params	params;
};

#endif
