/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:11:54 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/09 12:11:56 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getword(char const *s, char c)
{
	int		len;
	char	*str;

	len = ft_wordlen(s, c);
	str = ft_strsub(s, 0, len);
	if (!str)
		return (NULL);
	return (str);
}
