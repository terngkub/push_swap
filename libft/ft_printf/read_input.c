/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:03:41 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/30 11:58:08 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_readword(const char **format, char **str, size_t *len)
{
	size_t	old_len;
	char	*word;

	old_len = *len;
	if (!(word = ft_getword(*format, '%')))
		return (0);
	*format += ft_strlen(word) - 1;
	*len += ft_strlen(word);
	if (!ft_strfncat_back(str, word, old_len, *len - old_len))
	{
		free(word);
		return (0);
	}
	free(word);
	return (1);
}

void	ft_initconv(t_printf *conv)
{
	conv->flag_sharp = 0;
	conv->flag_zero = 0;
	conv->flag_minus = 0;
	conv->flag_plus = 0;
	conv->flag_space = 0;
	conv->width = 0;
	conv->has_precision = 0;
	conv->precision = 0;
	conv->length = 0;
	conv->spec = 0;
}

int		ft_readconv(const char **format, va_list ap, char **str, size_t *len)
{
	size_t		old_len;
	t_printf	conv;
	char		*word;

	ft_initconv(&conv);
	if (!ft_getconv(format, &conv))
		return (1);
	old_len = *len;
	if (!(word = ft_getdata(ap, &conv, len)))
		return (0);
	if (!ft_strfncat_back(str, word, old_len, *len - old_len))
	{
		free(word);
		return (0);
	}
	free(word);
	return (1);
}

char	*ft_readformat(const char *format, va_list ap, size_t *len)
{
	char	*str;

	if (!(str = ft_strnew(0)))
		return (NULL);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!ft_readconv(&format, ap, &str, len))
			{
				free(str);
				return (NULL);
			}
		}
		else if (!ft_readword(&format, &str, len))
		{
			free(str);
			return (NULL);
		}
		format++;
	}
	return (str);
}
