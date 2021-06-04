/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   If_last_elem_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:53:02 by mjammie           #+#    #+#             */
/*   Updated: 2021/06/03 12:13:31 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_more_a(t_stack **stack_a, t_stack **stack_b, int min_num_a)
{
	if (!(*stack_b)->next && (*stack_b)->num > (*stack_a)->num)
	{
		if ((*stack_b)->num > max_num(*stack_a))
		{
			min_num_a = min_num(*stack_a);
			while ((*stack_a)->num != min_num_a)
				rab(*stack_a, "ra", 0);
		}
		else
		{
			while ((*stack_b)->num > (*stack_a)->num)
				rab(*stack_a, "ra", 0);
		}
		pab(stack_b, stack_a, "pa", 0);
	}
}

void	a_more_b(t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_b)->next && (*stack_b)->num < (*stack_a)->num)
	{
		if (min_num(*stack_a) > (*stack_b)->num)
		{
			while ((*stack_a)->num != min_num(*stack_a))
				rab(*stack_a, "ra", 0);
		}
		else
		{
			while ((*stack_b)->num < (*stack_a)->num)
				rab(*stack_a, "ra", 0);
			while ((*stack_b)->num > (*stack_a)->num)
				rab(*stack_a, "ra", 0);
		}
		pab(stack_b, stack_a, "pa", 0);
	}
}

int	if_last_elem_b(t_stack **stack_a, t_stack **stack_b)
{
	int	min_num_a;

	min_num_a = min_num(*stack_a);
	if (!(*stack_b)->next && (*stack_b)->num > (*stack_a)->num)
	{
		b_more_a(stack_a, stack_b, min_num_a);
		return (1);
	}
	else if (!(*stack_b)->next && (*stack_b)->num < (*stack_a)->num)
	{
		a_more_b(stack_a, stack_b);
		return (1);
	}
	return (0);
}
