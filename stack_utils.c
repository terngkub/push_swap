#include "push_swap.h"

int		ft_stack_issorted(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node->next)
	{
		if (node->n > (node->next)->n)
			return (0);
		node = node->next;
	}
	return (1);
}

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

