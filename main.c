/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:14:15 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/14 21:15:55 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	unsigned int num = 2975540279;


	printf("len: %d\n", ft_printf("u: %u\nd: %d\n",num,num));
	printf("\n");
	printf("len: %d\n", printf("u: %u\nd: %d\n",num,num));
	return (0);
}
