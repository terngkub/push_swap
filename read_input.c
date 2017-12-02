/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 17:59:11 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/02 18:03:25 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_duplication(t_stack *stack)
{
	t_node	*node;
	t_node	*check;

	node = stack->top;
	while (node->next)
	{
		check = node->next;
		while (check)
		{
			if (node->n == check->n)
				ft_error();
			check = check->next;
		}
		node = node->next;
	}
}

void	ft_check_input(char *str)
{
	int			i;
	long long	n;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error();
		i++;
	}
	n = ft_atoi(str);
	if (n > 2147483647 || n < -2147483648)
		ft_error();
}

t_stack	*ft_read_input(int argc, char **argv)
{
	t_stack	*stack;
	char	**arr;
	int		i;
	int		j;
	
	stack = ft_stack_new();
	i = 1;
	while (i < argc)
	{
		if (!(arr = ft_strsplit(argv[i++], ' ')))
			ft_error();
		j = 0;
		while (arr[j])
		{
			ft_check_input(arr[j]);
			ft_stack_pushback(stack, ft_node_new(ft_atoi(arr[j++])));
		}
	}
	ft_check_duplication(stack);
	return (stack);
}
