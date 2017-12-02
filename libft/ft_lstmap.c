/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:27:01 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/09 16:07:00 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*old;
	t_list	*new;

	if (!lst)
		return (NULL);
	old = NULL;
	if (lst->next)
		old = ft_lstmap(lst->next, f);
	new = f(lst);
	ft_lstadd(&old, new);
	return (new);
}
