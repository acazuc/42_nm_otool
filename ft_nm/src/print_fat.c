/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 13:06:25 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 13:09:03 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int	print_fat_test(t_env *env, t_fat *fat, int32_t arch)
{
	t_fat_file_list	*lst;

	lst = fat->files;
	while (lst)
	{
		if (lst->file.fat_arch.cputype == arch)
		{
			print_object(env, &lst->file.object);
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}

void		print_fat(t_env *env, t_fat *fat)
{
	if (print_fat_test(env, fat, 0x01000007))
		return ;
	if (print_fat_test(env, fat, 0x01000000))
		return ;
	if (print_fat_test(env, fat, 0))
		return ;
}
