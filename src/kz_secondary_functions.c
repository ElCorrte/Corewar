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
	g_asm.l = 1;
	g_asm.q = 0;
	g_asm.p = 0;
}

void	lets_get_null_for_file(void)
{
	g_asm.c = 0;
	g_asm.f_comment = 0;
	g_asm.f_name = 0;
	g_asm.line = 1;
	g_asm.l = 1;
	g_asm.q = 0;
	g_asm.p = 0;
}

int 	find_char(char c, int i)
{
	while (LABEL_CHARS[i])
	{
		if (LABEL_CHARS[i] == c)
			return (1);
		i++;
	}
	return (0);
}

t_labels	*skip_blank_lines(t_labels *tmp)
{
	while ((ft_isspace(*tmp->str) || (*tmp->str == '\0') ||
			(*tmp->str == COMMENT_CHAR) || *tmp->str == ';') &&
			(tmp->next != NULL))
	{
		while (ft_isspace(*tmp->str))
			tmp->str++;
		if ((*tmp->str == '\0' || *tmp->str == COMMENT_CHAR ||
				*tmp->str == ';') && tmp->next != NULL)
		{
			tmp = tmp->next;
			g_asm.l++;
		}
	}
	if (tmp->next == NULL)
	{
		while (ft_isspace(*tmp->str))
			tmp->str++;
		if (*tmp->str == COMMENT_CHAR || *tmp->str == ';')
		{
			while (*tmp->str)
				tmp->str++;
		}
	}
	return (tmp);
}

int 		finaly_check_name_comm(t_labels *tmp, int i, int n, int a)
{
	t_file	*q;

	q = g_file;
	while (q->next != NULL)
		q = q->next;
	if (tmp->str[i] == '"' && tmp->str[n] == '\0')
	{
		if (a == 1)
			q->name = ft_strnew((size_t)i);
		else
			q->comm = ft_strnew((size_t)i);
		if (a == 1)
			q->name = ft_strncpy(q->name, tmp->str, (size_t)i);
		else
			q->comm = ft_strncpy(q->comm, tmp->str, (size_t)i);
		return (1);
	}
	return (0);
}
