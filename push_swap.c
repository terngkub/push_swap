#include "push_swap.h"

t_stack	*ft_sort_three(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;
	int		one;
	int		two;
	int		three;

	node = stack_a->top;
	one = node->n;
	two = node->next->n;
	three = node->next->next->n;
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
	return (stack_a);
}

int		main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;

	stack_a = ft_read_input(argc, argv);
	stack_b = ft_stack_new();
	if (argc == 4)
		ft_sort_three(stack_a, stack_b);
	return (0);
}
