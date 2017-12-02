/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:04:47 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/30 13:25:25 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_handle_nullstr(size_t *len)
{
	*len += 6;
	return (ft_strdup("(null)"));
}

char	*ft_getstr(va_list ap, t_printf *conv, size_t *len)
{
	char	*tmp;
	char	*str;

	if (!(tmp = va_arg(ap, char*)))
		str = ft_strdup("(null)");
	else if (!(str = ft_strdup(tmp)))
		return (NULL);
	if (!ft_handle_precision_str(conv, &str)
			|| !ft_handle_minus(conv, &str)
			|| !ft_handle_zero(conv, &str)
			|| !ft_handle_width(conv, &str))
	{
		free(str);
		return (NULL);
	}
	*len += ft_strlen(str);
	return (str);
}

char	*ft_getwstr(va_list ap, t_printf *conv, size_t *len)
{
	wchar_t	*wstr;
	char	*str;
	char	*wchar;
	int		precision;

	if (!(wstr = va_arg(ap, wchar_t*)))
		return (ft_handle_nullstr(len));
	else if (!(str = ft_strnew(0)))
		return (NULL);
	precision = conv->has_precision ? conv->precision : 1;
	while (*wstr && precision)
	{
		if (!(wchar = ft_getwchar(*wstr++)))
			return (NULL);
		if (!(ft_strfreecat_back(&str, wchar)))
		{
			free(wchar);
			return (NULL);
		}
		free(wchar);
		precision = conv->has_precision ? precision - 1 : 1;
	}
	*len += ft_strlen(str);
	return (str);
}

char	*ft_getchar(va_list ap, t_printf *conv, size_t *len)
{
	char	tmp;
	char	*str;

	tmp = va_arg(ap, unsigned int);
	if (!(str = ft_strnew(1)))
		return (NULL);
	str[0] = tmp;
	conv->has_precision = 0;
	if (!ft_handle_minus(conv, &str)
			|| !ft_handle_zero(conv, &str)
			|| !ft_handle_width(conv, &str))
	{
		free(str);
		return (NULL);
	}
	if (tmp == 0 && conv->width > 1)
		*len += conv->width;
	else if (tmp == 0)
		*len += 1;
	else
		*len += ft_strlen(str);
	return (str);
}

char	*ft_getwrongspec(t_printf *conv, size_t *len)
{
	char	*str;

	if (!(str = ft_strnew(1)))
		return (NULL);
	str[0] = conv->spec;
	if (!ft_handle_minus(conv, &str)
			|| !ft_handle_zero(conv, &str)
			|| !ft_handle_width(conv, &str))
	{
		free(str);
		return (NULL);
	}
	*len += ft_strlen(str);
	return (str);
}
