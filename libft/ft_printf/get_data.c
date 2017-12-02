/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:04:06 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/29 17:57:18 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_getdata(va_list ap, t_printf *conv, size_t *len)
{
	char	*str;
	wchar_t	c;

	str = NULL;
	if (ft_strchr("diouxX", conv->spec))
		str = ft_getnum(ap, conv, len);
	else if (conv->spec == 's' && conv->length != 'l')
		str = ft_getstr(ap, conv, len);
	else if (conv->spec == 'c' && conv->length != 'l')
		str = ft_getchar(ap, conv, len);
	else if (conv->spec == 's' && conv->length == 'l')
		str = ft_getwstr(ap, conv, len);
	else if (conv->spec == 'c' && conv->length == 'l')
	{
		if (!(c = va_arg(ap, wchar_t)))
			*len += 1;
		str = ft_getwchar(c);
		*len += ft_strlen(str);
	}
	else if (conv->spec == 'p')
		str = ft_getptr(ap, conv, len);
	else
		str = ft_getwrongspec(conv, len);
	return (str);
}
