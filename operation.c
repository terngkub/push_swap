/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 17:54:30 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/09 10:19:23 by terng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_operate_s(char *op, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(op, "sa") == 0)
		ft_stack_swap(stack_a);
	else if (ft_strcmp(op, "sb") == 0)
		ft_stack_swap(stack_b);
	else if (ft_strcmp(op, "ss") == 0)
	{
		ft_stack_swap(stack_a);
		ft_stack_swap(stack_b);
	}
	else
		ft_error();
}

void	ft_operate_p(char *op, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(op, "pa") == 0)
		ft_stack_push(stack_a, ft_stack_pop(stack_b));
	else if (ft_strcmp(op, "pb") == 0)
		ft_stack_push(stack_b, ft_stack_pop(stack_a));
	else
		ft_error();
}

void	ft_operate_r(char *op, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(op, "ra") == 0)
		ft_stack_rotate(stack_a);
	else if (ft_strcmp(op, "rb") == 0)
		ft_stack_rotate(stack_b);
	else if (ft_strcmp(op, "rr") == 0)
	{
		ft_stack_rotate(stack_a);
		ft_stack_rotate(stack_b);
	}
	else if (ft_strcmp(op, "rra") == 0)
		ft_stack_revrotate(stack_a);
	else if (ft_strcmp(op, "rrb") == 0)
		ft_stack_revrotate(stack_b);
	else if (ft_strcmp(op, "rrr") == 0)
	{
		ft_stack_revrotate(stack_a);
		ft_stack_revrotate(stack_b);
	}
	else
		ft_error();
}

void	ft_print_colour(char *op)
{
		if (ft_strcmp(op, "sa") == 0)
			ft_putstr("\033[31m");
		else if (ft_strcmp(op, "sb") == 0)
			ft_putstr("\033[m1;31");
		else if (ft_strcmp(op, "ss") == 0)
			ft_putstr("\033[32m");
		else if (ft_strcmp(op, "pa") == 0)
			ft_putstr("\033[33m");
		else if (ft_strcmp(op, "pb") == 0)
			ft_putstr("\033[1;33m");
		else if (ft_strcmp(op, "ra") == 0)
			ft_putstr("\033[34m");
		else if (ft_strcmp(op, "rb") == 0)
			ft_putstr("\033[1;34m");
		else if (ft_strcmp(op, "rr") == 0)
			ft_putstr("\033[35m");
		else if (ft_strcmp(op, "rra") == 0)
			ft_putstr("\033[36m");
		else if (ft_strcmp(op, "rrb") == 0)
			ft_putstr("\033[1;36m");
		else if (ft_strcmp(op, "rrr") == 0)
			ft_putstr("\033[46m");
		ft_putstr(op);
		ft_putendl("\033[0m");
}

void	ft_operate(char *op, t_stack *stack_a, t_stack *stack_b, char print,
			t_option *option)
{
	if (op[0] == 's')
		ft_operate_s(op, stack_a, stack_b);
	else if (op[0] == 'p')
		ft_operate_p(op, stack_a, stack_b);
	else if (op[0] == 'r')
		ft_operate_r(op, stack_a, stack_b);
	else
		ft_error();
	if (print && option->colour)
		ft_print_colour(op);
	else if (print)
		ft_putendl(op);
	if (option->debug)
		ft_debug(stack_a, stack_b);
}
