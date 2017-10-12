/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kz_check_param_of_instruction.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 13:00:32 by kzakharc          #+#    #+#             */
/*   Updated: 2017/10/11 13:00:34 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		check_direct(t_labels *tmp, int i, int q, int last)
{
	g_asm.last = last;
	if (tmp->str[g_asm.p] != DIRECT_CHAR)
		return (print_usage_1(0, g_tab[i].name, q, "indirect"));
	g_asm.p++;
	if (tmp->str[g_asm.p] == LABEL_CHAR || tmp->str[g_asm.p] == '-' ||
		ft_isdigit(tmp->str[g_asm.p]))
	{
		if (tmp->str[g_asm.p] == LABEL_CHAR)
		{
			if (find_label(tmp, g_file, i))
				return (check_separator(tmp, q, i, "indirect"));
			return (0);
		}
		if (tmp->str[g_asm.p] == '-')
			g_asm.p++;
		while ((tmp->str[g_asm.p] != SEPARATOR_CHAR) &&
				!(ft_isspace(tmp->str[g_asm.p])) && (tmp->str[g_asm.p] != '\0'))
		{
			if (!(ft_isdigit(tmp->str[g_asm.p])))
				return (print_usage(4, "nope"));
			g_asm.p++;
		}
		return (check_separator(tmp, q, i, "indirect"));
	}
	else
		return (print_usage(4, "nope"));
}

int 	check_separator(t_labels *tmp, int q, int i, char *s)
{
	if (tmp->str[g_asm.p] == SEPARATOR_CHAR && g_asm.last != -1)
		return (1);
	if (tmp->str[g_asm.p] == SEPARATOR_CHAR && g_asm.last == -1)
		return (print_usage_1(2, g_tab[i].name, q, "nope"));
	if (ft_isspace(tmp->str[g_asm.p]) && g_asm.last != -1)
		return (print_usage_1(1, g_tab[i].name, q, s));
	if (ft_isspace(tmp->str[g_asm.p]) && g_asm.last == -1)
	{
		while (ft_isspace(tmp->str[g_asm.p]) && tmp->str[g_asm.p] != '\0')
			g_asm.p++;
		if (tmp->str[g_asm.p] != '\0' && tmp->str[g_asm.p] != COMMENT_CHAR  &&
				tmp->str[g_asm.p] != ';')
			return (print_usage(11, "nope"));
		else
			return (1);
	}
	if (tmp->str[g_asm.p] == '\0' && g_asm.last == -1)
		return (1);
	return (0);
}

int 	find_label(t_labels *tmp, t_file *t, int i)
{
	size_t	c;
	t_labels	*fn;
	char		*str;

	c = 0;
	while (t->next != NULL)
		t = t->next;
	fn = t->labels;
	g_asm.p++;
	while (tmp->str[g_asm.p + c] != SEPARATOR_CHAR &&
			!ft_isspace(tmp->str[g_asm.p + c]) && tmp->str[g_asm.p + c] != '\0')
		c++;
	str = tmp->str;
	str += g_asm.p;
	g_asm.p += c;
	while (fn != NULL)
	{
		skip_blank_lines(fn, -1);
		if (!(ft_strncmp(str, fn->str, c)) && fn->str[c] == LABEL_CHAR)
			return (1);
		fn = fn->next;
	}
	return (print_usage_1(3, g_tab[i].name, 0, "nope"));
}