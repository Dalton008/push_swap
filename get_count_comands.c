/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_count_comands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:21:51 by mjammie           #+#    #+#             */
/*   Updated: 2021/06/04 13:53:46 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	plus_num2(int *mas, t_mas *m, t_stack *stack_b)
{
	int		nom_1st_min_val;

	nom_1st_min_val = get_nom_1st_min_val(mas, m->size_b);
	while (nom_1st_min_val)
	{
		stack_b = stack_b->next;
		nom_1st_min_val--;
		m->num2++;
	}
	m->num_srav = stack_b->num;
}

void	plus_num1(t_mas *m, t_stack *stack_a)
{
	t_stack	*head_a;
	int		min_num_a;

	head_a = stack_a;
	while (m->num_srav > stack_a->num && stack_a->next)
	{
		stack_a = stack_a->next;
		m->num1++;
		if (m->num_srav > stack_a->num && !stack_a->next)
			m->num1++;
	}
	stack_a = head_a;
	if (m->num1 == ft_lstsize(stack_a))
	{
		m->num1 = 0;
		min_num_a = min_num(stack_a);
		while (stack_a->num != min_num_a)
		{
			m->num1++;
			stack_a = stack_a->next;
		}
	}
}

void	get_cc(t_mas *m, t_stack *stack_a, t_stack *stack_b, int *mas)
{
	t_stack	*head_a;
	t_stack	*head_b;

	head_a = stack_a;
	head_b = stack_b;
	plus_num2(mas, m, stack_b);
	stack_b = head_b;
	plus_num1(m, stack_a);
}
