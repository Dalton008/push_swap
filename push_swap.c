/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 18:06:00 by mjammie           #+#    #+#             */
/*   Updated: 2021/06/04 13:53:08 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, t_stack *stack_a, t_stack *stack_b, char **argv)
{
	int		st_len;
	int		i;

	i = 0;
	stack_a = add_argv_in_stack(argc, argv);
	if (stack_a == 0)
	{
		write(1, "Error\n", 6);
		return ;
	}
	st_len = ft_lstsize(stack_a);
	stack_b = NULL;
	if (st_len <= 5 || !if_sort(stack_a))
		sort_five(stack_a, stack_b);
	else
		sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	push_swap(argc, stack_a, stack_b, argv);
}
