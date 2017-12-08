/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:10:03 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/08 20:33:30 by terng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_stack_issorted(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node->next)
	{
		if (node->n > (node->next)->n)
			return (0);
		node = node->next;
	}
	return (1);
}

void	ft_stack_print(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node)
	{
		ft_putnbr(node->n);
		ft_putchar(' ');
		node = node->next;
	}
	ft_putchar('\n');
}

void	ft_debug(t_stack *stack_a, t_stack *stack_b)
{
	ft_putstr("a: ");
	ft_stack_print(stack_a);
	ft_putstr("b: ");
	ft_stack_print(stack_b);
	ft_putstr("_______________________________\n");
}
