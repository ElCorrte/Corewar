/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kz_record_files.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 14:26:28 by kzakharc          #+#    #+#             */
/*   Updated: 2017/09/15 14:26:29 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_file		*record_file(char *line, char *str)
{
	t_file		*tmp;

	tmp = g_file;
	if (g_asm.c == 0)
	{
		tmp = (t_file *)malloc(sizeof(t_file));
		tmp->file_name = ft_strdup(str);
		tmp->name = NULL;
		tmp->comment = NULL;
		tmp->labels = (t_labels *)malloc(sizeof(t_labels));
		tmp->labels->str = ft_strdup(line);
		tmp->labels->next = NULL;
		tmp->next = NULL;
		g_asm.c++;
	}
}