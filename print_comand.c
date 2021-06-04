/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_comand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:42:58 by mjammie           #+#    #+#             */
/*   Updated: 2021/06/03 16:47:32 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return ;
	while (str[len])
		len++;
	write(1, str, len);
	write(1, "\n", 1);
}

void	print_comand(char *str, int flag)
{
	static int	count;

	if (!flag)
	{
		ft_putstr(str);
		count++;
	}
}
