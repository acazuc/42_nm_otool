/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool_file_print.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 12:46:43 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/21 12:59:19 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

void	file_print(t_env *env, t_file *file, t_object *object, int first_file)
{
	(void)first_file;
	ft_putstr(file->name);
	ft_putendl(":");
	object_print(env, object, file->name);
}
