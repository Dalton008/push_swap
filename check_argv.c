/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:38:28 by mjammie           #+#    #+#             */
/*   Updated: 2021/06/03 16:50:58 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_argv(int argc, char **argv)
{
	int	n;
	int	i;

	i = 1;
	while (i < argc)
	{
		n = 0;
		while (argv[i][n])
		{
			if (argv[i][n] >= 48 && argv[i][n] <= 57)
				n++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	len_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int	check_split(char *split)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (split[len])
		len++;
	while (i < len)
	{
		if (split[i] >= 48 && split[i] <= 57)
			i++;
		else
			return (1);
	}
	return (0);
}

int	duplicate(t_stack *stack)
{
	t_stack	*head;
	int		dup;

	dup = stack->num;
	while (stack)
	{
		head = stack;
		head = head->next;
		while (head)
		{
			if (dup == head->num)
				return (1);
			head = head->next;
		}
		stack = stack->next;
		if (stack)
			dup = stack->num;
	}
	return (0);
}

void	free_split(char **split)
{
	int	n;

	n = 0;
	while (split[n])
		free(split[n++]);
	free(split);
}
