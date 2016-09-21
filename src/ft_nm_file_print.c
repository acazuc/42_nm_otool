/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm_file_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 12:39:31 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/21 12:46:34 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void		file_print(t_env *env, t_file *file, t_object *object
		, int print_file)
{
	if (print_file)
	{
		ft_putchar('\n');
		ft_putstr(file->name);
		ft_putendl(":");
	}
	object_print(env, object, file->name);
}
