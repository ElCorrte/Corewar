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
}

void	lets_get_null_for_file(void)
{
	g_asm.c = 0;
	g_asm.f_comment = 0;
	g_asm.f_name = 0;
	g_asm.line = 1;
	g_asm.l = 1;
	g_asm.q = 0;
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

t_labels	*skip_blank_lines(t_file *tmp)
{
	while ((ft_isspace(*tmp->labels->str) || (*tmp->labels->str == '\0') ||
			(*tmp->labels->str == COMMENT_CHAR) || *tmp->labels->str == ';') &&
			(tmp->labels->next != NULL))
	{
		while (ft_isspace(*tmp->labels->str))
			tmp->labels->str++;
		if ((*tmp->labels->str == '\0' || *tmp->labels->str == COMMENT_CHAR ||
				*tmp->labels->str == ';') && tmp->labels->next != NULL)
		{
			tmp->labels = tmp->labels->next;
			g_asm.l++;
		}
	}
	if (tmp->labels->next == NULL)
	{
		while (ft_isspace(*tmp->labels->str))
			tmp->labels->str++;
		if (*tmp->labels->str == COMMENT_CHAR || *tmp->labels->str == ';')
		{
			while (*tmp->labels->str)
				tmp->labels->str++;
		}
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
