/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kz_secondary_functions_1.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 15:09:01 by kzakharc          #+#    #+#             */
/*   Updated: 2017/10/10 15:09:03 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_labels	*leaf_list(t_file *t)
{
	t_labels	*tmp;

	g_asm.count = g_asm.l;
	while (t->next != NULL)
		t = t->next;
	tmp = t->labels;
	while (--g_asm.count > 0)
		tmp = tmp->next;
	g_asm.count = g_asm.l;
	return (tmp);
}

