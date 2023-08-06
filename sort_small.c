/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 21:38:09 by anayef            #+#    #+#             */
/*   Updated: 2023/08/04 22:18:16 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_the_highest(t_stack *stack)
{
	int	highest;

	highest = 0;
	while (stack != NULL)
	{
		if (stack->data > highest)
			highest = stack->data;
		stack = stack->next;
	}
	return (highest);
}

void	sort_two(t_stack **stack)
{
	int	highest;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	highest = find_the_highest(*stack);
	if (highest == (*stack)->data)
		do_sa(stack);
	else
		return ;
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	size;
	int	pos;

	size = find_size(*stack_a);
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	while (size > 3)
	{
		min = find_min(*stack_a);
		pos = find_element_position(*stack_a, min);
		while ((*stack_a)->data != min)
		{
			if (pos < 2)
				do_ra(stack_a);
			else
				do_rra(stack_a);
		}
		do_pb(stack_a, stack_b);
		size --;
	}
	sort_three(stack_a);
	while (*stack_b != NULL)
		do_pa(stack_a, stack_b);
}

void	sort_three(t_stack **stack)
{
	int	highest;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	highest = find_the_highest(*stack);
	if (highest == (*stack)->data)
	{
		do_ra(stack);
		if (!is_sorted(*stack))
			do_sa(stack);
	}
	else if (highest == (*stack)->next->data)
	{
		do_rra(stack);
		if (!is_sorted(*stack))
			do_sa(stack);
	}
	else
	{
		if (!is_sorted(*stack))
			do_sa(stack);
	}
}
