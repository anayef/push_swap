/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:45:19 by anayef            #+#    #+#             */
/*   Updated: 2023/08/05 22:47:50 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rb(t_stack **stack)
{
	do_ra(stack);
	ft_putstr("rb\n");
}

void	do_rrb(t_stack **stack)
{
	do_rra(stack);
	ft_putstr("rrb\n");
}
