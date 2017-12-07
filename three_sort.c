/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 19:04:42 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/07 18:06:38 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three_sort(t_stack *stack_a, t_stack *stack_b)
{
	int		one;
	int		two;
	int		three;

	one = stack_a->top->n;
	two = stack_a->top->next->n;
	three = stack_a->top->next->next->n;
	if (one < two && two < three)
		;
	else if (one < two && two > three && one < three)
	{
		ft_operate("sa", stack_a, stack_b, 1);
		ft_operate("ra", stack_a, stack_b, 1);
	}
	else if (one > two && two < three && one < three)
		ft_operate("sa", stack_a, stack_b, 1);
	else if (one < two && two > three && one > three)
		ft_operate("rra", stack_a, stack_b, 1);
	else if (one > two && two < three && one > three)
		ft_operate("ra", stack_a, stack_b, 1);
	else if (one > two && two > three)
	{
		ft_operate("ra", stack_a, stack_b, 1);
		ft_operate("sa", stack_a, stack_b, 1);
	}
}
