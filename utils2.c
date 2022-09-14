/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:40:37 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/14 22:33:25 by tliangso         ###   ########.fr       */
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

void	ft_printaddr(va_list args, t_sc *sc)
{
	void	*addr;

	addr = (void *)va_arg(args, size_t);
	write(1, "0x", 2);
	sc->len += ft_printhex((size_t)addr, "x") + 3;
}
