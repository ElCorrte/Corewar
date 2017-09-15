/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kz_validation_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 16:11:51 by kzakharc          #+#    #+#             */
/*   Updated: 2017/08/15 16:11:52 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	check_and_read(char *str, int i)
{
	str = NULL;
	i = 0;
}

int 	g_validation(char *str)
{
	char 	*line;

	line = NULL;
	if (!(str[0] == '-' && str[1] == 'a' && str[2] == '\0'))
	{
		g_asm.c = 0;
		(g_asm.fd = open(str, O_RDONLY)) == -1 ? print_usage(2, str) : 0;
		while (get_next_line(g_asm.fd, &line) > 0)
			g_file = record_file(line, str);
	}
	return (0);
}