/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:10:03 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/09 14:21:11 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_free(t_stack *stack)
{
	t_node	*node;
	t_node	*next;

	if (!stack)
		return ;
	node = stack->top;
	next = (node) ? node->next : NULL;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	free(stack);
}

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
