/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 17:54:22 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/07 18:09:32 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_swap(t_stack *stack)
{
	t_node	*tmp;

	if (!stack)
		return (NULL);
	if (stack->top == stack->bottom)
		return (stack);
	tmp = stack->top;
	stack->top = (stack->top)->next;
	tmp->next = (stack->top)->next;
	(stack->top)->next = tmp;
	if (!(tmp->next))
		stack->bottom = tmp;
	return (stack);
}

t_stack	*ft_stack_rotate(t_stack *stack)
{
	t_node	*tmp;

	if (!stack)
		return (NULL);
	if (stack->top == stack->bottom)
		return (stack);
	tmp = stack->top;
	stack->top = (stack->top)->next;
	(stack->bottom)->next = tmp;
	tmp->next = NULL;
	stack->bottom = tmp;
	return (stack);
}

t_stack	*ft_stack_revrotate(t_stack *stack)
{
	t_node *tmp;

	if (!stack)
		return (NULL);
	if (stack->top == stack->bottom)
		return (stack);
	tmp = stack->top;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	(stack->bottom)->next = stack->top;
	stack->top = stack->bottom;
	stack->bottom = tmp;
	return (stack);
}
