/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:26:44 by mjammie           #+#    #+#             */
/*   Updated: 2021/05/18 20:44:28 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	minus;
	int	num_count;
	int	result;

	minus = 1;
	result = 0;
	num_count = 19;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		minus = minus * -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		if (!num_count--)
			return ((1 + minus) / (-2));
		result = result * 10 + *str - 48;
		str++;
	}
	return (result * minus);
}
