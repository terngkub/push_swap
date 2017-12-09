/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:09:07 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/09 17:54:39 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_option	option;
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (argc == 1)
		return (0);
	option.print = 1;
	option.debug = 0;
	option.colour = 0;
	stack_a = ft_read_input(argc, argv, &option);
	stack_b = ft_stack_new();
	if (argc == 1 || stack_a->len == 1)
		return (0);
	else if (stack_a->len == 2 && stack_a->top->n > stack_a->top->next->n)
		ft_operate("ra", stack_a, stack_b, &option);
	else if (stack_a->len == 3)
		ft_three_sort(stack_a, stack_b, &option);
	else if (stack_a->len < 45)
		ft_selection_sort(stack_a, stack_b, stack_a->len, &option);
	else
		ft_short_sort(stack_a, stack_b, &option, stack_a->len);
	ft_stack_free(stack_a);
	ft_stack_free(stack_b);
	return (0);
}
