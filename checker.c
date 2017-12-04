/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:15:43 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/03 14:03:00 by terng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*

size_t	ft_stack_len(t_stack *stack)
{
	t_node	*node;
	size_t	len;

	node = stack->top;
	len = 0;
	while (node)
	{
		node = node->next;
		len++;
	}
	return (len);
}
*/

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	char	*op;

	if (argc == 1)
		return (1);
	stack_a = ft_read_input(argc, argv);
	stack_b = ft_stack_new();
	while (get_next_line(0, &op) > 0)
		ft_operate(op, stack_a, stack_b, 0);
	if (stack_b->len > 0 || !ft_stack_issorted(stack_a))
		ft_putendl("KO");
	else
		ft_putendl("OK");
	return (0);
}
