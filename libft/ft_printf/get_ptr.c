/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:58:31 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/29 18:58:34 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_getptr(va_list ap, t_printf *conv, size_t *len)
{
	void	*ptr;
	char	*str;

	ptr = va_arg(ap, void*);
	if (conv->has_precision && ptr == 0 && conv->precision == 0)
	{
		str = ft_strnew(0);
	}
	else if (!(str = ft_itoa_base((size_t)ptr, "0123456789abcdef")))
		return (NULL);
	ft_handle_precision_num(conv, &str);
	if (!(ft_strfreecat_front(&str, "0x")))
		return (NULL);
	ft_handle_minus(conv, &str);
	ft_handle_width(conv, &str);
	*len += ft_strlen(str);
	return (str);
}
