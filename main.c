/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:34:02 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/15 23:30:44 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char *oct = "tvvr";
	char *juu = "12345";
	int ei = 1090909;
	int *jo;
	void * noh;

	jo = &ei;

	ft_printf("%s\n", oct);
	printf("%s\n", oct);
	printf("%p\n", oct);
	printf("%s\n", juu);
	printf("%p\n", juu);
	printf("%d\n", ei);
	printf("%p\n", jo);
	printf("%d\n", (int)noh);
	printf("%p\n", noh);
	ft_printf("%p\n", juu);
	return (0);
}
