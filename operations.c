/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:11:28 by mjammie           #+#    #+#             */
/*   Updated: 2021/06/01 13:40:02 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sab(t_stack *stack, char *str, int flag)
{
	int	num;

	if (ft_lstsize(stack) <= 1)
		return ;
	num = stack->num;
	stack->num = stack->next->num;
	stack->next->num = num;
	print_comand(str, flag);
}

int	pab(t_stack **stack_from, t_stack **stack_to, char *str, int flag)
{
	t_stack	*new;
	t_stack	*to;
	t_stack	*from;

	to = *stack_to;
	from = *stack_from;
	if (!from)
		return (0);
	new = from;
	from = from->next;
	*stack_from = from;
	if (!to)
	{
		to = new;
		to->next = NULL;
		*stack_to = to;
	}
	else
	{
		new->next = to;
		*stack_to = new;
	}
	print_comand(str, flag);
	return (0);
}

void	rab(t_stack *stack, char *str, int flag)
{
	int	num_top;

	num_top = stack->num;
	while (stack->next)
	{
		stack->num = stack->next->num;
		stack = stack->next;
		if (stack->next == 0)
			stack->num = num_top;
	}
	print_comand(str, flag);
}

void	rrab(t_stack **stack, char *str, int flag)
{
	t_stack	*p;
	t_stack	*last;
	t_stack	*head;

	head = *stack;
	last = head;
	while (last->next)
	{
		p = last;
		last = last->next;
	}
	last->next = *stack;
	p->next = NULL;
	*stack = last;
	print_comand(str, flag);
}
