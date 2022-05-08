/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:10:04 by mviinika          #+#    #+#             */
/*   Updated: 2022/05/08 22:03:55 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int main()
{

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

	ft_printf("[%b]\n" , 0);

	// ft_printf("[%0#.1f]\n", -3.141593);
	// printf("[%0#.1f]\n",-3.141593);

	// ft_printf("[%0#10.1f]\n", -3.141593);
	// printf("[%0#10.1f]\n", -3.141593);



	// ft_printf("[%010f]\n", 1.000000);
	// printf("[%010f]\n",1.000000);

	// ft_printf("[%0#10.1f]\n", -3.141593);
	// printf("[%0#10.1f]\n", -3.141593);


	// ft_printf("[%#10.1f]\n", 3.141593);
	// printf("[%#10.1f]\n",3.141593);

	// ft_printf("[%#10.1f]\n", -3.141593);
	// printf("[%#10.1f]\n", -3.141593);



	// ft_printf("[%015.1lf]\n", -958.125);
	// printf("[%015.1lf]\n",-958.125);

	// ft_printf("[%015.1lf]\n", 958.125);
	// printf("[%015.1lf]\n",958.125);

	// ft_printf("[%#0lf]\n", -958.125);
	// printf("[%#0lf]\n",-958.125);


	// ft_printf("[%#10.f]\n",   3.141593);
	// printf("[%#10.f]\n",   3.141593);

	// ft_printf("[%#.f]\n",   -3.141593);
	// printf("[%#.f]\n",   -3.141593);

	// ft_printf("[%#-10.f]\n",  -6.393847);
	// printf("[%#-10.f]\n",  -6.393847);


	// ft_printf("[% #10.0lf]\n", -6.393847);
	// printf("[% #10.0lf]\n", -6.393847);

	// ft_printf("[% #.f]\n",   3.141593);
	// printf("[% #.f]\n",   3.141593);

	// ft_printf("[% #.f]\n",   -3.141593);
	// printf("[% #.f]\n",   -3.141593);

	// ft_printf("[% -10.5f]\n",  -6.393847);
	// printf("[% -10.5f]\n",  -6.393847);

	// ft_printf("[% -10.5f]\n",  6.393847);
	// printf("[% -10.5f]\n",  6.393847);



	// ft_printf("[% 10f]\n",  6.393847);
	// printf("[% 10f]\n",  6.393847);


	// ft_printf("%10f\n",  6.393847);
	// printf("%10f\n",  6.393847);

	// ft_printf("[%10f]\n",  -6.393847);
	// printf("[%10f]\n",  -6.393847);

	// ft_printf("[% 10f]\n",  -6.393847);
	// printf("[% 10f]\n",  -6.393847);

	// ft_printf("[%10f]\n", -1.000000);
	// printf("[%10f]\n",-1.000000);

	// ft_printf("[%010.0lf]\n", -6.393847);
	// printf("[%010.0lf]\n", -6.393847);

	// ft_printf("[%010.0d]\n", 0);
	// printf("[%010.0d]\n", 0);

	// ft_printf("[%+7d]\n", 0);
	// printf("[%+7d]\n", 0);

	// ft_printf("[%hhd]\n", -2147483648);
	// printf("[%hhd]\n", -2147483648);

	// ft_printf("[%010hhd]\n", -2147483648);
	// printf("[%010hhd]\n", -2147483648);

	// ft_printf("[%#015.0x]\n", -2147483648);
	// printf("[%#015.0x]\n", -2147483648);

	// ft_printf("[%#10.0hx]\n", 1);
	// printf("[%#10.0hx]\n", 1);

	// ft_printf("[%#010.0hx]\n", 1);
	// printf("[%#010.0hx]\n", 1);

	// ft_printf("[%010.0hhi]\n", 0);
	// printf("[%010.0hhi]\n", 0);

	// ft_printf("[%010.0hhi]\n", -2147483648);
	// printf("[%010.0hhi]\n", -2147483648);

	// ft_printf("[%010.0hhi]\n", 0);
	// printf("[%010.0hhi]\n", 0);

	// ft_printf("[%#ho]\n",  2147483648);
	// printf("[%#ho]\n",  2147483648);

	// ft_printf("[%#010.0hx]\n",  2147483648);
	// printf("[%#010.0hx]\n",  2147483648);



	return 0;
}
