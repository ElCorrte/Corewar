/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kz_secondary_functions_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 17:28:01 by kzakharc          #+#    #+#             */
/*   Updated: 2017/10/14 17:28:02 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		is_it_label(t_labels *tmp, int i)
{
	while (tmp->str[g_asm.p] != LABEL_CHAR &&
		   !(ft_isspace(tmp->str[g_asm.p])))
	{
		if (!find_char(tmp->str[g_asm.p], 0))
			return (print_usage(4, "nope"));
		g_asm.p++;
	}
	if (tmp->str[g_asm.p] != LABEL_CHAR)
		return (print_usage(13, g_tab[i].name));
	else
		return (1);
}

char 	*usage(void)
{
	t_file	*tmp;

	tmp = g_file;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp->file_name);
}