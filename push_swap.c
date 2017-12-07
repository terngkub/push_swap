#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;

	stack_a = ft_read_input(argc, argv);
	stack_b = ft_stack_new();
	if (argc == 1 || stack_a->len == 1)
		return (0);
	else if (stack_a->len == 2 && stack_a->top->n > stack_a->top->next->n)
		ft_operate("ra", stack_a, stack_b, 1);
	else if (stack_a->len == 3)
		ft_sort_three(stack_a, stack_b);
	else if (stack_a->len < 45)
		ft_selection_sort(stack_a, stack_b, stack_a->len);
	else
		ft_shortest_sort(stack_a, stack_b);
	//ft_printf("%d\n", ft_stack_issorted(stack_a));
	//ft_stack_print(stack_a);
	return (0);
}
