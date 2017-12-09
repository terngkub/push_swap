/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 17:59:11 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/09 12:27:32 by nkamolba         ###   ########.fr       */
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
		if (str[i] == '-')
			i++;
		if (str[i] < '0' || str[i] > '9')
			ft_error();
		if (str[i])
			i++;
	}
	n = ft_atoi(str);
	if (n > 2147483647 || n < -2147483648)
		ft_error();
}

void	ft_check_option(char **argv, int *i, t_option *option)
{
	if (ft_strcmp(argv[*i], "-v") == 0)
	{
		option->debug = 1;
		*i += 1;
	}
	else if (ft_strcmp(argv[*i], "-c") == 0)
	{
		option->colour = 1;
		*i += 1;
	}
	else if (ft_strcmp(argv[*i], "-vc") == 0 || ft_strcmp(argv[*i], "-cv") == 0)
	{
		option->debug = 1;
		option->colour = 1;
		*i += 1;
	}
}

t_stack	*ft_read_input(int argc, char **argv, t_option *option)
{
	t_stack	*stack;
	char	**arr;
	int		i;
	int		j;

	stack = ft_stack_new();
	i = 1;
	if (option)
		ft_check_option(argv, &i, option);
	while (i < argc)
	{
		if (!(arr = ft_strsplit(argv[i++], ' ')))
			ft_error();
		j = 0;
		while (arr[j])
		{
			ft_check_input(arr[j]);
			ft_stack_pushback(stack, ft_node_new(ft_atoi(arr[j])));
			free(arr[j++]);
		}
		free(arr);
	}
	ft_check_duplication(stack);
	return (stack);
}
