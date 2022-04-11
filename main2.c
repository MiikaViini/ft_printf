/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:34:02 by mviinika          #+#    #+#             */
/*   Updated: 2022/04/10 21:32:33 by mviinika         ###   ########.fr       */
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
	int i = 0;
	int a = 0;

	i = ft_printf("%+d\n", -54);


	a =	printf("%+d\n", -54);

	printf("%d", a);
	return (0);
}
