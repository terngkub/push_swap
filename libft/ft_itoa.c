/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:36:40 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/23 17:34:13 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(long long int n)
{
	int			len;
	char		neg;
	char		*str;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_numlen(n);
	neg = 0;
	if (n < 0)
		neg = 1;
	if (!(str = ft_strnew(len + neg)))
		return (NULL);
	if (neg)
		str[0] = '-';
	while (n)
	{
		if (n < 0)
			str[len--] = ((n % 10) * -1) + '0';
		else
			str[--len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
