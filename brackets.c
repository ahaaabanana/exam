/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whybread <whybread@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 18:19:20 by whybread          #+#    #+#             */
/*   Updated: 2019/08/24 10:33:04 by whybread         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void 	ft_putchar(char c)
{
	write(1, &c, 1);
}

void 	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int 	determine_expr(char *expr, int length)
{
	char	arr[length + 1];
	int 	i;

	i = -1;
	while (++i <= length)
		arr[i] = 0;
	i = -1;
	while (*expr)
	{
		if (*expr == '{')
			arr[++i] = '}';
		else if (*expr == '[')
			arr[++i] = ']';
		else if (*expr == '(')
			arr[++i] = ')';
		if (*expr == '}' || *expr == ']' || *expr == ')')
		{
			if (*expr == arr[i])
				i--;
			else
				return (0);
		}
		expr++;
	}
	return (1);
}

int  	is_correct_expr(char *expr)
{
	int 	i;
	int 	c_brackets;
	int 	o_brackets;

	i = -1;
	o_brackets = 0;
	c_brackets = 0;
	while (expr[++i])
	{
		if (expr[i] == '{' || expr[i] == '[' || expr[i] == '(')
			o_brackets++;
		else if (expr[i] == '}' || expr[i] == ']' || expr[i] == ')')
			c_brackets++;
	}
	if (o_brackets != c_brackets)
		return (0);
	if (o_brackets == 0)
		return (1);
	return (determine_expr(expr, o_brackets));
}

int 	main(int argc, char **argv)
{
	if (argc > 1)
	{
		while (*(++argv))
		{
			if (is_correct_expr(*argv))
				ft_putstr("OK\n");
			else
				ft_putstr("Error\n");
		}
	}
	else
		ft_putchar(10);
	return (0);
}