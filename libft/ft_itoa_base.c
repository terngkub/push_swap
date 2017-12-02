/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:52:27 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/24 12:52:39 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(size_t n, char *base)
{
	int		base_len;
	int		num_len;
	size_t	tmp;
	char	*str;

	base_len = ft_strlen(base);
	num_len = 1;
	tmp = n;
	while (tmp /= base_len)
		num_len++;
	if (!(str = ft_strnew(num_len)))
		return (NULL);
	while (num_len--)
	{
		str[num_len] = base[n % base_len];
		n /= base_len;
	}
	return (str);
}
