/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfncat_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:13:23 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/27 18:15:03 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfncat_front(char **str1, char *str2,
			size_t len1, size_t len2)
{
	char	*word;
	size_t	i;

	if (!(word = ft_strnew(len1 + len2)))
		return (NULL);
	i = 0;
	while (i < len2)
	{
		word[i] = str2[i];
		i++;
	}
	while (i - len2 < len1)
	{
		word[i] = str1[0][i - len2];
		i++;
	}
	free(*str1);
	*str1 = word;
	return (*str1);
}
