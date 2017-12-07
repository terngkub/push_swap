/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:49:36 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/07 18:49:46 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_optimize_rotate(t_op *op)
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
}

void	ft_optimize_revrotate(t_op *op)
{
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

void	ft_optimize_operation(t_op *op)
{
	ft_optimize_rotate(op);
	ft_optimize_revrotate(op);
}
