/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 16:46:49 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/30 12:32:23 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_handle_precision_num(t_printf *conv, char **str)
{
	int		len;
	int		sign;
	char	*tmp;
	int		i;
	int		j;

	sign = (**str == '-') ? 1 : 0;
	len = ft_strlen(*str) - sign;
	if (!conv->has_precision || conv->precision <= len)
		return (1);
	if (!(tmp = ft_strnew(conv->precision + sign)))
		return (0);
	i = 0;
	j = 0;
	if (sign)
		tmp[i++] = str[0][j++];
	while (i < conv->precision - len + sign)
		tmp[i++] = '0';
	while (j < len + sign)
		tmp[i++] = str[0][j++];
	free(*str);
	*str = tmp;
	return (1);
}

int		ft_handle_precision_str(t_printf *conv, char **str)
{
	int		precision;
	char	*tmp;

	if (!conv->has_precision)
		return (1);
	precision = conv->precision;
	if (!(tmp = ft_strnew(precision)))
		return (0);
	while (precision-- >= 0)
		tmp[precision] = str[0][precision];
	free(*str);
	*str = tmp;
	return (1);
}

int		ft_handle_width(t_printf *conv, char **str)
{
	int		len;
	char	*space;

	len = ft_strlen(*str);
	if (conv->spec == 'c' && **str == 0)
		len = 1;
	else if (conv->spec == 'c' && (conv->flag_minus || conv->flag_zero))
		len = conv->width;
	if (conv->width <= len)
		return (1);
	if (!(space = ft_strnew(conv->width - len)))
		return (0);
	space = ft_memset(space, ' ', conv->width - len);
	if (!(*str = ft_strfncat_front(str, space, len, conv->width - len)))
	{
		free(space);
		return (0);
	}
	free(space);
	return (1);
}
