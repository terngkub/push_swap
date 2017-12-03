/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:43:42 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/02 23:44:40 by terng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>
# include <inttypes.h>

typedef struct	s_printf
{
	char		flag_sharp;
	char		flag_zero;
	char		flag_minus;
	char		flag_plus;
	char		flag_space;
	int			width;
	char		has_precision;
	int			precision;
	char		length;
	char		spec;
}				t_printf;

int				ft_printf(const char *format, ...);

int				ft_readword(const char **format, char **str, size_t *len);
void			ft_initconv(t_printf *conv);
int				ft_readconv(const char **format, va_list ap, char **str
					, size_t *len);
char			*ft_readformat(const char *format, va_list ap, size_t *len);

void			ft_getflag(const char **format, t_printf *conv);
void			ft_getwp(const char **format, t_printf *conv);
void			ft_getlength(const char **format, t_printf *conv);
int				ft_getconv(const char **format, t_printf *conv);

char			*ft_strfrontcat_free(char **str1, char *str2);
char			*ft_strbackcat_free(char **str1, char *str2);
void			ft_getlength(const char **format, t_printf *conv);
int				ft_checkspec(t_printf *conv);
int				ft_getconv(const char **format, t_printf *conv);

char			*ft_getdata(va_list ap, t_printf *conv, size_t *len);

size_t			ft_getnum_signed(va_list ap, char length);
size_t			ft_getnum_unsigned(va_list ap, char length);
size_t			ft_getnum_bytype(va_list ap, t_printf *conv);
char			*ft_numtostr(size_t n, t_printf *conv);
char			*ft_getnum(va_list ap, t_printf *conv, size_t *len);

char			*ft_handle_nullstr(size_t *len);
char			*ft_getstr(va_list ap, t_printf *conv, size_t *len);
char			*ft_getchar(va_list ap, t_printf *conv, size_t *len);
char			*ft_getwstr(va_list ap, t_printf *conv, size_t *len);
char			*ft_getwrongspec(t_printf *conv, size_t *len);

char			*ft_one_byte(wchar_t c);
char			*ft_two_byte(wchar_t c);
char			*ft_three_byte(wchar_t c);
char			*ft_four_byte(wchar_t c);
char			*ft_getwchar(wchar_t c);

char			*ft_getptr(va_list ap, t_printf *conv, size_t *len);

int				ft_handle_sharp(t_printf *conv, char **str);
int				ft_handle_plus(t_printf *conv, char **str);
int				ft_handle_space(t_printf *conv, char **str);
int				ft_handle_zero(t_printf *conv, char **str);
int				ft_handle_minus(t_printf *conv, char **str);

int				ft_handle_precision_num(t_printf *conv, char **str);
int				ft_handle_precision_str(t_printf *conv, char **str);
int				ft_handle_width(t_printf *conv, char **str);

#endif
