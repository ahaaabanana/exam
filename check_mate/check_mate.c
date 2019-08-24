/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whybread <whybread@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 21:35:26 by whybread          #+#    #+#             */
/*   Updated: 2019/08/24 09:53:15 by whybread         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	show_board(char **board, int length)
{
	int	i;
	int j;

	i = -1;
	while (++i < length)
	{
		j = -1;
		while (++j < length)
			ft_putchar(board[i][j]);
		ft_putchar(10);
	}
	ft_putchar(10);
}

char	**create_board(char **board, int length)
{
	char 	**big_board;
	int		i;
	int		j;

	big_board = (char**)malloc(sizeof(char*) * length);
	i = -1;
	while (++i < length)
	{
		big_board[i] = (char*)malloc(sizeof(char) * length);
		j = -1;
		while (++j < length)
			big_board[i][j] = '*';
	}
	i = 0;
	while (++i < length - 1)
	{
		j = 0;
		while (++j < length - 1)
			big_board[i][j] = board[i - 1][j - 1];
	}
	return (big_board);
}

int		is_pbrq(char c)
{
	return (c == 'P' || c == 'B' || c == 'R' || c == 'Q');
}

int		check_rook(char **board, int i, int j, int length)
{
	int		n;
	int		m;
	
	n = i;
	m = j;
	// printf("i = %d, j = %d\n", i, j);
	while (++n < length - 1)
	{
		if (is_pbrq(board[n][m]))
			break;
		else if (board[n][m] == 'K')
			return (1);
	}
	n = i;
	while (--n >= 1)
	{
		if (is_pbrq(board[n][m]))
			break;
		else if (board[n][m] == 'K')
			return (1);
	}
	n = i;
	while (++m < length - 1)
	{
		if (is_pbrq(board[n][m]))
			break;
		else if (board[n][m] == 'K')
			return (1);
	}
	m = j;
	while (--m >= 1)
	{
		if (is_pbrq(board[n][m]))
			break;
		else if (board[n][m] == 'K')
			return (1);
	}
	return (0);
}

int		check_bishop(char **board, int i, int j, int length)
{		
	int		n;
	int		m;

	n = i;
	m = j;
	while (--n >= 1 && --m >= 1)
	{
		if (is_pbrq(board[n][m]))
			break ;
		else if (board[n][m] == 'K')
			return (1);
	}
	n = i;
	m = j;
	while (--n >= 1 && ++m < length - 1)
	{
		if (is_pbrq(board[n][m]))
			break ;
		else if (board[n][m] == 'K')
			return (1);
	}
	n = i;
	m = j;
	while (++n < length -  1 && --m >= 1)
	{
		if (is_pbrq(board[n][m]))
			break ;
		else if (board[n][m] == 'K')
			return (1);
	}
	n = i;
	m = j;
	while (++n < length - 1 && ++m < length - 1)
	{
		if (is_pbrq(board[n][m]))
			break ;
		else if (board[n][m] == 'K')
			return (1);
	}
	return (0);
}

int		is_check(char **board, int length)
{
	int		i;
	int 	j;

	i = 0;
	while (++i < length - 1)
	{
		j = 0;
		while (++j < length - 1)
		{
			if (board[i][j] == 'P' && (board[i - 1][j - 1] == 'K' || board[i - 1][j + 1] == 'K'))
			{
				ft_putstr("pawn\n");
				return (1);
			}
			else if (board[i][j] == 'R' && check_rook(board, i, j, length))
			{
				ft_putstr("rook\n");
				return (1);
			}
			else if (board[i][j] == 'B' && check_bishop(board, i, j, length))
			{
				ft_putstr("bishop\n");
				return (1);
			}
			else if (board[i][j] == 'Q' && (check_rook(board, i, j, length) || check_bishop(board, i, j, length)))
			{
				ft_putstr("queen\n");
				return (1);
			}
		}
	}
	return (0);
}

int		main(int argc, char **argv)
{
	char	**board;

	if (argc > 1)
	{
		show_board(argv + 1, argc - 1);
		board = create_board(argv + 1, argc + 1);
		show_board(board, argc + 1);
		if (is_check(board, argc + 1))
			ft_putstr("Success");
		else
			ft_putstr("Fail");
	}
	ft_putchar(10);
	return (0);
}