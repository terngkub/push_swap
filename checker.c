/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:15:43 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/09 10:08:51 by terng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack 	*stack_b;
	char		*op;
	t_option	option;

	if (argc == 1)
		return (1);
	stack_a = ft_read_input(argc, argv, NULL);
	stack_b = ft_stack_new();
	option.debug = 0;
	option.colour = 0;
	while (get_next_line(0, &op) > 0)
	{
		ft_operate(op, stack_a, stack_b, 0, &option);
		free(op);
	}
	if (stack_b->len > 0 || !ft_stack_issorted(stack_a))
		ft_putendl("KO");
	else
		ft_putendl("OK");
	return (0);
}
