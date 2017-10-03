/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kz_secondary_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 18:24:43 by kzakharc          #+#    #+#             */
/*   Updated: 2017/08/15 18:24:44 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	lets_get_null(void)
{
	g_file = NULL;
	g_asm.a = 0;
	g_asm.fd = 0;
	g_asm.c = 0;
	g_asm.f_comment = 0;
	g_asm.f_name = 0;
	g_asm.line = 1;
	g_asm.column = 1;
}

void	lets_get_null_for_file(void)
{
	g_asm.c = 0;
	g_asm.f_comment = 0;
	g_asm.f_name = 0;
	g_asm.line = 1;
	g_asm.column = 0;
}

t_labels	*skip_blank_lines(t_file *tmp)
{
	while (ft_isspace(*tmp->labels->str) || (*tmp->labels->str == '\0'))
	{
		while (ft_isspace(*tmp->labels->str))
			tmp->labels->str++;
		if (*tmp->labels->str == '\0')
			tmp->labels = tmp->labels->next;
	}
	return (tmp->labels);
}

int 		finaly_check_name_comm(t_file *tmp, int i, int n, int a)
{
	if (tmp->labels->str[i] == '"' && tmp->labels->str[n] == '\0')
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
	return (0);
}

/*
void	print_all_this_shit(void)
{
	t_file		*tmp;

	tmp = g_file;
	while (tmp != NULL)
	{
		while (tmp->labels != NULL)
		{
			ft_printf("%s\n", tmp->labels->str);
			tmp->labels = tmp->labels->next;
		}
		ft_printf("-------------------------------------------\n");
		tmp = tmp->next;
	}
}*/
