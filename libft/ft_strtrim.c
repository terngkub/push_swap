/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:39:40 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/10 14:13:53 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_istrimspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	unsigned int	len;
	unsigned int	beg;
	unsigned int	end;
	char			*str;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	beg = 0;
	end = 0;
	str = (char *)s;
	while (ft_istrimspace(*str++))
		beg++;
	while (*str)
		str++;
	while (ft_istrimspace(*--str))
		end++;
	str = ft_strsub(s, beg, len - beg - end);
	return (str);
}
