/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:35:19 by anayef            #+#    #+#             */
/*   Updated: 2023/08/05 22:20:28 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}	t_stack;

int		ft_isdigit(int c);
void	ft_putstr(char *s);
int		ft_atoi(const char *nptr);
int		ft_strcmp(const char *str1, const char *str2);
size_t	ft_strlen(const char *str);
int		handle_input_errors(int argc, char *argv[]);
int		find_min(t_stack *stack);
int		find_size(t_stack *stack);
int		is_sorted(t_stack *stack);
int		find_element_position(t_stack *stack_a, int value);
void	free_stack(t_stack *stack);
void	do_sa(t_stack **stack);
void	do_pa(t_stack **stack_a, t_stack **stack_b);
void	do_pb(t_stack **stack_a, t_stack **stack_b);
void	do_ra(t_stack **stack_a);
void	do_rra(t_stack **stack_a);
void	do_rb(t_stack **stack);
void	do_rrb(t_stack **stack);
t_stack	*find_last(t_stack *stack);
t_stack	*creat_stack(int argc, char *argv[]);
void	sort_two(t_stack **stack);
void	sort_three(t_stack **stack);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	sort(t_stack **stack_a, t_stack **stack_b);

#endif