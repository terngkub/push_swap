#include "push_swap.h"

int		ft_median(t_node *node, size_t len)
{
	int		arr[len];
	size_t	i;
	size_t	less;
	size_t	more;

	i = 0;
	while (i < len && node)
	{
		arr[i++] = node->n;
		node = node->next;
	}
	i = 0;
	while (i < len)
	{
		less = 0;
		more = 0;
		while (less + more < len && less <= len / 2 && more <= len / 2 + 1)
			(arr[less + more] < arr[i]) ? less++ : more++;
		if (less == len / 2 && more >= len / 2)
			break;
		i++;
	}
	return (arr[i]);
}

/*
 * 123 sb pa sb pa sa pa
 * 132 sb pa sb pa pa
 * 213 pa sb pa sa pa
 * 231 sb pa pa pa
 * 312 pa sb pa pa
 * 321 pa pa pa
 */

void	ft_quick_sort(t_stack *stack_a, t_stack *stack_b)
{
	int		median;
	size_t	half_len;

	while (stack_a->len > 2)
	{
		median = ft_median(stack_a->top, stack_a->len);
		half_len = stack_a->len / 2;
		while (stack_a->len > half_len + 1)
		{
			if (stack_a->top->n < median)
				ft_operate("pb", stack_a, stack_b, 1);
			else
				ft_operate("ra", stack_a, stack_b, 1);
		}
	}
	if (stack_a->top->n > stack_a->bottom->n)
		ft_operate("sa", stack_a, stack_b, 1);
	//phase 2
	//quick sort each one
	//
	//get the number of sort
	//if (number == 3)
	//	three_swap
	//else if (number == 2 && >)
	//	swap push push
	//
	//sort_len(stack_b, stack_a, len)
}

int		main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;

	stack_a = ft_read_input(argc, argv);
	stack_b = ft_stack_new();
	if (argc == 1)
		return (0);
	/*
	else if (stack_a->len)
		ft_sort_three(stack_a, stack_b);
	else
		ft_selection_sort(stack_a, stack_b);
	*/
	ft_shortest_sort(stack_a, stack_b);
	//ft_printf("%d\n", ft_stack_issorted(stack_a));
	//ft_stack_print(stack_a);
	return (0);
}
