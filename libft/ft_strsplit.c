/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:06:41 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/09 13:36:28 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		words;
	int		i;

	if (s == NULL)
		return (NULL);
	words = ft_countword(s, c);
	arr = (char **)ft_memalloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < words)
	{
		s = ft_skipc(s, c);
		arr[i] = ft_getword(s, c);
		if (!arr[i])
			return (NULL);
		s = ft_skiptoc(s, c);
		i++;
	}
	return (arr);
}
