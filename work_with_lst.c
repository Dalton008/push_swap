/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:37:39 by mjammie           #+#    #+#             */
/*   Updated: 2021/06/03 16:50:31 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack->next != 0)
	{
		i++;
		stack = stack->next;
	}
	return (i + 1);
}

t_stack	*create_new_node(int num)
{
	t_stack	*list;

	list = (struct s_stack *)malloc(sizeof(t_stack));
	if (list == 0)
		return (0);
	list->num = num;
	list->next = NULL;
	return (list);
}

void	print(t_stack *stack)
{
	while (stack)
	{
		printf("%d\n", stack->num);
		stack = stack->next;
	}
}	

int	while_len(char **split, t_stack **new_stack)
{
	int		len_sp;
	int		n;

	len_sp = len_split(split);
	n = 0;
	while (len_sp--)
	{
		if (check_split(split[n]))
			return (0);
		else if (ft_atoi(split[n]) >= -2147483648 || \
				ft_atoi(split[n]) <= 2147483647)
			(*new_stack)->num = ft_atoi(split[n]);
		else
			return (0);
		if (len_sp != 0)
		{
			(*new_stack)->next = create_new_node(ft_atoi(split[n]));
			(*new_stack) = (*new_stack)->next;
		}
		n++;
	}
	free_split(split);
	return (1);
}

t_stack	*add_argv_in_stack(int argc, char **argv)
{
	t_stack	*new_stack;
	t_stack	*first;
	int		i;
	char	**split;

	i = 1;
	new_stack = create_new_node(0);
	first = new_stack;
	if (new_stack == 0)
		return (0);
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!while_len(split, &new_stack))
			return (0);
		if (i != argc - 1)
		{
			new_stack->next = create_new_node(0);
			new_stack = new_stack->next;
		}
		i++;
	}
	if (duplicate(first))
		return (0);
	return (first);
}
