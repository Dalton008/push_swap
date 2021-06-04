/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:00:19 by mjammie           #+#    #+#             */
/*   Updated: 2021/06/01 14:38:22 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_nom_1st_min_val(int *mas, int size)
{
	int	nom_1st_min_val;
	int	min_val_mas;

	nom_1st_min_val = 0;
	min_val_mas = min_val_in_mas(mas, size);
	while (size--)
	{
		if (mas[nom_1st_min_val] == min_val_mas)
			return (nom_1st_min_val);
		nom_1st_min_val++;
	}
	return (0);
}

int	min_val_in_mas(int mas[], int size_b)
{
	int	r;
	int	min;

	r = 0;
	min = mas[r];
	while (r < size_b)
	{
		if (mas[r] < min)
			min = mas[r];
		r++;
	}
	return (min);
}

int	max_num(t_stack *stack)
{
	int	res;

	res = stack->num;
	while (stack)
	{
		if (stack->num > res)
			res = stack->num;
		stack = stack->next;
	}
	return (res);
}

int	min_num(t_stack *stack)
{
	int	res;

	res = stack->num;
	while (stack)
	{
		if (stack->num < res)
			res = stack->num;
		stack = stack->next;
	}
	return (res);
}

int	if_sort(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (1);
		stack = stack->next;
	}
	return (0);
}
