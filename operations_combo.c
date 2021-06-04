/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_combo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 21:48:16 by mjammie           #+#    #+#             */
/*   Updated: 2021/05/31 18:22:49 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ssab(t_stack *stack_a, t_stack *stack_b)
{
	int	flag;

	flag = 1;
	sab(stack_a, "ss", 0);
	sab(stack_b, "", 1);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rab(stack_a, "rr", 0);
	rab(stack_b, "rr", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rrab(stack_a, "rrr", 0);
	rrab(stack_b, "rrr", 1);
}
