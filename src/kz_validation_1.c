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

int 	g_validation(char *str)
{
	char		*line;
	static int	y;

	line = NULL;
	if (!(str[0] == '-' && str[1] == 'a' && str[2] == '\0'))
	{
		g_asm.c = 0;
		y++;
		(g_asm.fd = open(str, O_RDONLY)) == -1 ? print_usage(2, str) : 0;
		if (g_asm.fd == -1)
			return (0);
		g_file = record_file(str, y);
		while (get_next_line(g_asm.fd, &line) > 0)
			record_labels(line);
	}
	return (0);
}