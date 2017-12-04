/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 19:05:16 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/04 19:05:18 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
