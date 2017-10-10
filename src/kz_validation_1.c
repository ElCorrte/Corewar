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
	char 		c[1];
	static int	y;

	line = NULL;
	if (!(str[0] == '-' && str[1] == 'a' && str[2] == '\0'))
	{
		y++;
		if ((g_asm.fd = open(str, O_RDONLY)) == -1)
			return (print_usage(2, str));
		g_file = record_file(str, y);
		if (lseek(g_asm.fd, -1, SEEK_END) < 0)
			return (print_usage(10, "Seek Error"));
		if (read(g_asm.fd, c, 1) < 0)
			return (print_usage(10, "Read Error"));
		if (lseek(g_asm.fd, 0, SEEK_SET) < 0)
			return (print_usage(10, "Seek Error"));
		while (get_next_line(g_asm.fd, &line) > 0)
			record_labels(line);
		if (c[0] != '\n' && (g_asm.q = looking_for_errors()) != 2)
			return (print_usage(9, str));
		else if (g_asm.q > 0)
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
		tmp->labels = skip_blank_lines(tmp);
		if (*tmp->labels->str == '\0' && tmp->labels->next == NULL)
			return (2);
		if (g_asm.line == 1 || g_asm.line == 2)
			if (!(checkout_name_comm(tmp, 0)))
				return (0);
		if (g_asm.line > 2 && tmp->labels->str)
			if (!(checkout_body(tmp, 0, 0)))
				return (0);
		tmp->labels = tmp->labels->next;
		g_asm.line++;
		g_asm.l++;
	}
	if (ft_strlen(tmp->name) > 128)
		return (print_usage(12, "Champion name too long (Max length 128)"));
	if (ft_strlen(tmp->comm) > 2048)
		return (print_usage(12, "Champion comment too long (Max length 2048)"));
	return (1);
}

int		checkout_name_comm(t_file *tmp, int a)
{
	tmp->labels = skip_blank_lines(tmp);
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
	else if (check_no_repit(tmp))
		return (print_usage(3, "none"));
	else
		return (0);
	while (ft_isspace(*tmp->labels->str))
		tmp->labels->str++;
	if (check_no_repit(tmp))
		return (check_comment(tmp, 0, a));
	return (0);
}

int 	check_comment(t_file *tmp, int i, int a)
{
	int		n;

	if (*tmp->labels->str == '"')
	{
		tmp->labels->str++;
		while (tmp->labels->str[i] != '"' && tmp->labels->str[i] != '\0')
			i++;
		if (tmp->labels->str[i] == '\0')
			return (print_usage(11, "none"));
		n = i + 1;
		while (ft_isspace(tmp->labels->str[n]))
			n++;
		if (finaly_check_name_comm(tmp, i, n, a))
			return (1);
		else
			print_usage(11, "none");
	}
	else
		print_usage(4, "none");
	return (0);
}

int 	check_no_repit(t_file *tmp)
{
	if (g_asm.line == 2 && (g_asm.f_name == 0 || g_asm.f_comment == 0))
	{
		if ((g_asm.f_name == 0) && (g_asm.f_comment > 1))
			print_usage(5, ".comment");
		else if ((g_asm.f_comment == 0) && (g_asm.f_name > 1))
			print_usage(6, ".name");
		else
			print_usage(7, tmp->labels->str);
		return (0);
	}
	return (1);
}
