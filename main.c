/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:34:02 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/21 15:32:10 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{

	unsigned long long int  joo= 123123123123;

	printf("string %hd\n", joo);
	ft_printf("joo %hd", joo);
	return (0);
}
