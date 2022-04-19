/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 09:08:03 by mviinika          #+#    #+#             */
/*   Updated: 2022/04/18 20:36:53 by mviinika         ###   ########.fr       */
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

	// i = ft_printf("[%.f]\n", 1.5);
	// a =	printf("[%.f]\n", 1.5);





	// i = ft_printf("[%.f]\n", 9.50000);
	// a =	printf("[%.f]\n", 9.50000);

	// i = ft_printf("[%.15f]\n", 1.00002);
	// a =	printf("[%.15f]\n", 1.00002);


	// i = ft_printf("[%.15f]\n", 1.56423335);
	// a =	printf("[%.15f]\n", 1.56423335);


	// i = ft_printf("[%.15f]\n", 1.5643339);
	// a =	printf("[%.15f]\n", 1.5643339);
	// i = ft_printf("[%2.3o]\n", 0);
	// a =	printf("[%2.3o]\n", 0);


	// i = ft_printf("[%2.2o]\n", 0);
	// a =	printf("[%2.2o]\n", 0);

	// i = ft_printf("[%2.1o]\n", 0);
	// a =	printf("[%2.1o]\n", 0);

	// i = ft_printf("[%#2.1o]\n", 0);
	// a =	printf("[%#2.1o]\n", 0);

	// i = ft_printf("[%-#2.1x]\n", 0);
	// a =	printf("[%-#2.1x]\n", 0);

	// i = ft_printf("[%2.2x]\n", 0);
	// a =	printf("[%2.2x]\n", 0);

	// i = ft_printf("[%2.1o]\n", 0);
	// a =	printf("[%2.1o]\n", 0);

	// i = ft_printf("[%#2.1o]\n", 0);
	// a =	printf("[%#2.1o]\n", 0);

	// i = ft_printf("[%-#2.1o]\n", 0);
	// a =	printf("[%-#2.1o]\n", 0);

	// i = ft_printf("[%-#2.2o]\n", 0);
	// a =	printf("[%-#2.2o]\n", 0);

	// i = ft_printf("[%-#2.3o]\n", 0);
	// a =	printf("[%-#2.3o]\n", 0);

	// i = ft_printf("[%-2.1o]\n", 0);
	// a =	printf("[%-2.1o]\n", 0);

	// i = ft_printf("[%-2.2o]\n", 0);
	// a =	printf("[%-2.2o]\n", 0);

	// i = ft_printf("[%-1.0d]\n", 0);
	// a =	printf("[%-1.0d]\n", 0);

	// i = ft_printf("[% -6.4d]\n", 0);
	// a =	printf("[% -6.4d]\n", 0);

	// i = ft_printf("[% -3.0d]\n", 0);
	// a =	printf("[% -3.0d]\n", 0);



	// i = ft_printf("[% -0.2d]\n", 0);
	// a =	printf("[% -0.2d]\n", 0);

	// i = ft_printf("[% -1.2d]\n", 0);
	// a =	printf("[% -1.2d]\n", 0);

	// i = ft_printf("[% -1.1d]\n", 0);
	// a =	printf("[% -1.1d]\n", 0);

	// i = ft_printf("[% -1d]\n", 0);
	// a =	printf("[% -1d]\n", 0);

	// 	i = ft_printf("[% -1.0d]\n", 0);
	// a =	printf("[% -1.0d]\n", 0);

	// i = ft_printf("[% -0.0d]\n", 0);
	// a =	printf("[% -0.0d]\n", 0);


	// i = ft_printf("[% +6d]\n", 33333);
	// a =	printf("[% +6d]\n", 33333);

	// 	i = ft_printf("[%+1.0d]\n", 33333);
	// a =	printf("[%+1.0d]\n", 33333);

	// i = ft_printf("[%05.0d]\n", -10);
	// a =	printf("[%05.0d]\n", -10);


	// i = ft_printf("[%s  %x    %X %c %u  %p  ]\n", str, uin, uin, c,uin, &i);
	// a =	printf("[%s  %x    %X %c %u  %p  ]\n", str, uin, uin, c,uin, &i);

	// i = ft_printf("[%010.1d]\n", 3);
	// a =	printf("[%010.1d]\n", 3);
	i = ft_printf("[%0#10.1f]\n", -958.125000);
	a =	printf("[%0#10.1f]\n", -958.125000);
	i = ft_printf("[%f]\n", 3.1);
	a =	printf("[%f]\n", 3.1);

	i = ft_printf("[%.f]\n", 0.876509);
	a =	printf("[%.f]\n", 0.876509);

	i = ft_printf("[%f]\n", -958.125000);
	a =	printf("[%f]\n", -958.125000);

	i = ft_printf("[%10.15f]\n", -9007199254740992.0);
	a =	printf("[%10.15f]\n", -9007199254740992.0);
	// i = ft_printf("[%.5x]\n", 21);
	// a =	printf("[%.5x]\n", 21);
	printf("%d\n%d", i, a);
	return (0);
}


