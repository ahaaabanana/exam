/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_detector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whybread <whybread@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 22:02:32 by whybread          #+#    #+#             */
/*   Updated: 2019/08/19 22:07:20 by whybread         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>

int		cycle_detector(const t_list *list)
{
	return (1);
}

int		main(int argc, char **argv)
{
	int		x;
	int		*t1;
	int		*t2;

	printf("%p\n", &x + 1);
	t1 = &x + 1;
	printf("%p", t1);
	t2 = &x;
	if (t1 == t2)
		printf("yes");
	return (0);
}