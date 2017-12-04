/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 19:04:51 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/04 19:05:42 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
int		ft_move_num(t_stack *stack_a, t_stack *stack_b, int index_a, t_node *node_a)
{
	t_node	*node_b;
	t_node	*place;
	int		i;
	int		index_b;

	node_b = stack_b->top;
	i = 0;
	while (node_b)
	{
		if (place->n < node_b->n && node_b->n < node_a->n)
		{
			place = node->b;
			index_b = i;
		}
		i++;
		node_b = node_b->next;
	}
	return (index_a + index_b);
}

void	ft_shortest_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;
	t_node	*target_a;
	t_node	*target_b;
	int		i;
	int		move_num;
	int		target_num;

	while (!ft_stack_issorted(stack_a))
	{
		node = stack_a->top;
		i = 0;
		target_num = 2147483648;
		while (node)
		{
			move_num = ft_move_num(stack_a, stack_b, i, node);
			if (move_num < target_num)
			{
				target_num = move_num;
				target_a = node;
			}
			node = node->next;
			i++;
		}
		node = stack->top;
		while (node->n != target_a->n)
		{
			ft_operate("ra", stack_a, stack_b, 1);
			
		
	}
}
*/
