/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:34:02 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/16 19:41:41 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char 	*str = "tvvr";
	int		i = 456234;
	//long int	li = 21123123123;
	//long long int lli = 12312312313;
	char c = 'A';
	double flo = 1.5653991;

	ft_printf("IMP address	%p\n", str);
	ft_printf("integer		%d\n", i);
	ft_printf("octal		%o\n", i);
	ft_printf("hex		%x\n", i);
	ft_printf("char			%c\n", c);
	ft_printf("integer		%i\n", i);
	ft_printf("float		%f\n", flo);
	ft_printf("string		%s\n", str);
	ft_printf("\n");
	printf("OG address	%p\n", str);
	printf("integer		%d\n", i);
	printf("octal		%o\n", i);
	printf("hex		%x\n", i);
	printf("char		%c\n", c);
	printf("integer		%i\n", i);
	printf("float		%f\n", flo);
	printf("string		%s\n", str);

	return (0);
}
