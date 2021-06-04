/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:58:06 by mjammie           #+#    #+#             */
/*   Updated: 2021/06/04 13:56:38 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_num1_zero(t_stack *stack_a, t_mas *m)
{
	while (stack_a && m->num1 == 0)
	{
		if (m->num_srav > stack_a->num)
		{
			while (stack_a && m->num_srav > stack_a->num)
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

void	if_min_a(t_stack *stack_a, t_mas *m)
{
	t_stack	*head_a;

	head_a = stack_a;
	if (min_num(stack_a) > m->num_srav)
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

void	if_flag(t_mas *m)
{
	if (m->flag)
	{
		if ((m->nomer + m->po) < m->size_a / 2)
			m->num1 = m->nomer + m->po;
		else
		{
			m->flag = 2;
			m->num1 = m->size_a - m->nomer - m->po;
		}
	}
}

void	get_flags(t_stack *stack_a, t_stack *stack_b, t_mas *m)
{
	t_stack	*head_a;

	if_num1_zero(stack_a, m);
	head_a = stack_a;
	if_min_a(stack_a, m);
	if_flag(m);
	if (if_sort(stack_a) && m->num1 == 0 && m->min_num_a > min_num(stack_b) \
		&& m->flag != 2)
	{
		m->min_num_a = min_num(stack_a);
		while (stack_a->num != m->min_num_a)
		{
			m->num1++;
			stack_a = stack_a->next;
		}
	}
	if (m->num1 + 1 == ft_lstsize(head_a) && !m->flag_last)
	{
		m->num1 = 1;
		m->flag_last = 1;
	}
}
