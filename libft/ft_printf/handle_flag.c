/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:50:45 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/30 12:37:06 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_handle_sharp(t_printf *conv, char **str)
{
	if (!conv->flag_sharp || !ft_strchr("oxX", conv->spec))
		return (1);
	if (conv->spec == 'o' && **str == '0')
		return (1);
	if (ft_strchr("xX", conv->spec) && **str == '0' && conv->precision <= 1)
		return (1);
	if (ft_strchr("xX", conv->spec) && conv->has_precision
			&& conv->precision == 0)
		return (1);
	if (conv->spec == 'o' && !(*str = ft_strfreecat_front(str, "0")))
		return (0);
	else if (conv->spec == 'x' && !(*str = ft_strfreecat_front(str, "0x")))
		return (0);
	else if (conv->spec == 'X' && !(*str = ft_strfreecat_front(str, "0X")))
		return (0);
	return (1);
}

int		ft_handle_plus(t_printf *conv, char **str)
{
	if (!conv->flag_plus || !ft_strchr("di", conv->spec) || **str == '-')
		return (1);
	if (ft_atoi(*str) >= 0)
	{
		if (!(*str = ft_strfreecat_front(str, "+")))
			return (0);
	}
	return (1);
}

int		ft_handle_space(t_printf *conv, char **str)
{
	if (!conv->flag_space || !ft_strchr("di", conv->spec) || conv->flag_plus
			|| **str == '-')
		return (1);
	if (!(*str = ft_strfreecat_front(str, " ")))
		return (0);
	return (1);
}

int		ft_handle_minus(t_printf *conv, char **str)
{
	int		len;
	char	*space;

	len = ft_strlen(*str);
	if (!conv->flag_minus || conv->width <= len)
		return (1);
	if (!(space = ft_strnew(conv->width - len)))
		return (0);
	space = ft_memset(space, ' ', conv->width - len);
	if (!(*str = ft_strfreecat_back(str, space)))
	{
		free(space);
		return (0);
	}
	free(space);
	return (1);
}

int		ft_handle_zero(t_printf *conv, char **str)
{
	int		len;
	char	*tmp;
	int		zero_len;
	int		i;
	int		j;

	len = (conv->spec == 'c' && **str == 0) ? 1 : ft_strlen(*str);
	if (!conv->flag_zero || conv->flag_minus || conv->width <= len
			|| (conv->has_precision && ft_strchr("dioux", conv->spec)))
		return (1);
	if (!(tmp = ft_strnew(conv->width)))
		return (0);
	zero_len = conv->width - len;
	i = 0;
	j = 0;
	while (str[0][j] != 0 && ft_strchr("-+ 0xX", str[0][j]))
		tmp[i++] = str[0][j++];
	while (zero_len--)
		tmp[i++] = '0';
	while (j < len)
		tmp[i++] = str[0][j++];
	free(*str);
	*str = tmp;
	return (1);
}
