/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_arrange.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 19:08:25 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/08 20:22:03 by terng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_arrange(t_stack *stack_a, t_stack *stack_b, int debug)
{
	t_node	*node;
	t_op	op;
	int		max;
	int		i;

	node = stack_b->top;
	max = -2147483648;
	ft_init_op(&op);
	i = 0;
	while (node)
	{
		if (node->n > max)
		{
			max = node->n;
			op.rb = ((size_t)i > stack_b->len / 2 ? 0 : i);
			op.rrb = ((size_t)i > stack_b->len / 2 ? stack_b->len - i : 0);
		}
		node = node->next;
		i++;
	}
	while (op.rb--)
		ft_operate("rb", stack_a, stack_b, 1, debug);
	while (op.rrb--)
		ft_operate("rrb", stack_a, stack_b, 1, debug);
}

void	ft_stack_arrange_add(t_stack *stack_b, t_op *op)
{
	t_node	*node;
	t_op	tmp;
	int		max;
	int		i;

	node = stack_b->top;
	max = -2147483648;
	ft_init_op(&tmp);
	i = 0;
	while (node)
	{
		if (node->n > max)
		{
			max = node->n;
			tmp.rb = ((size_t)i > stack_b->len / 2 ? 0 : i);
			tmp.rrb = ((size_t)i > stack_b->len / 2 ? stack_b->len - i : 0);
		}
		node = node->next;
		i++;
	}
	op->rb += tmp.rb;
	op->rrb += tmp.rrb;
	ft_optimize_operation(op);
}
