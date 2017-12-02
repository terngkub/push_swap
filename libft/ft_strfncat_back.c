/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfncat_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:09:55 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/27 17:43:27 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfncat_back(char **str1, char *str2,
			size_t len1, size_t len2)
{
	char	*word;
	size_t	i;

	if (!(word = ft_strnew(len1 + len2)))
		return (NULL);
	i = 0;
	while (i < len1)
	{
		word[i] = str1[0][i];
		i++;
	}
	while (i - len1 < len2)
	{
		word[i] = str2[i - len1];
		i++;
	}
	free(*str1);
	*str1 = word;
	return (*str1);
}
