/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 15:37:09 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/03 12:50:54 by terng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_stack_new(void)
{
	t_stack	*stack;

	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	stack->len = 0;
	return (stack);
}

t_stack *ft_stack_push(t_stack *stack, t_node *node)
{
	if (!stack)
		return (NULL);
	if (!node)
		return (stack);
	if (stack->len == 0)
	{
		stack->top = node;
		stack->bottom = node;
		stack->len++;
	}
	else
	{
		node->next = stack->top;
		stack->top = node;
		stack->len++;
	}
	return (stack);
}

t_stack *ft_stack_pushback(t_stack *stack, t_node *node)
{
	if (!stack)
		return (NULL);
	if (!node)
		return (stack);
	if (stack->len == 0)
	{
		stack->top = node;
		stack->bottom = node;
		stack->len++;
	}
	else
	{
		(stack->bottom)->next = node;
		stack->bottom = node;
		stack->len++;
	}
	return (stack);
}

t_node *ft_node_new(int n)
{
	t_node	*node;

	if (!(node = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	node->n = n;
	node->next = NULL;
	return (node);
}

t_node *ft_stack_pop(t_stack *stack)
{
	t_node *tmp;
	
	if (!stack)
		return (NULL);
	if (stack->len == 0)
		return (NULL);
	else if (stack->len == 1)
	{
		tmp = stack->top;
		stack->top = NULL;
		stack->bottom = NULL;
		stack->len--;
	}
	else
	{
		tmp = stack->top;
		stack->top = tmp->next;
		tmp->next = NULL;
		stack->len--;
	}
	return (tmp);
}
