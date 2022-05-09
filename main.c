/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:10:04 by mviinika          #+#    #+#             */
/*   Updated: 2022/05/09 13:54:23 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

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
	ft_printf("[%hb]\n" ,SHRT_MIN);
	//printf("[%010.0b]\n", 0);
	ft_printf("[%hb]\n" ,SHRT_MAX);

	ft_printf("[%b]\n" , INT_MIN);

	ft_printf("[%b]\n",INT_MAX);

	ft_printf("[%lb]\n" ,LONG_MIN);

	ft_printf("[%lb]\n" ,LONG_MAX);

	ft_printf("[%llb]\n" ,LLONG_MIN);

	ft_printf("[%llb]\n" ,LLONG_MAX);

	ft_printf("[%b]\n", -16);

	ft_printf("[%b]\n" , 16);

	ft_printf("[%b]\n", -60600);

	ft_printf("[%b]\n" , 60600);

	ft_printf("[%hb]\n", -123);

	ft_printf("[%+hb]\n" , 123);

	ft_printf("[%b]\n", -55645646);

	ft_printf("[%b]\n" , 55645646);

	ft_printf("[%b]\n", 0);

	ft_printf("[%#-+*b]\n" ,10, -0);

	ft_printf("[%*b]\n",15 , -1);



	ft_printf("[%10hb]\n" ,SHRT_MIN);
	//printf("[%010.0b]\n", 0);
	ft_printf("[%10hb]\n" ,SHRT_MAX);

	ft_printf("[%*b]\n" ,90, INT_MIN);

	ft_printf("[%*b]\n",90 ,INT_MAX);

	ft_printf("[%-15lb]\n" ,LONG_MIN);

	ft_printf("[%-15lb]\n" ,LONG_MAX);

	ft_printf("[%0#+-*b]\n" ,90,LLONG_MIN);

	ft_printf("[%0#+-*b]\n",90 ,LLONG_MAX);

	ft_printf("[%b]\n", -16);

	ft_printf("[%b]\n" , 16);

	ft_printf("[%b]\n", -60600);

	ft_printf("[%b]\n" , 60600);

	ft_printf("[%hb]\n", -123);

	ft_printf("[%+hb]\n" , 123);

	ft_printf("[%b]\n", -55645646);

	ft_printf("[%b]\n" , 55645646);

	ft_printf("[%b]\n", 0);

	ft_printf("[%0#.1f]\n", -3.141593);
	printf("[%0#.1f]\n",-3.141593);

	ft_printf("[%0#10.1f]\n", -3.141593);
	printf("[%0#10.1f]\n", -3.141593);



	ft_printf("[%010f]\n", 1.000000);
	printf("[%010f]\n",1.000000);

	ft_printf("[%0#10.1f]\n", -3.141593);
	printf("[%0#10.1f]\n", -3.141593);


	ft_printf("[%#10.1f]\n", 3.141593);
	printf("[%#10.1f]\n",3.141593);

	ft_printf("[%#10.1f]\n", -3.141593);
	printf("[%#10.1f]\n", -3.141593);



	ft_printf("[%015.1lf]\n", -958.125);
	printf("[%015.1lf]\n",-958.125);

	ft_printf("[%015.1lf]\n", 958.125);
	printf("[%015.1lf]\n",958.125);

	ft_printf("[%#0lf]\n", -958.125);
	printf("[%#0lf]\n",-958.125);


	ft_printf("[%#10.f]\n",   3.141593);
	printf("[%#10.f]\n",   3.141593);

	ft_printf("[%#.f]\n",   -3.141593);
	printf("[%#.f]\n",   -3.141593);

	ft_printf("[%#-10.f]\n",  -6.393847);
	printf("[%#-10.f]\n",  -6.393847);


	ft_printf("[% #10.0lf]\n", -6.393847);
	printf("[% #10.0lf]\n", -6.393847);

	ft_printf("[% #.f]\n",   3.141593);
	printf("[% #.f]\n",   3.141593);

	ft_printf("[% #.f]\n",   -3.141593);
	printf("[% #.f]\n",   -3.141593);

	ft_printf("[% -10.5f]\n",  -6.393847);
	printf("[% -10.5f]\n",  -6.393847);

	ft_printf("[% -10.5f]\n",  6.393847);
	printf("[% -10.5f]\n",  6.393847);



	ft_printf("[% 10f]\n",  6.393847);
	printf("[% 10f]\n",  6.393847);


	ft_printf("%10f\n",  6.393847);
	printf("%10f\n",  6.393847);

	ft_printf("[%10f]\n",  -6.393847);
	printf("[%10f]\n",  -6.393847);

	ft_printf("[% 10f]\n",  -6.393847);
	printf("[% 10f]\n",  -6.393847);

	ft_printf("[%10f]\n", -1.000000);
	printf("[%10f]\n",-1.000000);

	ft_printf("[%010.0lf]\n", -6.393847);
	printf("[%010.0lf]\n", -6.393847);

	ft_printf("[%010.0d]\n", 0);
	printf("[%010.0d]\n", 0);

	ft_printf("[%+7d]\n", 0);
	printf("[%+7d]\n", 0);

	ft_printf("[%hhd]\n", -2147483648);
	printf("[%hhd]\n", -2147483648);

	ft_printf("[%010hhd]\n", -2147483648);
	printf("[%010hhd]\n", -2147483648);

	ft_printf("[%#015.0x]\n", -2147483648);
	printf("[%#015.0x]\n", -2147483648);

	ft_printf("[%#10.0hx]\n", 1);
	printf("[%#10.0hx]\n", 1);

	ft_printf("[%#010.0hx]\n", 1);
	printf("[%#010.0hx]\n", 1);

	ft_printf("[%010.0hhi]\n", 0);
	printf("[%010.0hhi]\n", 0);

	ft_printf("[%010.0hhi]\n", -2147483648);
	printf("[%010.0hhi]\n", -2147483648);

	ft_printf("[%010.0hhi]\n", 0);
	printf("[%010.0hhi]\n", 0);

	ft_printf("[%#ho]\n",  2147483648);
	printf("[%#ho]\n",  2147483648);

	ft_printf("[%#010.0hx]\n",  2147483648);
	printf("[%#010.0hx]\n",  2147483648);

	 ft_printf("[%5d]\n", -12);
		printf("[%5d]\n", -12);

	 ft_printf("[%-5d]\n", -12);
		printf("[%-5d]\n", -12);

	 ft_printf("[%-05d]\n", -12);
		printf("[%-05d]\n", -12);

	 ft_printf("[%+10.5d]\n", -12);
		printf("[%+10.5d]\n", -12);

	 ft_printf("[%+10.5d]\n", -12);
		printf("[%+10.5d]\n", -12);

	 ft_printf("[%+10.5d]\n", 4242);
		printf("[%+10.5d]\n", 4242);

	  ft_printf("MY [%.5d]\n", 42);
	 	printf("OG [%.5d]\n", 42);

	 ft_printf("[%05d]\n", 42);
		printf("[%05d]\n", 42);

	 ft_printf("[%5d]\n", -42);
		printf("[%5d]\n", -42);

	 ft_printf("MY [%05d]\n", 42);
		printf("OG [%05d]\n", 42);

	 ft_printf("[%03.2d]\n", -1);
		printf("[%03.2d]\n", -1);

	 ft_printf("[%20s]\n", str);
	 printf("[%20s]\n", str);
	 ft_printf("[%s]\n", str);
	 printf("[%s]\n", str);
	 ft_printf("[% 10.10u]\n", 10);
	 printf("[% 10.10u]\n", 10);
	 ft_printf("[%+10.10u]\n", 10);
	 printf("[%+10.10u]\n", 10);
	  ft_printf("[%- 15.10u]\n", 10);
	 printf("[%- 15.10u]\n", 10);

	 ft_printf("[%#0 15u]\n", 10);
	 printf("[%#0 15u]\n", 10);

	 ft_printf("[%#10.10u]\n", -1231231);
	 printf("[%#10.10u]\n", -1231231);
	 ft_printf("[%010.10d]\n", 10);
	// ft_printf("[%20c]\n", 60);
	 ft_printf("[%#-10.5x]\n", 60);
	 printf("[%#-10.5x]\n", 60);

	 ft_printf("[%#12.15x]\n", 60);
	 printf("[%#12.15x]\n", 60);

	 ft_printf("[%#10.11x]\n", 60);
	 printf("[%#10.11x]\n", 60);

	 ft_printf("[%#10.5x]\n", 60);
	 printf("[%#10.5x]\n", 60);

	 ft_printf("[%#-15.12x]\n", 150);
	 printf("[%#-15.12x]\n", 150);

	 ft_printf("[%#-x]\n", 60);
	 printf("[%#-x]\n", 60);
	//  ft_printf("[%c]\n", '\0');
	//  printf("[%10c]\n", 60);
	 ft_printf("[%10c]\n", 70);
	 printf("[%10c]\n", 70);
	 ft_printf("[%20.s]\n", str);

	 ft_printf("[%%]\n");
	 printf("[%%]\n");

	 ft_printf("[%050%]\n");
	 printf("[%050%]\n");

	 ft_printf("[%-50%]\n");
	 printf("[%-50%]\n");

	 ft_printf("[%     %]\n");
	 printf("[%     %]\n");

	 ft_printf("[%#%]\n");
	 printf("[%#%]\n");

	 ft_printf("[%*s]\n", -32, "abc");
		printf("[%*s]\n", -32, "abc");

	 ft_printf("[%.f]\n", 1.5);
		printf("[%.f]\n", 1.5);





	 ft_printf("[%.f]\n", 9.50000);
		printf("[%.f]\n", 9.50000);

	 ft_printf("[%.15f]\n", 1.00002);
		printf("[%.15f]\n", 1.00002);


	 ft_printf("[%.15f]\n", 1.56423335);
		printf("[%.15f]\n", 1.56423335);


	 ft_printf("[%.15f]\n", 1.5643339);
		printf("[%.15f]\n", 1.5643339);
	 ft_printf("[%2.3o]\n", 0);
		printf("[%2.3o]\n", 0);


	 ft_printf("[%2.2o]\n", 0);
		printf("[%2.2o]\n", 0);

	 ft_printf("[%2.1o]\n", 0);
		printf("[%2.1o]\n", 0);

	 ft_printf("[%#2.1o]\n", 0);
		printf("[%#2.1o]\n", 0);

	 ft_printf("[%-#2.1x]\n", 0);
		printf("[%-#2.1x]\n", 0);

	 ft_printf("[%2.2x]\n", 0);
		printf("[%2.2x]\n", 0);

	 ft_printf("[%2.1o]\n", 0);
		printf("[%2.1o]\n", 0);

	 ft_printf("[%#2.1o]\n", 0);
		printf("[%#2.1o]\n", 0);

	 ft_printf("[%-#2.1o]\n", 0);
		printf("[%-#2.1o]\n", 0);

	 ft_printf("[%-#2.2o]\n", 0);
		printf("[%-#2.2o]\n", 0);

	 ft_printf("[%-#2.3o]\n", 0);
		printf("[%-#2.3o]\n", 0);

	 ft_printf("[%-2.1o]\n", 0);
		printf("[%-2.1o]\n", 0);

	 ft_printf("[%-2.2o]\n", 0);
		printf("[%-2.2o]\n", 0);

	 ft_printf("[%-1.0d]\n", 0);
		printf("[%-1.0d]\n", 0);

	 ft_printf("[% -6.4d]\n", 0);
		printf("[% -6.4d]\n", 0);

	 ft_printf("[% -3.0d]\n", 0);
		printf("[% -3.0d]\n", 0);



	 ft_printf("[% -0.2d]\n", 0);
		printf("[% -0.2d]\n", 0);

	 ft_printf("[% -1.2d]\n", 0);
		printf("[% -1.2d]\n", 0);

	 ft_printf("[% -1.1d]\n", 0);
		printf("[% -1.1d]\n", 0);

	 ft_printf("[% -1d]\n", 0);
		printf("[% -1d]\n", 0);

		 ft_printf("[% -1.0d]\n", 0);
		printf("[% -1.0d]\n", 0);

	 ft_printf("[% -0.0d]\n", 0);
		printf("[% -0.0d]\n", 0);


	 ft_printf("[% +6d]\n", 33333);
		printf("[% +6d]\n", 33333);

		 ft_printf("[%+1.0d]\n", 33333);
		printf("[%+1.0d]\n", 33333);

	 ft_printf("[%0p]\n", -10);
		printf("[%0p]\n", -10);

	 ft_printf("[%p]\n", -10);
		printf("[%p]\n", -10);

	 ft_printf("[%-20p]\n", 10);
		printf("[%-20p]\n", 10);

	 ft_printf("[%20p]\n", 10);
		printf("[%20p]\n", 10);



	 ft_printf("[%s  %x    %X %c %u  %p  ]\n", str, uin, uin, c,uin, &i);
		printf("[%s  %x    %X %c %u  %p  ]\n", str, uin, uin, c,uin, &i);

	 ft_printf("[%010d]\n", 3);
		printf("[%010d]\n", 3);
	 ft_printf("[%0#10.1f]\n", -958.125000);
		printf("[%0#10.1f]\n", -958.125000);
	 ft_printf("[%f]\n", 3.1);
		printf("[%f]\n", 3.1);

	 ft_printf("[%10f]\n", 0.876509);
		printf("[%10f]\n", 0.876509);

	 ft_printf("[%f]\n", -958.125000);
		printf("[%f]\n", -958.125000);

	 ft_printf("[%f]\n", -0.100000);
		printf("[%f]\n", -0.100000);

	 ft_printf("[%f]\n", -1.100000);
		printf("[%f]\n", -1.100000);

	 ft_printf("[%.f]\n", -199.9);
		printf("[%.f]\n", -199.9);

	 ft_printf("[%10.1f]\n", -199.9);
		printf("[%10.1f]\n", -199.9);

	 ft_printf("[%f]\n", 0.100000);
		printf("[%f]\n", 0.100000);

	 ft_printf("[%f]\n", 1.100000);
		printf("[%f]\n", 1.100000);

	 ft_printf("[%.f]\n", -99.500000);
		printf("[%.f]\n", -99.500000);

	 ft_printf("[%10.1f]\n", 199.9);
		printf("[%10.1f]\n", 199.9);


	 ft_printf("[%#.f]\n", 9.400000);
		printf("[%#.f]\n", 9.400000);

	 ft_printf("[%.f]\n", 2.500000);
		printf("[%.f]\n", 2.500000);

	 ft_printf("[%.1f]\n", 1.500000);
		printf("[%.1f]\n", 1.500000);

	 ft_printf("[%.2f]\n", 958.125000);
		printf("[%.2f]\n", 958.125000);

	 ft_printf("[%f]\n", 99.500000);
		printf("[%f]\n", 99.500000);

	 ft_printf("[%f]\n", -0.0);
		printf("[%f]\n", -0.0);

	 ft_printf("[%#10.8hho]\n", (unsigned char)250);
		printf("[%#10.8hho]\n", (unsigned char)250);
	 ft_printf("% 03d\n", 0);
		printf("% 03d\n", 0);

	 ft_printf("%.5p\n", 5);
		printf("%.5p\n", 5);

	 ft_printf("%p\n", 0);
		printf("%p\n", 0);
	 ft_printf("{%0*.*d}\n",-20,-15, 42);
		printf("{%0*.*d}\n",-20,-15, 42);



	 ft_printf("[%.5x]\n", 21);
		printf("[%.5x]\n", 21);



	return 0;
}
