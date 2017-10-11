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

int		check_direct(t_labels *tmp, int i, int q)
{
	if (*tmp->str != DIRECT_CHAR)
		return (print_usage_1(0, g_tab[i].name, q, "indirect"));
	tmp->str++;
	if (*tmp->str == LABEL_CHAR || *tmp->str == '-' ||
		ft_isdigit(*tmp->str))
	{
		if (*tmp->str == LABEL_CHAR)
		{
			if (find_label(tmp, g_file))
				return (check_separator(tmp, q, i, "indirect"));
			return (0);
		}
		if (*tmp->str == '-')
			tmp->str++;
		while (*tmp->str != SEPARATOR_CHAR &&
				!ft_isspace(*tmp->str) && *tmp->str != '\0')
		{
			if (!(ft_isdigit(*tmp->str)))
				return (print_usage(4, "nope"));
			tmp->str++;
		}
		return (check_separator(tmp, q, i, "indirect"));
	}
	else
		return (print_usage(4, "nope"));
}

int 	check_separator(t_labels *tmp, int q, int i, char *s)
{
	if (*tmp->str == SEPARATOR_CHAR && q < 3)
		return (1);
	if (*tmp->str == SEPARATOR_CHAR && q == 3)
		return (print_usage_1(2, g_tab[i].name, q, "nope"));
	if (ft_isspace(*tmp->str) && q != 3)
		return (print_usage_1(1, g_tab[i].name, q, s));
	if (ft_isspace(*tmp->str) && q == 3)
	{
		while (ft_isspace(*tmp->str) && *tmp->str != '\0')
			tmp->str++;
		if (*tmp->str != '\0')
			return (print_usage(11, "nope"));
		else
			return (1);
	}
	if (*tmp->str == '\0' && q == 3)
		return (1);
	return (0);
}

int 	find_label(t_labels *tmp, t_file *t)
{
	size_t	c;
	t_labels	*fn;

	c = 0;
	while (t->next != NULL)
		t = t->next;
	fn = t->labels;
	tmp->str++;
	while (tmp->str[c] != SEPARATOR_CHAR &&
			!ft_isspace(tmp->str[c]) && tmp->str[c] != '\0')
		c++;
	while (fn != NULL)
	{
		skip_blank_lines(fn);
		if (!(ft_strncmp(tmp->str, fn->str, c)))
			return (1);
		fn = fn->next;
	}
	return (print_usage_1(3, g_tab[0].name, 0, "nope"));
}