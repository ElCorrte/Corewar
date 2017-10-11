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

int		check_direct(t_file *tmp, int i, int q)
{
	if (*tmp->labels->str != DIRECT_CHAR)
		return (print_usage_1(0, g_tab[i].name, q, "indirect"));
	tmp->labels->str++;
	if (*tmp->labels->str == LABEL_CHAR || *tmp->labels->str == '-' ||
		ft_isdigit(*tmp->labels->str))
	{
		if (*tmp->labels->str == LABEL_CHAR)
		{
			if (find_label(tmp))
				return (check_separator(tmp, q, i, "indirect"));
			return (0);
		}
		if (*tmp->labels->str == '-')
			tmp->labels->str++;
		while (*tmp->labels->str != SEPARATOR_CHAR &&
				!ft_isspace(*tmp->labels->str) && *tmp->labels->str != '\0')
		{
			if (!(ft_isdigit(*tmp->labels->str)))
				return (print_usage(4, "nope"));
			tmp->labels->str++;
		}
		return (check_separator(tmp, q, i, "indirect"));
	}
	else
		return (print_usage(4, "nope"));
}

int 	check_separator(t_file *tmp, int q, int i, char *s)
{
	if (*tmp->labels->str == SEPARATOR_CHAR && q < 3)
		return (1);
	if (*tmp->labels->str == SEPARATOR_CHAR && q == 3)
		return (print_usage_1(2, g_tab[i].name, q, "nope"));
	if (ft_isspace(*tmp->labels->str) && q != 3)
		return (print_usage_1(1, g_tab[i].name, q, s));
	if (ft_isspace(*tmp->labels->str) && q == 3)
	{
		while (ft_isspace(*tmp->labels->str) && *tmp->labels->str != '\0')
			tmp->labels->str++;
		if (*tmp->labels->str != '\0')
			return (print_usage(11, "nope"));
		else
			return (1);
	}
	if (*tmp->labels->str == '\0' && q == 3)
		return (1);
	return (0);
}

int 	find_label(t_file *tmp)
{
	int 	c;
	t_file	*fn;

	c = 0;
	fn = g_file;
	while (fn->next != NULL)
		fn = fn->next;
	tmp->labels->str++;
	while (tmp->labels->str[c] != SEPARATOR_CHAR &&
			!ft_isspace(tmp->labels->str[c]) && tmp->labels->str[c] != '\0')
		c++;
	while (fn->labels != NULL)
	{
		fn->labels = fn->labels->next;
	}
}