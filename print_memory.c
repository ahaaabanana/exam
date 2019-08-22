/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whybread <whybread@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 20:14:57 by whybread          #+#    #+#             */
/*   Updated: 2019/07/26 21:12:05 by whybread         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	print_memory(const void *addr, size_t size)
{
	size_t	i;
	unsigned char byte;
	unsigned char showbyte[2 + 1];
	unsigned char showchar[16 + 1];

	i = -1;
	showbyte[0] = '0';
	showbyte[1] = '0';
	showbyte[2] = 0;
	showchar[16] = 0;
	while (++i < size)
	{
		byte = ((unsigned char*)addr)[i];
		showchar[i % 16] = (byte > 31 && byte < 127) ? byte : '.';
		showbyte[1] = (byte % 16 >= 10 ? 'a' - 10: '0') + byte % 16;
		showbyte[0] = (byte / 16 >= 10 ? 'a' - 10: '0') + byte / 16;
		ft_putstr(showbyte);
		if ((i + 1) % 2 == 0)
			ft_putchar(' ');
		if ((i + 1) % 16 == 0)
		{
			ft_putchar(10);
			ft_putstr(showchar);
		}
	}
}

int		main(void)
{
	int	tab[10] = {0, 23, 150, 255,
					12, 16, 21, 42};
	print_memory(tab, sizeof(tab));
	return (0);
}