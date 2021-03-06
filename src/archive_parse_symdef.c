/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive_parse_symdef.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 09:29:55 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/19 11:23:58 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static t_ar_file_list	*get_file(t_ar_file_list *src, char *file)
{
	t_ar_file_list	*new;

	if (!(new = malloc(sizeof(*new))))
		return (NULL);
	new->next = NULL;
	while (src)
	{
		if (!ft_strcmp(file, src->file.name))
		{
			new->file = src->file;
			return (new);
		}
		src = src->next;
	}
	return (NULL);
}

static void				swap(t_ar_file_list *new, t_ar_file_list *lst
		, t_ar_file_list *prv, t_ar_file_list **list)
{
	new->next = lst;
	if (prv)
		prv->next = new;
	else
		*list = new;
}

static int				push_entry(t_ar_file_list **dst, t_ar_file_list *new
		, t_ar_file_list *prv)
{
	t_ar_file_list	*lst;

	if (!(*dst))
	{
		*dst = new;
		return (1);
	}
	lst = *dst;
	prv = NULL;
	while (lst)
	{
		if (new->file.ran_strx < lst->file.ran_strx)
		{
			swap(new, lst, prv, dst);
			return (1);
		}
		if (!lst->next)
		{
			lst->next = new;
			return (1);
		}
		prv = lst;
		lst = lst->next;
	}
	return (1);
}

int						archive_parse_symdef(t_archive *archive
		, t_ar_file *file)
{
	t_ar_file_list	*lst;
	t_ar_file_list	*new;
	struct ranlib	stru;
	uint32_t		size;
	uint32_t		count;

	if (!(buffer_read(&file->object.buffer, &size, sizeof(size))))
		return (0);
	lst = NULL;
	count = 0;
	while (count < size)
	{
		if (!(buffer_read(&file->object.buffer, &stru, sizeof(stru))))
			return (0);
		if (!(new = get_file(archive->files, (char*)archive->file->buffer.data
					+ 16 + 12 + 6 + 6 + 8 + 10 + 2 + stru.ran_off)))
			return (0);
		new->file.ran_strx = stru.ran_un.ran_strx;
		if (!push_entry(&lst, new, NULL))
			return (0);
		count += sizeof(stru);
	}
	archive->files = lst;
	return (1);
}
