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

t_stack	*ft_selection_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*min_node;
	t_node	*check;
	size_t	index;
	size_t	min;

	while (stack_a->len > 1)
	{
		min_node = stack_a->top;
		check = min_node->next;
		min = 0;
		index = 1;
		while (check)
		{
			if (check->n < min_node->n)
			{
				min_node = check;
				min = index;
			}
			check = check->next;
			index++;
		}
		if (min == 1)
			ft_operate("sa", stack_a, stack_b, 1);
		else if (min > 1)
		{
			if (min <= stack_a->len / 2)
			{
				while (min--)
					ft_operate("ra", stack_a, stack_b, 1);
			}
			else
			{
				while (stack_a->len - min)
				{
					ft_operate("rra", stack_a, stack_b, 1);
					min++;
				}
					
			}
		}
		if (ft_stack_issorted(stack_a))
			break;
		ft_operate("pb", stack_a, stack_b, 1);
	}
	while (stack_b->len > 0)
		ft_operate("pa", stack_a, stack_b, 1);
	return (stack_a);
}

int		main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;

	stack_a = ft_read_input(argc, argv);
	stack_b = ft_stack_new();
	if (argc <= 2)
		return (0);
	else if (argc == 4)
		ft_sort_three(stack_a, stack_b);
	else
		ft_selection_sort(stack_a, stack_b);
	return (0);
}
