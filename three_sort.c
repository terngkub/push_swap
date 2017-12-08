/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 19:04:42 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/08 20:10:44 by terng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three_sort(t_stack *stack_a, t_stack *stack_b, int debug)
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
		ft_operate("sa", stack_a, stack_b, 1, debug);
		ft_operate("ra", stack_a, stack_b, 1, debug);
	}
	else if (one > two && two < three && one < three)
		ft_operate("sa", stack_a, stack_b, 1, debug);
	else if (one < two && two > three && one > three)
		ft_operate("rra", stack_a, stack_b, 1, debug);
	else if (one > two && two < three && one > three)
		ft_operate("ra", stack_a, stack_b, 1, debug);
	else if (one > two && two > three)
	{
		ft_operate("ra", stack_a, stack_b, 1, debug);
		ft_operate("sa", stack_a, stack_b, 1, debug);
	}
}
