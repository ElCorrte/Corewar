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
