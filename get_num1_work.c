/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num1_work.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:44:01 by mjammie           #+#    #+#             */
/*   Updated: 2021/06/03 16:47:40 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_b_more_a(t_stack *stack_a, t_stack *head_b, t_mas *m)
{
	while (stack_a->next && head_b->num > stack_a->num)
	{
		stack_a = stack_a->next;
		m->num1++;
		if (head_b->num > stack_a->num && !stack_a->next)
			m->num1++;
	}
}

void	if_min_a_more_b(t_stack *stack_a, t_stack *head_b, t_mas *m)
{
	t_stack	*head_a;

	head_a = stack_a;
	if (min_num(stack_a) > head_b->num)
	{
		while (if_sort(stack_a))
		{
			stack_a = stack_a->next;
			m->num1++;
		}
		stack_a = head_a;
		if (m->num1 == ft_lstsize(head_a))
			m->flag_last = 1;
		else
			m->flag_last = 2;
	}
}

void	if_num1_eq_zero(t_stack *stack_a, t_stack *head_b, t_mas *m)
{
	while (stack_a && m->num1 == 0)
	{
		if (head_b->num > stack_a->num)
		{
			while (stack_a && head_b->num > stack_a->num)
			{
				m->po++;
				stack_a = stack_a->next;
			}
			m->flag = 1;
			break ;
		}
		m->nomer++;
		stack_a = stack_a->next;
	}
}

void	work_with_flags(t_mas *m)
{
	if (m->flag)
	{
		if ((m->nomer + m->po) < m->size_a / 2)
			m->num1 = m->nomer + m->po;
		else
			m->num1 = m->size_a - m->nomer - m->po;
	}
	if (m->num1 + 1 == m->size_a && !m->flag_last)
	{
		m->num1 = 1;
		m->flag_last = 1;
	}
}
