/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:34:03 by anayef            #+#    #+#             */
/*   Updated: 2023/08/04 22:17:21 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	find_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack != NULL)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	find_min(t_stack *stack)
{
	int	min_data;

	min_data = stack->data;
	while (stack != NULL)
	{
		if (stack->data < min_data)
			min_data = stack->data;
		stack = stack->next;
	}
	return (min_data);
}

int	find_element_position(t_stack *stack_a, int value)
{
	int	position;

	position = 0;
	while (stack_a != NULL)
	{
		if (value == stack_a->data)
			return (position);
		position++;
		stack_a = stack_a->next;
	}
	return (-1);
}
