/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:26:58 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/14 22:01:20 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"

typedef struct s_sc
{
	size_t	len;
	size_t	width;
}	t_sc;

size_t	ft_intlen(long int nb, int div);

void	ft_printchr(va_list args, t_sc *sc);
void	ft_printhex(size_t x, const char *format);
void	ft_printint(va_list args, t_sc *sc, const char *format);
void	ft_printstr(va_list args, t_sc *sc);
void	ft_hex(va_list args, t_sc *sc, const char *format);
void	ft_printaddr(va_list args, t_sc *sc);

int		ft_printf(const char *format, ...);
#endif
