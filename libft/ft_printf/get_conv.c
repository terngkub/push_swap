/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:03:54 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/29 16:08:13 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_getflag(const char **format, t_printf *conv)
{
	if (!(**format))
		return ;
	while (ft_strchr("#0-+ ", **format))
	{
		if (**format == '#')
			conv->flag_sharp = 1;
		else if (**format == '0')
			conv->flag_zero = 1;
		else if (**format == '-')
			conv->flag_minus = 1;
		else if (**format == '+')
			conv->flag_plus = 1;
		else if (**format == ' ')
			conv->flag_space = 1;
		*format += 1;
	}
}

void	ft_getwp(const char **format, t_printf *conv)
{
	if (!(**format))
		return ;
	if (ft_isdigit(**format))
	{
		conv->width = ft_atoi(*format);
		*format += ft_numlen(conv->width);
	}
	if (**format == '.')
	{
		*format += 1;
		conv->has_precision = 1;
		if (!ft_isdigit(**format))
			conv->precision = 0;
		else
		{
			conv->precision = ft_atoi(*format);
			*format += ft_numlen(conv->precision);
		}
	}
}

void	ft_getlength(const char **format, t_printf *conv)
{
	if (!(**format))
		return ;
	if (ft_strchr("hljz", **format))
	{
		conv->length = **format;
		*format += 1;
		if (ft_strchr("hl", conv->length) && ft_strchr("hl", **format))
		{
			if (**format == 'h')
				conv->length = 'H';
			else if (**format == 'l')
				conv->length = 'L';
			*format += 1;
		}
	}
}

int		ft_checkspec(t_printf *conv)
{
	if (ft_strchr("DOUCS", conv->spec))
	{
		conv->spec = ft_tolower(conv->spec);
		conv->length = 'l';
	}
	return (1);
}

int		ft_getconv(const char **format, t_printf *conv)
{
	while (ft_strchr("#+ -.0123456789hljz", **format) && **format)
	{
		ft_getflag(format, conv);
		ft_getwp(format, conv);
		ft_getlength(format, conv);
	}
	if (!(**format))
	{
		*format -= 1;
		return (0);
	}
	conv->spec = **format;
	ft_checkspec(conv);
	return (1);
}
