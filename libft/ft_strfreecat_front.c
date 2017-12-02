/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfreecat_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:56:03 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/24 14:46:28 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfreecat_front(char **str1, char *str2)
{
	char	*tmp;

	if (!(tmp = ft_strjoin(str2, *str1)))
		return (NULL);
	free(*str1);
	*str1 = tmp;
	return (*str1);
}
