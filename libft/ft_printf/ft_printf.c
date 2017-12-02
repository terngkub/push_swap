/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:38:51 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/29 16:34:08 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	size_t		len;
	va_list		ap;
	char		*str;

	len = 0;
	va_start(ap, format);
	if (!(str = ft_readformat(format, ap, &len)))
		return (-1);
	va_end(ap);
	ft_putstr_len(str, len);
	free(str);
	return (len);
}
