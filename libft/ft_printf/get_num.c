/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:02:32 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/29 16:47:46 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_getnum_signed(va_list ap, char length)
{
	if (length == 'H')
		return ((char)va_arg(ap, int));
	else if (length == 'h')
		return ((short int)va_arg(ap, int));
	else if (length == 'l')
		return (va_arg(ap, long int));
	else if (length == 'L')
		return (va_arg(ap, long long int));
	else if (length == 'j')
		return (va_arg(ap, intmax_t));
	else if (length == 'z')
		return (va_arg(ap, size_t));
	return (va_arg(ap, int));
}

size_t	ft_getnum_unsigned(va_list ap, char length)
{
	if (length == 'H')
		return ((unsigned char)va_arg(ap, unsigned int));
	else if (length == 'h')
		return ((unsigned short)va_arg(ap, unsigned int));
	else if (length == 'l')
		return (va_arg(ap, unsigned long int));
	else if (length == 'L')
		return (va_arg(ap, unsigned long long int));
	else if (length == 'j')
		return (va_arg(ap, uintmax_t));
	else if (length == 'z')
		return (va_arg(ap, size_t));
	return (va_arg(ap, unsigned int));
}

size_t	ft_getnum_bytype(va_list ap, t_printf *conv)
{
	size_t	n;

	n = 0;
	if (ft_strchr("di", conv->spec))
		n = ft_getnum_signed(ap, conv->length);
	else if (ft_strchr("ouxX", conv->spec))
		n = ft_getnum_unsigned(ap, conv->length);
	return (n);
}

char	*ft_numtostr(size_t n, t_printf *conv)
{
	char	*str;

	str = NULL;
	if (n == 0 && conv->has_precision && conv->precision == 0)
		str = ft_strnew(0);
	else if (ft_strchr("di", conv->spec))
		str = ft_itoa(n);
	else if (conv->spec == 'u')
		str = ft_itoa_base(n, "0123456789");
	else if (conv->spec == 'o')
		str = ft_itoa_base(n, "01234567");
	else if (conv->spec == 'x')
		str = ft_itoa_base(n, "0123456789abcdef");
	else if (conv->spec == 'X')
		str = ft_itoa_base(n, "0123456789ABCDEF");
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_getnum(va_list ap, t_printf *conv, size_t *len)
{
	size_t	n;
	char	*str;

	n = ft_getnum_bytype(ap, conv);
	if (!(str = ft_numtostr(n, conv)))
		return (NULL);
	if (!ft_handle_precision_num(conv, &str)
			|| !ft_handle_sharp(conv, &str)
			|| !ft_handle_plus(conv, &str)
			|| !ft_handle_space(conv, &str)
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
