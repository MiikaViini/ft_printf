/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:34:02 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/28 13:40:15 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	char k = 'k';
	char kd = 120;

	char *addr = "12345";
	int in = 132313;
	int *p;

	float flout = 123456.123456;
	double doublu = 123456.123456123456;


	p = &in;


	short smad = 32767;
	short sman = -32768;

	unsigned short us = 65535;

	int min = -2147483648;
	int mad = 2147483647;

	unsigned int umad = 4294967295;

	long lmad = 2147483647;
	long lmin = -2147483648;

	long int joo = -1231231231231;
	long long  llmin = -9223372036854775808;
	long long llmad = 9223372036854775807;

	//unsigned long long ullmad = 18446744073709551615;

	printf("string OG %lld\n", joo);
	ft_printf("string IM %lld\n", joo);



	printf("string OG %d\n", k);
	ft_printf("string IM %d\n", k);

	printf("string OG %hd\n", kd);
	ft_printf("string IM %hd\n", kd);

	printf("string OG %d\n", sman);
	ft_printf("string IM %d\n", sman);

	printf("string OG %d\n", smad);
	ft_printf("string IM %d\n", smad);

	printf("string OG %hd\n", us);
	ft_printf("string IM %hd\n", us);

	printf("string OG %ld\n", lmad);
	ft_printf("string IM %ld\n", lmad);

	printf("string OG %ld\n", lmin);
	ft_printf("string IM %ld\n", lmin);

	printf("string OG %lld\n", llmad);
	ft_printf("string IM %lld\n", llmad);

	printf("string OG %lld\n", llmin);
	ft_printf("string IM %lld\n", llmin);

	printf("string OG %llu\n", ULONG_MAX);
	ft_printf("string IM %llu\n", ULONG_MAX);

	printf("string OG %p\n", ULONG_MAX);
	ft_printf("string IM %p\n", ULONG_MAX);

	printf("string OG %p\n", p);
	ft_printf("string IM %p\n",p);

	printf("string OG %c\n", k);
	ft_printf("string IM %c\n",k);

	printf("string OG %c\n", kd);
	ft_printf("string IM %c\n",kd);

	printf("string OG %s\n", "pergule");
	ft_printf("string IM %s\n","pergule");

	printf("string OG %s\n", addr);
	ft_printf("string IM %s\n",addr);

	printf("string OG %s\n", " ");
	ft_printf("string IM %s\n"," ");

	printf("string OG %o\n", llmad);
	ft_printf("string IM %o\n",llmad);

	printf("string OG %o\n", in);
	ft_printf("string IM %o\n",in);

	printf("string OG %o\n", smad);
	ft_printf("string IM %o\n",smad);


	printf("string OG %o\n", sman);
	ft_printf("string IM %o\n",sman);

	printf("string OG %o\n", us);
	ft_printf("string IM %o\n",us);


	printf("string OG %lo\n", llmad);
	ft_printf("string IM %lo\n",llmad);

	printf("string OG %o\n", in);
	ft_printf("string IM %o\n",in);

	printf("string OG %lo\n", smad);
	ft_printf("string IM %lo\n",smad);


	printf("string OG %lo\n", sman);
	ft_printf("string IM %lo\n",sman);

	printf("string OG %lo\n", us);
	ft_printf("string IM %lo\n",us);

		printf("string OG %llo\n", llmad);
	ft_printf("string IM %llo\n",llmad);

	printf("string OG %llo\n", in);
	ft_printf("string IM %llo\n",in);

	printf("string OG %llo\n", smad);
	ft_printf("string IM %llo\n",smad);


	printf("string OG %llo\n", sman);
	ft_printf("string IM %llo\n",sman);

	printf("string OG %llo\n", us);
	ft_printf("string IM %llo\n",us);


		printf("string OG %ho\n", llmad);
	ft_printf("string IM %ho\n",llmad);

	printf("string OG %ho\n", in);
	ft_printf("string IM %ho\n",in);

	printf("string OG %ho\n", smad);
	ft_printf("string IM %ho\n",smad);


	printf("string OG %ho\n", sman);
	ft_printf("string IM %ho\n",sman);

	printf("string OG %ho\n", us);
	ft_printf("string IM %ho\n",us);



		printf("string OG %hho\n", llmad);
	ft_printf("string IM %hho\n",llmad);

	printf("string OG %hho\n", in);
	ft_printf("string IM %hho\n",in);

	printf("string OG %hho\n", smad);
	ft_printf("string IM %hho\n",smad);


	printf("string OG %ho\n", sman);
	ft_printf("string IM %ho\n",sman);

	printf("string OG %ho\n", us);
	ft_printf("string IM %ho\n",us);

	printf("string OG octal %llo\n", ULONG_MAX);
	ft_printf("string IM octal %llo\n", ULONG_MAX);

	printf("string OG %llo\n", llmad);
	ft_printf("string IM %llo\n",llmad);

		printf("string OG %llx\n", -9223372036854775808);
	ft_printf("string IM %llx\n", -9223372036854775808);

		printf("string OG %f\n", flout);
	ft_printf("string IM %f\n", flout);

		printf("string OG %Lf\n", flout);
	ft_printf("string IM %Lf\n", flout);

	printf("string OG %lf\n", flout);
	ft_printf("string IM %lf\n", flout);

	printf("string OG %llf\n", flout);
	ft_printf("string IM %llf\n", flout);

	printf("string OG %f\n", doublu);
	ft_printf("string IM %f\n", doublu);

		printf("string OG %Lf\n", doublu);
	ft_printf("string IM %Lf\n", doublu);

	printf("string OG %lf\n", doublu);
	ft_printf("string IM %lf\n", doublu);

	printf("string OG %llf\n", doublu);
	ft_printf("string IM %llf\n", doublu);
	return (0);
}
