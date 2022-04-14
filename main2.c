/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:34:02 by m3iinika          #+#    #+#             */
<<<<<<< HEAD
<<<<<<< HEAD
/*   Updated: 2022/04/14 07:45:14 by mviinika         ###   ########.fr       */
=======
/*   Updated: 2022/04/13 22:23:04 by mviinika         ###   ########.fr       */
>>>>>>> 2564d38b42f4e792a864caa0d27db7867ae72785
=======
/*   Updated: 2022/04/14 07:50:03 by mviinika         ###   ########.fr       */
>>>>>>> a4c635bb2c62be5cec4f3871f0c3afd7afc7390a
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int main()
{
	long long joo = 922337203685477580;
	//long  juu = 0;
	// char *joo = "jouo";
	//double jaa = 23.145;
	//char per = '%';
	int i = 42;
	int a = 0;
	static unsigned int uin = 238;
	static char c = 'G';
	static char *str = "Hello World";

	// i = ft_printf("[%5d]\n", -12);
	// a =	printf("[%5d]\n", -12);

	// i = ft_printf("[%-5d]\n", -12);
	// a =	printf("[%-5d]\n", -12);

	// i = ft_printf("[%-05d]\n", -12);
	// a =	printf("[%-05d]\n", -12);

	// i = ft_printf("[%+10.5d]\n", -12);
	// a =	printf("[%+10.5d]\n", -12);

	// i = ft_printf("[%+10.5d]\n", -12);
	// a =	printf("[%+10.5d]\n", -12);

	// i = ft_printf("[%+10.5d]\n", 4242);
	// a =	printf("[%+10.5d]\n", 4242);

	//  i = ft_printf("MY [%.5d]\n", 42);
	//  a =	printf("OG [%.5d]\n", 42);

	// i = ft_printf("[%05d]\n", 42);
	// a =	printf("[%05d]\n", 42);

	// i = ft_printf("[%5d]\n", -42);
	// a =	printf("[%5d]\n", -42);

	// i = ft_printf("MY [%05d]\n", 42);
	// a =	printf("OG [%05d]\n", 42);

	// i = ft_printf("[%03.2d]\n", -1);
	// a =	printf("[%03.2d]\n", -1);

	// i = ft_printf("[%-*s]\n", -32, "abc");
	// a =	printf("[%-*s]\n", -32, "abc");

	// i = ft_printf("[%*s]\n", -32, "abc");
	// a =	printf("[%*s]\n", -32, "abc");

<<<<<<< HEAD
<<<<<<< HEAD
	i = ft_printf("[%.15f]\n", 1.00002);
	a =	printf("[%.15f]\n", 1.00002);

=======
	i = ft_printf("[%.15f]\n", 1.56423335);
	a =	printf("[%.15f]\n", 1.56423335);
>>>>>>> 2564d38b42f4e792a864caa0d27db7867ae72785
=======
	i = ft_printf("[%.15f]\n", 1.564333);
	a =	printf("[%.15f]\n", 1.564333);
>>>>>>> a4c635bb2c62be5cec4f3871f0c3afd7afc7390a

	// i = ft_printf("[%s  %x    %X %c %u  %p  ]\n", str, uin, uin, c,uin, &i);
	// a =	printf("[%s  %x    %X %c %u  %p  ]\n", str, uin, uin, c,uin, &i);

	// i = ft_printf("[%.5x]\n", 21);
	// a =	printf("[%.5x]\n", 21);
	//printf("%d", a);
	return (0);
}


