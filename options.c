/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whybread <whybread@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:23:24 by whybread          #+#    #+#             */
/*   Updated: 2019/07/25 20:13:40 by whybread         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void 	ft_putchar(char c)
{
	write(1, &c, 1);
}

void 	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int 	is_option(char *str)
{	
	if (*str == '-')
	{
		while (*(++str))
		{
			if (*str == 'h')
			{
				ft_putstr("options: abcdefghijklmnopqrstuvwxyz\n");
				return (0);
			}
			else if (*str < 'a' || *str > 'z')
			{
				ft_putstr("Invalid Option\n");
				return (0);
			}
		}
	}
	return (1);
}

char	*options(char *options, char *bites)
{
	if (*options == '-')
		while (*(++options))
			bites[31 - (int)(*options - 'a')] = '1';
	return (bites);
}

void	show_bites(char *bites)
{
	int		i;

	i = -1;
	while (++i < 32)
	{
		ft_putchar(bites[i]);
		if ((i + 1) % 8 == 0 && i != 31)
			ft_putchar(' ');
	}
	ft_putchar(10);
}

int 	main(int argc, char **argv)
{
	char	t[32 + 1];
	char 	*bites;
	int 	i;

	if (argc > 1)
	{
		i = 0;
		while (i < 32)
			t[i++] = '0';
		t[i] = 0;
		bites = t;
		while (*(++argv))
		{
			if (!is_option(*argv))
				return (0);
			else
				bites = options(*argv, bites);
		}
		show_bites(bites);
	}
	else
		ft_putstr("options: abcdefghijklmnopqrstuvwxyz\n");
	return (0);
}