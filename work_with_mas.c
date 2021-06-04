/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_mas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:10:23 by mjammie           #+#    #+#             */
/*   Updated: 2021/06/03 15:15:37 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_m(t_mas *m)
{
	m->num1 = 0;
	m->nomer = 0;
	m->po = 0;
	m->flag = 0;
	m->flag_last = 0;
}

int	get_num1(t_stack *stack_a, t_stack *head_b, t_mas *m)
{
	t_stack	*head_a;
	int		min_val_a;

	init_m(m);
	head_a = stack_a;
	if_b_more_a(stack_a, head_b, m);
	stack_a = head_a;
	if (m->num1 == ft_lstsize(stack_a))
	{
		m->num1 = 0;
		min_val_a = min_num(stack_a);
		while (stack_a->num != min_val_a)
		{
			m->num1++;
			stack_a = stack_a->next;
		}
		m->flag_last = 1;
		return (m->num1);
	}
	if_min_a_more_b(stack_a, head_b, m);
	if_num1_eq_zero(stack_a, head_b, m);
	work_with_flags(m);
	return (m->num1);
}

void	get_1st_half(t_mas *m)
{
	if (m->num1 == m->num2)
	{
		if (m->flag || m->flag_last)
			m->count = m->num1 + m->num2;
		else
			m->count = m->num2;
	}
	else
	{
		if (m->num1 <= m->size_a / 2)
			m->count = m->num1 + m->num2;
		else
		{
			if (m->flag_last == 1)
				m->count = m->size_a - m->num1 + 1 + m->num2;
			else if (m->flag_last == 2)
				m->count = (m->size_a - m->num1 - 1) + m->num2 + 1;
			else if (m->num2 == 0)
				m->count = m->size_a - m->num1 + 1;
			else
				m->count = m->size_a - m->num1 + m->num2;
		}
	}
}

void	scnd_half(t_mas *m)
{
	if (m->num1 == m->num2 && (m->num2 <= m->size_b / 2))
	{
		if (m->flag)
			m->count = m->num1 + m->num2;
		else if (m->num1 < m->size_a / 2)
			m->count = m->num2;
		else
			m->count = m->size_b - m->num2;
	}
	else
	{
		if (m->flag_last && m->num2 + 1 == m->size_b && m->num1 == m->size_a)
			m->count = 1;
		else if (m->num1 <= m->size_a / 2)
			m->count = m->num1 + (m->size_b - m->num2);
		else if (m->flag_last == 2)
			m->count = (m->size_a - m->num1 - 1) + (m->size_b - m->num2);
		else
			m->count = (m->size_a - m->num1) + (m->size_b - m->num2);
	}
}

void	get_mas(int *mas, t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*head_a;
	t_mas	*m;

	m = (struct s_mas *)malloc(sizeof(t_mas));
	head_a = stack_a;
	m->size_b = ft_lstsize(stack_b);
	m->size_a = ft_lstsize(head_a);
	m->stack_b_len = ft_lstsize(stack_b);
	m->num2 = 0;
	while (m->stack_b_len != 0)
	{
		m->count = 0;
		m->num1 = get_num1(stack_a, stack_b, m);
		if (m->num2 < m->size_b / 2)
			get_1st_half(m);
		else
			scnd_half(m);
		mas[m->num2] = m->count;
		if (stack_b->next)
			stack_b = stack_b->next;
		m->num2++;
		stack_a = head_a;
		m->stack_b_len--;
	}
	free(m);
}
