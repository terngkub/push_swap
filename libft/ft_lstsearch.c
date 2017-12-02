/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:07:23 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/15 15:21:19 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstsearch(t_list *lst, char *str)
{
	while (lst)
	{
		if (ft_strcmp(str, lst->content) == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
