/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kz_validation_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 16:07:51 by kzakharc          #+#    #+#             */
/*   Updated: 2017/10/07 16:07:52 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int 	checkout_body(t_labels *tmp, int a, int i)
{
	i = find_name(tmp, 15);
	if (i == -1)
	{
		while (tmp->str[g_asm.p] != LABEL_CHAR &&
				!(ft_isspace(tmp->str[g_asm.p])))
		{
			if (!find_char(tmp->str[g_asm.p], 0))
				return (print_usage(4, "nope"));
			g_asm.p++;
		}
		(tmp->str[g_asm.p] != LABEL_CHAR) ? i = -2 : 0;
		g_asm.p++;
		while (ft_isspace(tmp->str[g_asm.p]))
			g_asm.p++;
		a = find_name(tmp, 15);
		if (a == -1)
			return (print_usage(8, "nope"));
		else if (i == -2)
			return (print_usage(11, "nope"));
		else if (!(check_param(tmp, a)))
			return (0);
	}
	else if (!(check_param(tmp, i)))
		return (0);
	return (1);
}

int 	check_all_labels(int p)
{
	t_labels	*tmp;

	tmp = leaf_list(g_file);
	while (tmp != NULL)
	{
		tmp = skip_blank_lines(tmp, -3);
		if (tmp->str[0] == '\0' && tmp->next == NULL)
			break ;
		if (find_name(tmp, 15) == -1)
		{
			while (tmp->str[p] != LABEL_CHAR &&
				   !(ft_isspace(tmp->str[p])))
			{
				if (!find_char(tmp->str[p], 0))
					return (print_usage_0(0));
				p++;
			}
			if (tmp->str[p] != LABEL_CHAR)
				return (print_usage_0(1));
		}
		tmp = tmp->next;
		g_asm.count++;
	}
	return (1);
}

int 	check_param(t_labels *tmp, int i)
{
	g_asm.p += ft_strlen(g_tab[i].name);
	if ((i == 0) || (i == 8) || (i == 11) || (i == 14) || (i == 15))
		if (!(instruction_with_one_param(tmp, i)))
			return (0);
/*	if ((i == 3) || (i == 4))
		if (!(instruction_with_three_param1_1_1(tmp, i)))
			return (0);
	if ((i == 5) || (i == 6) || (i == 7))
		if (!(instruction_with_three_param3_3_1(tmp, i)))
			return (0);
	if ((i == 1) || (i == 12))
		if (!(instruction_with_two_param2_1(tmp, i)))
			return (0);
	if ((i == 9) || (i == 13))
		if (!(instruction_with_three_param3_2_1(tmp, i)))
			return (0);
	if (i == 10)
		if (!(instruction_with_three_param1_3_2(tmp, i)))
			return (0);
	if (i == 10)
		if (!(instruction_with_three_param1_3_2(tmp, i)))
			return (0);
	if (i == 2)
		if (!(instruction_with_two_param1_2(tmp, i)))
			return (0);*/
	return (1);
}

int 	instruction_with_one_param(t_labels *tmp, int i)
{
	if (!(ft_isspace(tmp->str[g_asm.p])))
		return (print_usage(13, g_tab[i].name));
	g_asm.p++;
	if (g_tab[i].arg[0] == T_DIR)
		return (check_direct(tmp, i, 1, -1));
	return (1);
}

int 	find_name(t_labels *tmp, int i)
{
	char	*t;
	int 	d;

	t = tmp->str;
	t += g_asm.p;
	while (i >= 0)
	{
		d = g_asm.p;
		d += ft_strlen(g_tab[i].name);
		if (!(ft_strncmp(g_tab[i].name, t, ft_strlen(g_tab[i].name))))
		{
			while (ft_isspace(tmp->str[d]))
				d++;
			if (tmp->str[d] != LABEL_CHAR)
				return (i);
		}
		i--;
	}
	return (-1);
}