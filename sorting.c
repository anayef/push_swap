/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 21:28:00 by anayef            #+#    #+#             */
/*   Updated: 2023/08/06 13:20:33 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_else(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	j;
	int	num;
	int	max_bits;
	int	size;

	max_bits = 0;
	size = find_size(*stack_a);
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			num = (*stack_a)->index;
			if ((num >> i) & 1)
				do_ra(stack_a);
			else
				do_pb(stack_a, stack_b);
		}
		while (*stack_b)
			do_pa(stack_a, stack_b);
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = find_size(*stack_a);
	if (!is_sorted(*stack_a))
	{
		if (size == 2)
			sort_two (stack_a);
		else if (size == 3)
			sort_three (stack_a);
		else if (size > 3 && size <= 5)
			sort_five (stack_a, stack_b);
		else
			sort_else(stack_a, stack_b);
	}
}
