/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:30:38 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/14 21:31:18 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_printchr(va_list args, t_sc *sc)
{
	int	c;

	c = va_arg(args, int);
	sc->len += write(1, &c, 1);
}

void	ft_printint(va_list args, t_sc *sc, const char *format)
{
	long int	u;
	int			d;

	if (*format == 'u')
	{
		u = va_arg(args, long int);
		ft_putnnbr_fd(u, 1);
		sc->len += ft_intlen(u, 10) - 1;
	}
	else
	{
		d = va_arg(args, int);
		ft_putnbr_fd(d, 1);
		sc->len += ft_intlen(d, 10);
	}
}

void	ft_printstr(va_list args, t_sc *sc)
{
	char	*s;

	s = va_arg(args, char *);
	if (!s)
	{
		write(1, "(null)", 6);
		sc->len += 6;
	}
	else
	{
		ft_putstr_fd(s, 1);
		sc->len += ft_strlen(s);
	}
}

void	ft_hex(va_list args, t_sc *sc, const char *format)
{
	size_t	x;

	x = va_arg(args, size_t);
	ft_printhex((unsigned long)x, format);
	sc->len += ft_intlen((unsigned long)x, 16);
}

void	ft_printhex(size_t x, const char *format)
{
	char	*hex;
	int		*res;
	int		i;

	if (*format == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	i = 0;
	res = (int *)malloc(sizeof(int) * ft_intlen((x), 16));
	if (res == NULL)
		return ;
	while (x >= 16)
	{
		*(res + i) = hex[x % 16];
		x /= 16;
		i++;
	}
	*(res + i) = hex[x];
	while (i >= 0)
	{
		ft_putchar_fd(res[i], 1);
		i--;
	}
	free (res);
}

size_t	ft_intlen(long int nb, int div)
{
	int			i;
	long int	number;
	int			neg;

	i = 0;
	if (!nb)
		return (i);
	if (nb < 0)
	{
		neg = 1;
		number = -nb;
	}
	else
	{
		neg = 0;
		number = nb;
	}
	while (number)
	{
		number /= div;
		i++;
	}
	return (i + neg);
}
