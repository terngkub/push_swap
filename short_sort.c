/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 19:04:51 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/08 20:14:24 by terng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_short_sort(t_stack *stack_a, t_stack *stack_b, int debug)
{
	t_op	op;
	size_t	i;

	i = 45;
	while (stack_a->len > i)
	{
		ft_init_op(&op);
		ft_get_op(stack_a, stack_b, &op);
		ft_run_op(stack_a, stack_b, &op, debug);
		ft_operate("pb", stack_a, stack_b, 1, debug);
	}
	ft_stack_arrange(stack_a, stack_b, debug);
	ft_selection_sort(stack_a, stack_b, i, debug);
	while (i > 0 || stack_b->len > 0)
	{
		if (stack_b->len == 0 || (i && stack_b->top->n < stack_a->bottom->n))
		{
			ft_operate("rra", stack_a, stack_b, 1, debug);
			i--;
		}
		else
			ft_operate("pa", stack_a, stack_b, 1, debug);
	}
}
