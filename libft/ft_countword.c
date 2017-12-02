/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:12:17 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/09 13:34:48 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countword(char const *s, char c)
{
	int	count;

	if (!s)
		return (0);
	count = 0;
	if (*s && *s != c)
		count++;
	while (*++s)
		if (*s != c && *(s - 1) == c)
			count++;
	return (count);
}
