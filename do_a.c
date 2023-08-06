/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:25:11 by anayef            #+#    #+#             */
/*   Updated: 2023/08/05 22:47:38 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa(t_stack **stack)
{
	int	tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = tmp;
	ft_putstr("sa\n");
}

void	do_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_b)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
	}
	ft_putstr("pa\n");
}

void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
	}
	ft_putstr("pb\n");
}

void	do_ra(t_stack **stack_a)
{
	t_stack	*tmp;

	if (*stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = NULL;
		find_last(*stack_a)->next = tmp;
	}
	ft_putstr("ra\n");
}

void	do_rra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (*stack_a)
	{
		tmp = *stack_a;
		prev = NULL;
		while (tmp->next)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		if (prev)
		{
			prev->next = NULL;
			tmp->next = *stack_a;
			*stack_a = tmp;
		}
	}
	ft_putstr("rra\n");
}
