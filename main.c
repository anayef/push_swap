/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:09:36 by anayef            #+#    #+#             */
/*   Updated: 2023/08/05 22:50:20 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

int	is_sorted(t_stack *stack)
{
	while (stack != NULL && stack->next != NULL)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	assign_index(t_stack *stack_a, int size)
{
	t_stack	*current;
	t_stack	*highest_element;
	int		highest_value;

	highest_element = stack_a;
	while (size > 0)
	{
		current = stack_a;
		highest_value = INT_MIN;
		while (current)
		{
			if (current->data == INT_MIN && current->index == 0)
				current->index = 1;
			else if (current->data > highest_value && current->index == 0)
			{
				highest_value = current->data;
				highest_element = current;
			}
			current = current->next;
		}
		if (highest_element != NULL)
			highest_element->index = size;
		size--;
	}
}

int	main(int ac, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	if (handle_input_errors(ac, argv) != 0)
		return (1);
	stack_b = NULL;
	stack_a = creat_stack(ac, argv);
	size = find_size(stack_a);
	assign_index(stack_a, size);
	sort(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
