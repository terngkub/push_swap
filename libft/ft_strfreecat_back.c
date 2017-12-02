/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfreecat_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:55:39 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/27 17:14:38 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfreecat_back(char **str1, char *str2)
{
	char	*tmp;

	if (!(tmp = ft_strjoin(*str1, str2)))
		return (NULL);
	free(*str1);
	*str1 = tmp;
	return (*str1);
}
