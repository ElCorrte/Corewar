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

int 	checkout_body(t_file *tmp, int a, int i)
{
	i = find_name(tmp, 15);
	if (i == -1)
	{
		while (*tmp->labels->str != LABEL_CHAR &&
				!(ft_isspace(*tmp->labels->str)))
		{
			if (!find_char(*tmp->labels->str, 0))
				return (print_usage(4, "nope"));
			tmp->labels->str++;
		}
		(*tmp->labels->str != LABEL_CHAR) ? i = -2 : 0;
		tmp->labels->str++;
		while (ft_isspace(*tmp->labels->str))
			tmp->labels->str++;
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

int 	check_param(t_file *tmp, int i)
{
	tmp->labels->str += ft_strlen(g_tab[i].name);
	if ((i == 0) || (i == 8) || (i == 11) || (i == 14) || (i == 15))
		if (!(instruction_with_one_param(tmp, i)))
			return (0);
	if ((i == 3) || (i == 4))
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
			return (0);
	return (1);
}

int 	instruction_with_one_param(t_file *tmp, int i)
{
	if (!(ft_isspace(*tmp->labels->str)))
		return (print_usage(13, g_tab[i].name));
	tmp->labels->str++;
	if (g_tab[i].arg[0] == T_DIR)
	{
		if (*tmp->labels->str != DIRECT_CHAR)
			return (print_usage_1(0, g_tab[i].name, 0, "indirect"));
		tmp->labels->str++;
		if (*tmp->labels->str == LABEL_CHAR || *tmp->labels->str == '-' ||
				ft_isdigit(*tmp->labels->str))
		{
			if (*tmp->labels->str == LABEL_CHAR)
			{
				if (!(find_label()))
					return (0);
			}
			else if (*tmp->labels->str == '-')
				tmp->labels->str++;
			else if (!(ft_isdigit(*tmp->labels->str)))
				return (print_usage(4, "nope"));
			else
				return (1);
		}
		else
			return (print_usage(4, "nope"));
	}
}

int 	find_name(t_file *tmp, int i)
{
	while (i >= 0)
	{
		if (!(ft_strncmp(g_tab[i].name, tmp->labels->str,
						 ft_strlen(g_tab[i].name))))
			return (i);
		i--;
	}
	return (-1);
}