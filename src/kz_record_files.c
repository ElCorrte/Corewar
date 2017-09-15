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

t_labels	*record_labels(char *line, char *str)
{
	t_labels	*tmp;

	tmp = g_file->labels;
	if (g_asm.c == 0)
	{
		tmp = (t_labels *)malloc(sizeof(t_labels));
		tmp->str = ft_strdup(line);
		tmp->next = NULL;
		g_asm.c++;
	}
	if (g_asm.c != 0)
		add_label(line, tmp);
	return (tmp);
}

t_file		*record_file(char *line, char *str, int y)
{
	t_file		*tmp;

	tmp = g_file;
	if (y == 1)
	{
		tmp = (t_file *)malloc(sizeof(t_file));
		tmp->file_name = ft_strdup(str);
		tmp->name = NULL;
		tmp->comment = NULL;
		tmp->labels = NULL;
		tmp->next = NULL;
		g_asm.c++;
	}
	if (y != 1)
		add_file(line, tmp, str);
	return (tmp);
}

void		add_label(char *line, t_labels *labels)
{
	t_labels *tmp;

	tmp = labels;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = (t_labels *)malloc(sizeof(t_labels));
	tmp->next->str = ft_strdup(line);
	tmp->next->next = NULL;
}

void		add_file(char *line, t_file *file, char *str)
{
	t_file *tmp;

	tmp = file;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = (t_file *)malloc(sizeof(t_file));
	tmp->next->file_name = ft_strdup(str);
	tmp->next->name = NULL;
	tmp->next->comment = NULL;
	tmp->next->labels = NULL;
	tmp->next->next = NULL;
}