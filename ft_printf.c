/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:26:25 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/14 21:20:14 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

const char	*ft_search_args(va_list args, const char *format, t_sc *sc)
{
	if (*format == 'c')
		ft_printchr(args, sc);
	else if (*format == 's')
		ft_printstr(args, sc);
	else if (*format == 'p')
		;//ft_printaddr(args, sc);
	else if (*format == 'd' || *format == 'i' || *format == 'u')
		ft_printint(args, sc, format);
	else if (*format == 'x' || *format == 'X')
		ft_hex(args, sc, format);
	else if (*format == '%')
	{
		write(1, "%", 1);
		sc->len += 1;
	}
	else
		return (NULL);
	format++;
	return (format);
}

const char	*ft_read_text(t_sc *sc, const char *format)
{
	char	*next;

	next = ft_strchr(format);
	if (next)
		sc->width = next - format;
	else
		sc->width = ft_strlen(format);
	write(1, format, sc->width);
	sc->len += sc->width;
	while (*format && *format != '%')
		++format;
	return (format);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_sc	sc;

	va_start(args, format);
	sc.len = 0;
	sc.width = 0;
	while (*format)
	{
		if (*format == '%')
			format = ft_search_args(args, format + 1, &sc);
		else
			format = ft_read_text(&sc, format);
		if (!format)
		{
			write(1, "(null)", 6);
			va_end(args);
			return (sc.len);
		}
	}
	va_end(args);
	return (sc.len);
}
