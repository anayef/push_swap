/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 20:17:22 by anayef            #+#    #+#             */
/*   Updated: 2023/08/05 22:20:44 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*creat_data(int value)
{
	t_stack	*data;

	data = malloc(sizeof(t_stack));
	if (!data)
		return (NULL);
	data->data = value;
	data->index = 0;
	data->next = NULL;
	return (data);
}

void	push(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*tmp;

	new_node = creat_data(value);
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		tmp = *stack;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
	}
}

t_stack	*creat_stack(int argc, char *argv[])
{
	int		i;
	int		value;
	t_stack	*stack;

	if (argc <= 1)
		return (NULL);
	i = 1;
	stack = NULL;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		push(&stack, value);
		i++;
	}
	return (stack);
}
