/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:41:29 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/07 18:54:31 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_op(t_op *op)
{
	op->ra = 0;
	op->rra = 0;
	op->rb = 0;
	op->rrb = 0;
	op->rr = 0;
	op->rrr = 0;
	op->arrange = 0;
}

void	ft_copy_op(t_op *dst, t_op *src)
{
	dst->ra = src->ra;
	dst->rra = src->rra;
	dst->rb = src->rb;
	dst->rrb = src->rrb;
	dst->rr = src->rr;
	dst->rrr = src->rrr;
	dst->arrange = src->arrange;
}

void	ft_get_op_b(t_node *node_a, t_node *node_b, int len, t_op *op)
{
	int		target;
	int		index;
	int		i;
	char	trigger;

	if (!node_b || !(node_b->next))
		return ;
	target = -2147483648;
	index = 0;
	i = 0;
	trigger = 0;
	while (node_b)
	{
		if ((i == 0 || target < node_b->n) && node_b->n < node_a->n)
		{
			target = node_b->n;
			op->rb = (i > len / 2) ? 0 : i;
			op->rrb = (i > len / 2) ? len - i : 0;
			trigger = 1;
		}
		node_b = node_b->next;
		i++;
	}
	if (trigger == 0)
		op->arrange = 1;
}

void	ft_get_op(t_stack *stack_a, t_stack *stack_b, t_op *op)
{
	t_op	tmp;
	t_node	*node;
	int		min;
	int		i;

	node = stack_a->top;
	min = 2147483647;
	i = 0;
	while (node)
	{
		ft_init_op(&tmp);
		tmp.ra = ((size_t)i > stack_a->len / 2) ? 0 : i;
		tmp.rra = ((size_t)i > stack_a->len / 2) ? stack_a->len - i : 0;
		ft_get_op_b(node, stack_b->top, stack_b->len, &tmp);
		ft_optimize_operation(&tmp);
		if (tmp.ra + tmp.rra + tmp.rb + tmp.rrb + tmp.rr + tmp.rrr < min)
		{
			min = tmp.ra + tmp.rra + tmp.rb + tmp.rrb + tmp.rr + tmp.rrr;
			ft_copy_op(op, &tmp);
		}
		node = node->next;
		i++;
	}
}

void	ft_run_op(t_stack *stack_a, t_stack *stack_b, t_op *op)
{
	if (op->arrange)
		ft_stack_arrange_add(stack_b, op);
	while (op->ra--)
		ft_operate("ra", stack_a, stack_b, 1);
	while (op->rra--)
		ft_operate("rra", stack_a, stack_b, 1);
	while (op->rb--)
		ft_operate("rb", stack_a, stack_b, 1);
	while (op->rrb--)
		ft_operate("rrb", stack_a, stack_b, 1);
	while (op->rr--)
		ft_operate("rr", stack_a, stack_b, 1);
	while (op->rrr--)
		ft_operate("rrr", stack_a, stack_b, 1);
}
