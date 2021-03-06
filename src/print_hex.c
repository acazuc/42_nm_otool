/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 12:51:32 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/20 14:45:04 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	print_hex_1(uint8_t val)
{
	int		tmp;
	int		i;

	i = 1;
	while (i >= 0)
	{
		tmp = (val >> (i * 4)) & 0xf;
		if (tmp >= 10)
			ft_putchar(tmp - 10 + 'a');
		else
			ft_putchar(tmp + '0');
		i--;
	}
}

void	print_hex_2(uint16_t val)
{
	int		tmp;
	int		i;

	i = 3;
	while (i >= 0)
	{
		tmp = (val >> (i * 4)) & 0xf;
		if (tmp >= 10)
			ft_putchar(tmp - 10 + 'a');
		else
			ft_putchar(tmp + '0');
		i--;
	}
}

void	print_hex_4(uint32_t val)
{
	int		tmp;
	int		i;

	i = 7;
	while (i >= 0)
	{
		tmp = (val >> (i * 4)) & 0xf;
		if (tmp >= 10)
			ft_putchar(tmp - 10 + 'a');
		else
			ft_putchar(tmp + '0');
		i--;
	}
}

void	print_hex_8(uint64_t val)
{
	int		tmp;
	int		i;

	i = 15;
	while (i >= 0)
	{
		tmp = (val >> (i * 4)) & 0xf;
		if (tmp >= 10)
			ft_putchar(tmp - 10 + 'a');
		else
			ft_putchar(tmp + '0');
		i--;
	}
}
