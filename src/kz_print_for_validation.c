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
	(i == 1) ? (ft_printf("Writing output program to %s\n", str)) : 0;
	(i == 2) ? (ft_printf("Can't read source file %s\n", str)) : 0;
	(i == 3) ? (ft_printf(RED "ERROR, line [%03d]\n" RESET, g_asm.line)) : 0;
	(i == 4) ?
	(ft_printf(BLU "Lexical error at line [%03d]\n" RESET, g_asm.line)) : 0;
	(i == 5) ? (ft_printf(RED "ERROR, no command '.name'\n" RESET)) : 0;
	(i == 8) ? (ft_printf(RED "ERROR, no command '.comment'\n" RESET)) : 0;
	(i == 6) ? (ft_printf(RED "ERROR, too much '.name'\n" RESET)) : 0;
	(i == 7) ? (ft_printf(RED "ERROR, too much '.comment'\n" RESET)) : 0;
}