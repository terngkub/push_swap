/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 19:04:51 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/06 16:14:42 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct		s_op
{
	int				ra;
	int				rra;
	int				rb;
	int				rrb;
	int				rr;
	int				rrr;
	int				arrange;
}					t_op;

void	ft_index_b(t_node *node_a, t_node *node_b, int len, t_op *op)
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
	op->rb = 0;
	op->arrange = 0;
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

void	ft_optimize_operation(t_op *op)
{
		if (op->ra > 0 && op->rb > 0)
		{
			if (op->ra >= op->rb)
			{
				op->rr = op->rb;
				op->ra = op->ra - op->rr;
				op->rb = 0;
			}
			else
			{
				op->rr = op->ra;
				op->ra = 0;
				op->rb = op->rb - op->rr;
			}
		}
		if (op->rra > 0 && op->rrb > 0)
		{
			if (op->rra >= op->rrb)
			{
				op->rrr = op->rrb;
				op->rra = op->rra - op->rrr;
				op->rrb = 0;
			}
			else
			{
				op->rrr = op->rra;
				op->rra = 0;
				op->rrb = op->rrb - op->rrr;
			}
		}
}

void	ft_index(t_stack *stack_a, t_stack *stack_b, t_op *op)
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
		tmp.ra = 0;
		tmp.rra = 0;
		tmp.rb = 0;
		tmp.rrb = 0;
		tmp.rr = 0;
		tmp.rrr = 0;
		tmp.arrange = 0;
		tmp.ra = ((size_t)i > stack_a->len / 2) ? 0 : i;
		tmp.rra = ((size_t)i > stack_a->len / 2) ? stack_a->len - i : 0;
		ft_index_b(node, stack_b->top, stack_b->len, &tmp);
		ft_optimize_operation(&tmp);
		if (tmp.ra + tmp.rra + tmp.rb + tmp.rrb + tmp.rr + tmp.rrr + tmp.arrange < min)
		{
			min = tmp.ra + tmp.rra + tmp.rb + tmp.rrb + tmp.rr + tmp.rrr + tmp.arrange;
			op->ra = tmp.ra;
			op->rra = tmp.rra;
			op->rb = tmp.rb;
			op->rrb = tmp.rrb;
			op->rr = tmp.rr;
			op->rrr = tmp.rrr;
			op->arrange = tmp.arrange;
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

void	ft_stack_arrange_add(t_stack *stack_a, t_stack *stack_b, t_op *op)
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
	op->rb += rb;
	op->rrb += rrb;
	ft_optimize_operation(op);
	(void)stack_a;
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
		op.ra = 0;
		op.rra = 0;
		op.rb = 0;
		op.rrb = 0;
		op.rr = 0;
		op.rrr = 0;
		op.arrange = 0;
		ft_index(stack_a, stack_b, &op);
		if (op.arrange)
			ft_stack_arrange_add(stack_a, stack_b, &op);
		while (op.ra--)
			ft_operate("ra", stack_a, stack_b, 1);
		while (op.rra--)
			ft_operate("rra", stack_a, stack_b, 1);
		while (op.rb--)
			ft_operate("rb", stack_a, stack_b, 1);
		while (op.rrb--)
			ft_operate("rrb", stack_a, stack_b, 1);
		while (op.rr--)
			ft_operate("rr", stack_a, stack_b, 1);
		while (op.rrr--)
			ft_operate("rrr", stack_a, stack_b, 1);
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
