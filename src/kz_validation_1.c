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
		while (tmp->labels->str[0] == '\0')
			tmp->labels = tmp->labels->next;
		if (g_asm.line == 1 || g_asm.line == 2)
			if (!(checkout_name_comm(tmp, 0)))
				return (0);
		tmp->labels = tmp->labels->next;
		g_asm.line++;
	}
	return (1);
}

int		checkout_name_comm(t_file *tmp, int a)
{
	while (ft_isspace(*tmp->labels->str))
		tmp->labels->str++;
	if (!(ft_strncmp(NAME_CMD_STRING, tmp->labels->str, 5)))
	{
		tmp->labels->str += 5;
		g_asm.f_name++;
		a = 1;
	}
	else if (!(ft_strncmp(COMMENT_CMD_STRING, tmp->labels->str, 8)))
	{
		tmp->labels->str += 8;
		g_asm.f_comment++;
	}
	else if (check_no_repit())
	{
		print_usage(3, "none");
		return (0);
	}
	else
		return (0);
	while (ft_isspace(*tmp->labels->str))
		tmp->labels->str++;
	if (check_no_repit())
		return (check_comment(tmp, -1, a));
	return (0);
}

int 	check_comment(t_file *tmp, int i, int a)
{
	if (*tmp->labels->str == '"')
	{
		tmp->labels->str++;
		while (tmp->labels->str[++i] != '"' && *tmp->labels->str);
		if (tmp->labels->str[i] == '\0')
		{
			print_usage(4, "none");
			return (0);
		}
		if (tmp->labels->str[i] == '"')
		{
			if (a == 1)
				tmp->name = ft_strnew((size_t)i);
			else
				tmp->comm = ft_strnew((size_t)i);
			if (a == 1)
				tmp->name = ft_strncpy(tmp->name, tmp->labels->str, (size_t)i);
			else
				tmp->comm = ft_strncpy(tmp->comm, tmp->labels->str, (size_t)i);
			return (1);
		}
	}
	else
		print_usage(4, "none");
	return (0);
}

int 	check_no_repit(void)
{
	if (g_asm.line == 2 && g_asm.f_name == 0)
	{
		print_usage(5, "none");
		return (0);
	}
	else if (g_asm.line == 2 && g_asm.f_comment == 0)
	{
		print_usage(8, "none");
		return (0);
	}
	else if (g_asm.f_name > 1)
	{
		print_usage(6, "none");
		return (0);
	}
	else if (g_asm.f_comment > 1)
	{
		print_usage(7, "none");
		return (0);
	}
	return (1);
}
