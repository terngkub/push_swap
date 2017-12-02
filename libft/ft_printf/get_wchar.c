/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:03:32 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/30 12:05:58 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_one_byte(wchar_t c)
{
	char	*str;

	if (!(str = ft_strnew(1)))
		return (NULL);
	str[0] = c;
	return (str);
}

char	*ft_two_byte(wchar_t c)
{
	char	*str;

	if (!(str = ft_strnew(2)))
		return (NULL);
	str[0] = 192 + (c / 64);
	str[1] = 128 + (c % 64);
	return (str);
}

char	*ft_three_byte(wchar_t c)
{
	char	*str;

	if (!(str = ft_strnew(3)))
		return (NULL);
	str[0] = 224 + (c / (64 * 64));
	str[1] = 128 + (c / 64 % 64);
	str[2] = 128 + (c % 64);
	return (str);
}

char	*ft_four_byte(wchar_t c)
{
	char	*str;

	if (!(str = ft_strnew(4)))
		return (NULL);
	str[0] = 240 + (c / (64 * 64 * 64));
	str[1] = 128 + (c / (64 * 64) % 64);
	str[2] = 128 + (c / 64 % 64);
	str[3] = 128 + (c % 64);
	return (str);
}

char	*ft_getwchar(wchar_t c)
{
	if (c >= 0 && c < 128)
		return (ft_one_byte(c));
	else if (c < 2047)
		return (ft_two_byte(c));
	else if (c < 65535)
		return (ft_three_byte(c));
	else if (c < 1114111)
		return (ft_four_byte(c));
	return (NULL);
}
