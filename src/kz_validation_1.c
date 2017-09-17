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
		y++;
		if ((g_asm.fd = open(str, O_RDONLY)) == -1)
		{
			print_usage(2, str);
			return (0);
		}
		g_file = record_file(str, y);
		while (get_next_line(g_asm.fd, &line) > 0)
			record_labels(line);
		if (looking_for_errors())
			return (1);
	}
	return (0);
}

int 	looking_for_errors(void)
{
	t_file	*tmp;

	tmp = g_file;
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp->labels != NULL)
	{
		if (g_asm.line == 1 || g_asm.line == 2)
			if (!(checkout_name_comm(tmp)))
				return (0);
		tmp->labels = tmp->labels->next;
		g_asm.line++;
	}
}

int		checkout_name_comm(t_file *tmp)
{
	while (ft_isspace(*tmp->labels->str))
		tmp->labels->str++;
	if (!(ft_strncmp(NAME_CMD_STRING, tmp->labels->str, 5)))
	{
		tmp->labels->str += 5;
		g_asm.check_line_for_name = g_asm.line;
		g_asm.f_name++;
	}
	else if (!(ft_strncmp(COMMENT_CMD_STRING, tmp->labels->str, 8)))
	{
		tmp->labels->str += 8;
		g_asm.check_line_for_comm = g_asm.line;
		g_asm.f_comment++;
	}
	else {
		print_usage(3, "none");
		return (0);
	}
	while (ft_isspace(*tmp->labels->str))
		tmp->labels->str++;
}
