/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:48:39 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/14 20:07:44 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PARAMETERS
// s: The string to output.
// fd: The file descriptor on which to write.

// DESCRIPTION
// Outputs the string ’s’ to the given file
// descriptor.

// RETURN VALUE
// None

#include	"libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (fd < 0)
		return ;
	i = 0;
	if (s == (void *)0)
		return ;
	while (*(unsigned char *)(s + i) != '\0')
		ft_putchar_fd(*(unsigned char *)(s + i++), fd);
}
