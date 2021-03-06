/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 13:06:25 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/21 12:50:25 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static int	fat_print_test(t_env *env, t_fat *fat, int32_t arch)
{
	t_fat_file_list	*lst;

	lst = fat->files;
	while (lst)
	{
		if (lst->file.fat_arch.cputype == arch)
		{
			object_print(env, &lst->file.object, fat->file->name);
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}

void		fat_print(t_env *env, t_fat *fat, t_file *file, int first_file)
{
	if (!first_file)
		ft_putchar('\n');
	ft_putstr(file->name);
	ft_putendl(":");
	if (fat_print_test(env, fat, 0x01000007))
		return ;
	if (fat_print_test(env, fat, 0x01000000))
		return ;
	if (fat_print_test(env, fat, 0))
		return ;
}
