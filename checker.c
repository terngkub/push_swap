/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:15:43 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/02 18:33:03 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_issorted(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	if (stack_b->top)
	{
		ft_putendl("KO");
		return ;
	}
	node = stack_a->top;
	while (node->next)
	{
		if (node->n > (node->next)->n)
		{
			ft_putendl("KO");
			return ;
		}
		node = node->next;
	}
	ft_putendl("OK");
}

/*
void	ft_stack_print(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node)
	{
		ft_putnbr(node->n);
		ft_putchar(' ');
		node = node->next;
	}
	ft_putchar('\n');
}

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
		ft_operate(op, stack_a, stack_b);
	ft_stack_issorted(stack_a, stack_b);
	return (0);
}
