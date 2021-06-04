/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:58:23 by mjammie           #+#    #+#             */
/*   Updated: 2021/06/04 13:53:04 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialization(t_mas *m, t_stack *head_a, t_stack *head_b)
{
	m->flag_last = 0;
	m->num1 = 0;
	m->num2 = 0;
	m->po = 0;
	m->flag = 0;
	m->nomer = 0;
	m->size_a = ft_lstsize(head_a);
	m->size_b = ft_lstsize(head_b);
	m->count = 0;
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int	max;

	while (1)
	{
		if (if_sort(stack_a))
		{
			min = min_num(stack_a);
			max = max_num(stack_a);
			if (stack_a->num == max)
				rab(stack_a, "ra", 0);
			else if (stack_a->num == min)
				pab(&stack_a, &stack_b, "pb", 0);
			else if (stack_a->num > stack_a->next->num)
				sab(stack_a, "sa", 0);
			else
				pab(&stack_a, &stack_b, "pb", 0);
		}
		else if (stack_b && ft_lstsize(stack_a) < 5)
			pab(&stack_b, &stack_a, "pa", 0);
		else
			break ;
	}
}

void	algo(t_mas *m, t_stack **stack_a, t_stack **stack_b)
{
	if (m->num1 == 0 && m->num_srav < (*stack_a)->num && m->num2 == 0)
		pab(stack_b, stack_a, "pa", 0);
	else
	{
		if (m->num2 < m->size_b / 2)
			if_1h(m, stack_a, stack_b);
		else
			if_2h(m, stack_a, stack_b);
	}
}

void	while_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	int		*mas;
	t_mas	*m;

	mas = malloc(ft_lstsize(*stack_b) * sizeof(int));
	m = (struct s_mas *)malloc(sizeof(t_mas));
	if (m == 0 || mas == 0)
		return ;
	while (stack_b)
	{
		get_mas(mas, *stack_a, *stack_b);
		initialization(m, *stack_a, *stack_b);
		if (if_last_elem_b(stack_a, stack_b))
			break ;
		get_cc(m, *stack_a, *stack_b, mas);
		get_flags(*stack_a, *stack_b, m);
		algo(m, stack_a, stack_b);
	}
	free(mas);
	free (m);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int		stack_a_len;

	stack_a_len = ft_lstsize(stack_a);
	while (stack_a_len > 5)
	{
		pab(&stack_a, &stack_b, "pb", 0);
		stack_a_len--;
	}
	sort_five(stack_a, stack_b);
	while_stack_b(&stack_a, &stack_b);
	while (if_sort(stack_a))
		rab(stack_a, "ra", 0);
}
