/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_symbol_list_push_back.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 14:27:46 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 14:32:00 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int		replace(t_env *env, t_symbol *lst, t_symbol *new)
{
	if (env->params.p)
		return (0);
	if (env->params.n)
	{
		if (env->params.r)
			return (lst->value < new->value);
		return (lst->value >= new->value);
	}
	if (env->params.r)
		return (ft_strcmp(lst->name, new->name) < 0);
	return (ft_strcmp(lst->name, new->name) >= 0);
}

static void		swap(t_symbol_list *new, t_symbol_list *lst, t_symbol_list *prv
		, t_symbol_list **list)
{
	new->next = lst;
	if (prv)
		prv->next = new;
	else
		(*list) = new;
}

static void		insert(t_env *env, t_symbol_list **list, t_symbol_list *new)
{
	t_symbol_list		*prv;
	t_symbol_list		*lst;

	if (!(*list))
	{
		*list = new;
		return ;
	}
	lst = *list;
	prv = NULL;
	while (lst)
	{
		if (replace(env, &lst->symbol, &new->symbol))
		{
			swap(new, lst, prv, list);
			return ;
		}
		if (!lst->next)
		{
			lst->next = new;
			return ;
		}
		prv = lst;
		lst = lst->next;
	}
}

int				struct_symbol_list_push_back(t_env *env, t_symbol_list **list
		, t_symbol symbol)
{
	t_symbol_list		*new;

	if (!(new = malloc(sizeof(*new))))
		return (0);
	if (symbol.name == NULL)
		if (!(symbol.name = ft_strdup("")))
			return (0);
	new->symbol = symbol;
	new->next = NULL;
	insert(env, list, new);
	return (1);
}
