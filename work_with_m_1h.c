/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_m_1h.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 21:35:05 by mjammie           #+#    #+#             */
/*   Updated: 2021/06/04 14:08:29 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_1h_eq(t_mas *m, t_stack **stack_a, t_stack **stack_b)
{
	if (m->num1 == m->num2)
	{
		if (m->flag_last == 1 || m->flag == 2)
		{
			while (m->num1--)
				rrab(stack_a, "rra", 0);
			while (m->num2--)
				rab(*stack_b, "rb", 0);
		}
		else
		{
			while (m->num2--)
				rr(*stack_a, *stack_b);
		}
		pab(stack_b, stack_a, "pa", 0);
	}
}

void	if_1h_fl_2(t_mas *m, t_stack **stack_a, t_stack **stack_b)
{
	while (m->num2--)
		rab(*stack_b, "rb", 0);
	if (m->num1 <= ft_lstsize(*stack_a) / 2)
	{
		while (m->num1--)
			rab(*stack_a, "ra", 0);
	}
	else
	{
		m->count = ft_lstsize(*stack_a) - m->num1;
		while (m->count--)
			rrab(stack_a, "rra", 0);
	}
	pab(stack_b, stack_a, "pa", 0);
}

void	if_1h_f_fl(t_mas *m, t_stack **stack_a, t_stack **stack_b)
{
	if (m->flag == 1)
	{
		while (m->num1--)
			rab(*stack_a, "ra", 0);
	}
	else if (m->flag == 2 || m->flag_last == 1)
	{
		while (m->num1--)
			rrab(stack_a, "rra", 0);
	}
	while (m->num2--)
		rab(*stack_b, "rb", 0);
	pab(stack_b, stack_a, "pa", 0);
}

void	how_n1_half(t_mas *m, t_stack **stack_a, t_stack **stack_b)
{
	if (m->num1 <= ft_lstsize(*stack_a) / 2)
	{
		while (m->num1--)
			rab(*stack_a, "ra", 0);
		while (m->num2--)
			rab(*stack_b, "rb", 0);
		pab(stack_b, stack_a, "pa", 0);
	}
	else
	{
		m->count = ft_lstsize(*stack_a) - m->num1;
		while (m->count--)
			rrab(stack_a, "rra", 0);
		while (m->num2--)
			rab(*stack_b, "rb", 0);
		pab(stack_b, stack_a, "pa", 0);
	}
}

void	if_1h(t_mas *m, t_stack **stack_a, t_stack **stack_b)
{
	if (m->num1 == m->num2)
		if_1h_eq(m, stack_a, stack_b);
	else
	{
		if (m->flag_last == 2)
			if_1h_fl_2(m, stack_a, stack_b);
		else if (m->flag || m->flag_last == 1)
			if_1h_f_fl(m, stack_a, stack_b);
		else
			how_n1_half(m, stack_a, stack_b);
	}
}
