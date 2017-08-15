/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 13:13:54 by kzakharc          #+#    #+#             */
/*   Updated: 2017/08/15 13:13:56 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int 	main(int argc, char **argv)
{
	int 	i;

	i = 0;
	lets_get_null();
	(argc == 1) ? print_usage(0) : 0;
	if (argc > 1)
	{
		while (++i <= (argc - 1))
			check_and_read(argv[i]);
	}
	(g_asm.a == 1) ? ft_printf("жопка попка") : 0;
	return (0);
}