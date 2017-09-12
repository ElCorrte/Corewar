/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_for_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 14:04:22 by kzakharc          #+#    #+#             */
/*   Updated: 2017/08/15 14:04:23 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	print_usage(int i, char *str)
{
	(i == 0) ? (ft_printf("Usage: ./asm [-a] <sourcefile.s>\n\t-a : Instead of "
			"creating a .cor file, outputs a stripped and annotated version "
								  "of the code to the standard output\n")) : 0;
	(i == 0) ? (ft_printf("Writing output program to %s\n", str)) : 0;
}