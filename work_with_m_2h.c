/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_m_2h.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:30:43 by mjammie           #+#    #+#             */
/*   Updated: 2021/06/04 14:08:30 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_n1_eq_n2(t_mas *m, t_stack **stack_a, t_stack **stack_b)
{
	if (m->flag == 2)
	{
		while (m->num1--)
			rrab(stack_a, "rra", 0);
		while (m->num2--)
			rab(*stack_b, "rb", 0);
		pab(stack_b, stack_a, "pa", 0);
	}
	else if (m->num1 <= ft_lstsize(*stack_a) / 2)
	{
		while (m->num1--)
			rr(*stack_a, *stack_b);
		pab(stack_b, stack_a, "pa", 0);
	}
	else
	{
		while (m->num1--)
			rrr(stack_a, stack_b);
		pab(stack_b, stack_a, "pa", 0);
	}
}

int	flag_and_n2_1h(t_mas *m, t_stack **stack_a, t_stack **stack_b)
{
	if (m->flag_last == 1 && m->num2 + 1 == m->size_b)
	{
		rrr(stack_a, stack_b);
		pab(stack_b, stack_a, "pa", 0);
		return (1);
	}
	else if (m->num2 <= m->size_b / 2)
	{
		while (m->num2--)
			rrab(stack_b, "rrb", 0);
		return (1);
	}
	return (0);
}

void	n2_2h(t_mas *m, t_stack **stack_a, t_stack **stack_b)
{
	m->count = m->size_b - m->num2;
	if (m->flag == 2)
	{
		while (m->num1--)
			rrab(stack_a, "rra", 0);
		while (m->count--)
			rrab(stack_b, "rrb", 0);
	}
	else
	{
		while (m->count--)
			rrab(stack_b, "rrb", 0);
		while (m->num1--)
		{
			if (m->flag_last == 1)
				rrab(stack_a, "rra", 0);
			else
				rab(*stack_a, "ra", 0);
		}
	}
	pab(stack_b, stack_a, "pa", 0);
}

void	if_2h(t_mas *m, t_stack **stack_a, t_stack **stack_b)
{
	if (m->num1 == m->num2)
		if_n1_eq_n2(m, stack_a, stack_b);
	else
	{
		if (m->flag_last == 1 && m->num2 + 1 == m->size_b)
		{
			rrr(stack_a, stack_b);
			pab(stack_b, stack_a, "pa", 0);
		}
		else if (m->num2 <= m->size_b / 2)
		{
			while (m->num2--)
				rrab(stack_b, "rrb", 0);
		}
		else
			n2_2h(m, stack_a, stack_b);
	}
}
