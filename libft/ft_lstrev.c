/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:13:12 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/15 14:33:18 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **lst)
{
	t_list	*old;
	t_list	*new;

	if (!(*lst) || !((*lst)->next))
		return ;
	old = NULL;
	while (*lst)
	{
		new = (*lst)->next;
		(*lst)->next = old;
		old = *lst;
		*lst = new;
	}
	*lst = old;
}
