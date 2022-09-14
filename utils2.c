/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:40:37 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/14 23:13:23 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_intlen(long int nb, int div)
{
	int			i;
	long int	number;
	int			neg;

	i = 0;
	if (!nb)
		return (1);
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

size_t	ft_uintlen(unsigned int nb, int div)
{
	int			i;
	long int	number;

	i = 0;
	if (!nb)
		return (1);
	number = nb;
	while (number)
	{
		number /= div;
		i++;
	}
	return (i);
}

static int	ft_printhexaddr(size_t x, const char *format)
{
	char	*hex;
	int		*res;
	int		i;
	int		len;

	if (*format == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	i = 0;
	res = (int *)malloc(sizeof(int) * ft_intlen((x), 16));
	if (res == NULL)
		return (0);
	while (x >= 16)
	{
		*(res + i) = hex[x % 16];
		x /= 16;
		i++;
	}
	*(res + i) = hex[x];
	len = i;
	while (i >= 0)
		ft_putchar_fd(res[i--], 1);
	free (res);
	return (len);
}

void	ft_printaddr(va_list args, t_sc *sc)
{
	void	*addr;

	addr = (void *)va_arg(args, size_t);
	write(1, "0x", 2);
	sc->len += ft_printhexaddr((size_t)addr, "x") + 3;
}
