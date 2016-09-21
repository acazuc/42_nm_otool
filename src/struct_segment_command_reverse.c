/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_segment_command_reverse.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 09:58:43 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 10:04:03 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	struct_segment_command_reverse_32(struct segment_command *command)
{
	command->cmd = ft_swap_uint(command->cmd);
	command->cmdsize = ft_swap_uint(command->cmdsize);
	command->vmaddr = ft_swap_uint(command->vmaddr);
	command->vmsize = ft_swap_uint(command->vmsize);
	command->fileoff = ft_swap_uint(command->fileoff);
	command->filesize = ft_swap_uint(command->filesize);
	command->maxprot = ft_swap_uint(command->maxprot);
	command->initprot = ft_swap_uint(command->initprot);
	command->nsects = ft_swap_uint(command->nsects);
	command->flags = ft_swap_uint(command->flags);
}

void	struct_segment_command_reverse_64(struct segment_command_64 *command)
{
	command->cmd = ft_swap_uint(command->cmd);
	command->cmdsize = ft_swap_uint(command->cmdsize);
	command->vmaddr = ft_swap_ulong(command->vmaddr);
	command->vmsize = ft_swap_ulong(command->vmsize);
	command->fileoff = ft_swap_ulong(command->fileoff);
	command->filesize = ft_swap_ulong(command->filesize);
	command->maxprot = ft_swap_uint(command->maxprot);
	command->initprot = ft_swap_uint(command->initprot);
	command->nsects = ft_swap_uint(command->nsects);
	command->flags = ft_swap_uint(command->flags);
}
