/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 18:11:57 by mjammie           #+#    #+#             */
/*   Updated: 2021/06/04 13:53:19 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}				t_stack;

typedef struct s_mas
{
	int				size_a;
	int				size_b;
	int				stack_b_len;
	int				count;
	int				num1;
	int				num2;
	int				nomer;
	int				po;
	int				flag;
	int				flag_last;
	int				num_srav;
	int				min_num_a;
	int				min_num_b;
}				t_mas;

int		ft_lstsize(t_stack *stack);
t_stack	*create_new_node(int num);
t_stack	*add_argv_in_stack(int argc, char **argv);
int		ft_atoi(char *str);
int		ft_lstsize(t_stack *stack);
void	sab(t_stack *stack, char *str, int flag);
void	ssab(t_stack *stack_a, t_stack *stack_b);
int		pab(t_stack **stack_from, t_stack **stack_to, char *str, int flag);
void	rab(t_stack *stack, char *str, int flag);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rrab(t_stack **stack, char *str, int flag);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	print(t_stack *stack);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
void	sort(t_stack *stack_a, t_stack *stack_b);

void	get_mas(int *mas, t_stack *stack_a, t_stack *stack_b);
int		min_val_in_mas(int mas[], int size_b);
int		max_num(t_stack *stack);
int		min_num(t_stack *stack);
int		if_sort(t_stack *stack);
int		get_nom_1st_min_val(int *mas, int size);
t_stack	*add_argv_in_stack(int argc, char **argv);

void	if_b_more_a(t_stack *stack_a, t_stack *head_b, t_mas *m);
void	if_min_a_more_b(t_stack *stack_a, t_stack *head_b, t_mas *m);
void	if_num1_eq_zero(t_stack *stack_a, t_stack *head_b, t_mas *m);
void	work_with_flags(t_mas *m);

void	print_comand(char *str, int flag);

int		if_last_elem_b(t_stack **stack_a, t_stack **stack_b);
void	get_cc(t_mas *m, t_stack *stack_a, t_stack *stack_b, int *mas);
void	get_flags(t_stack *stack_a, t_stack *stack_b, t_mas *m);

void	work_with_m(t_mas *m, t_stack *stack_a, t_stack *stack_b);

void	if_1h(t_mas *m, t_stack **stack_a, t_stack **stack_b);
void	if_2h(t_mas *m, t_stack **stack_a, t_stack **stack_b);

char	**ft_split(char const *s, char c);
int		check_argv(int argc, char **argv);

int		len_split(char **split);
int		check_split(char *split);
int		duplicate(t_stack *stack);
void	free_split(char **split);

#endif