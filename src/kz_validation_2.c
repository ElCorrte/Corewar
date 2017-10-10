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
	i = find_name(tmp, 0);
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
		a = find_name(tmp, 0);
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
	if (tmp)
		i = 0;
	return (1);
}

int 	find_name(t_file *tmp, int i)
{
	while (i < 16)
	{
		if (!(ft_strncmp(g_tab[i].name, tmp->labels->str,
						 ft_strlen(g_tab[i].name))))
			return (i);
		i++;
	}
	return (-1);
}