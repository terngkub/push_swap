/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 19:04:51 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/06 10:54:08 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct		s_op
{
	int				ra;
	int				rra;
	int				b;
}					t_op;

int		ft_index_b(t_node *node_a, t_node *node_b)
{
	int		target;
	int		index;
	int		i;
	char	trigger;

	if (!node_b || !(node_b->next))
		return (0);
	target = -2147483648;
	index = 0;
	i = 0;
	trigger = 0;
	while (node_b)
	{
		if ((i == 0 || target < node_b->n) && node_b->n < node_a->n)
		{
			target = node_b->n;
			index = i;
			trigger = 1;
		}
		node_b = node_b->next;
		i++;
	}
	if (trigger == 0)
		return (-1);
	return (index);
}

void	ft_index(t_stack *stack_a, t_stack *stack_b, t_op *op)
{
	t_node	*node;
	int		min;
	int		ra;
	int		rra;
	int		i;
	int		index_b;
	
	node = stack_a->top;
	min = 2147483647;
	i = 0;
	while (node)
	{
		ra = ((size_t)i > stack_a->len / 2) ? 0 : i;
		rra = ((size_t)i > stack_a->len / 2) ? stack_a->len - i : 0;
		index_b = ft_index_b(node, stack_b->top);
		if (ra + rra + ((index_b == -1) ? 1 : index_b) < min)
		{
			min = ra + rra + ((index_b == -1) ? 1 : index_b);
			op->ra = ra;
			op->rra = rra;
			op->b = index_b;
		}
		node = node->next;
		i++;
	}
}

void	ft_stack_arrange(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;
	int		max;
	int		rb;
	int		rrb;
	int		i;

	node = stack_b->top;
	max = -2147483648;
	rb = 0;
	rrb = 0;
	i = 0;
	while (node)
	{
		if (node->n > max)
		{
			max = node->n;
			rb = ((size_t)i > stack_b->len / 2 ? 0 : i);
			rrb = ((size_t)i > stack_b->len / 2 ? stack_b->len - i : 0);
		}
		node = node->next;
		i++;
	}
	while (rb--)
		ft_operate("rb", stack_a, stack_b, 1);
	while (rrb--)
		ft_operate("rrb", stack_a, stack_b, 1);
}

void	ft_debug(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("a :");
	ft_stack_print(stack_a);
	ft_printf("b :");
	ft_stack_print(stack_b);
	ft_printf("______________________\n");
}


void	ft_shortest_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_op	op;

	while (stack_a->len > 0)
	{
		ft_index(stack_a, stack_b, &op);
		while (op.ra--)
			ft_operate("ra", stack_a, stack_b, 1);
		while (op.rra--)
			ft_operate("rra", stack_a, stack_b, 1);
		while (op.b > 0)
		{
			ft_operate("rb", stack_a, stack_b, 1);
			op.b--;
		}
		if (op.b == -1)
		{
			ft_stack_arrange(stack_a, stack_b);
			ft_operate("pb", stack_a, stack_b, 1);
			ft_operate("rb", stack_a, stack_b, 1);
		}
		else
			ft_operate("pb", stack_a, stack_b, 1);
		//ft_debug(stack_a, stack_b);
	}
	ft_stack_arrange(stack_a, stack_b);
	//ft_debug(stack_a, stack_b);
	while (stack_b->len > 0)
	{
		ft_operate("pa", stack_a, stack_b, 1);
		//ft_debug(stack_a, stack_b);
	}
}
