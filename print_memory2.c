/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whybread <whybread@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 09:20:21 by whybread          #+#    #+#             */
/*   Updated: 2019/08/17 09:59:48 by whybread         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

void	show_byte(unsigned char c)
{
	ft_putchar((c / 16 >= 10 ? 'a' - 10 : '0') + c / 16);
	ft_putchar((c % 16 >= 10 ? 'a' - 10 : '0') + c % 16);
}

void	show_symbols(unsigned char *str, int to)
{
	size_t	i;

	i = -1;
	while (++i < to)
	{
		if (str[i] > 31 && str[i] < 127)
			ft_putchar(str[i]);
		else
			ft_putchar('.');
	}
	ft_putchar(10);
}

void	show_16_bytes_each(size_t to, unsigned char *addr)
{
	unsigned char 	symbols[16];
	int				i;

	i = -1;
	while (++i < to)
	{
		symbols[i % 16] = addr[i];
		show_byte(addr[i]);
		if ((i + 1) % 2 == 0)
			ft_putchar(' ');
		if ((i + 1) % 16 == 0)
			show_symbols(symbols, 16);
	}
}

void	show_remaining_bytes(size_t from, unsigned char *addr, size_t size)
{
	unsigned char	symbols[16];
	size_t	i;

	i = from - 1;
	while (++i < size)
	{
		symbols[i % 16] = addr[i];
		show_byte(addr[i]);
		if ((i + 1) % 2 == 0)
			ft_putchar(' ');
	}
	i = -1;
	// printf("from = %ld, size = %ld\n", from, size);
	while (++i < 16 - (size - from))
	{
		ft_putchar(' ');
		ft_putchar(' ');
		if ((i + 1) % 2 == 0)
			ft_putchar(' ');
	}
	show_symbols(symbols, size - from);
}

void	print_memory(const void *addr, size_t size)
{
	size_t			x;

	x = (size / 16) * 16;
	show_16_bytes_each(x, (unsigned char*)addr);
	show_remaining_bytes(x, (unsigned char*)addr, size);
}

int 	main(int argc, char **argv)
{
	// int 	tab[0] = {-23/*, -23, 150, 255, 12, 16, 21, 42, 47 */};	
	int		tab[0];

	print_memory(tab, sizeof(tab));
	return (0);
}
