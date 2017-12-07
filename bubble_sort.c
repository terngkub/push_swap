/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:15:09 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/06 17:48:27 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bubble_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;
	int		max;

	node = stack_a->top;
	max = -2147483648;
	while (node)
	{
		if (node->n > max)
			max = node->n;
		node = node->next;
	}
	while (!ft_stack_issorted(stack_a))
	{
		if (stack_a->top->n == max)
			ft_operate("ra", stack_a, stack_b, 1);
		else if (stack_a->top->n > stack_a->top->next->n)
			ft_operate("sa", stack_a, stack_b, 1);
		else
			ft_operate("ra", stack_a, stack_b, 1);
	}
}
