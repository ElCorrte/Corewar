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
	check_and_read("non", 0);
	(argc == 1) ? print_usage(0, "none") : 0;
	if (argc > 1)
		while (++i <= (argc - 1))
			(argv[i][0] == '-' && argv[i][1] == 'a' && argv[i][2] == '\0') ?
					g_asm.a = 1 : 0;
	i = 0;
	if (argc > 1)
	{
		while (++i <= (argc - 1))
			if (g_validation(argv[i]))
				g_asm.a = 1; /*? print_with_a(argv[i]) : creat_file(argv[i]);*/
	}
	return (0);
}