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

int		print_usage(int i, char *s)
{
	(i == 0) ? (ft_printf("Usage: ./asm [-a] <sourcefile.s>\n\t-a : Instead of "
			"creating a .cor file, outputs a stripped and annotated version "
								  "of the code to the standard output\n")) : 0;
	(i == 1) ? (ft_printf("Writing output program to %s\n", s)) : 0;
	(i == 2) ? (ft_printf("Can't read source file %s\n", s)) : 0;
	(i == 3) ? (ft_printf(RED "ERROR, line [%03d]\n" RESET, g_asm.l)) : 0;
	(i == 4) ?
	(ft_printf(YEL "Lexical error at line [%03d]\n" RESET, g_asm.l)) : 0;
	(i == 5) ? (ft_printf(RED "ERROR, too much commands '%s'\n" RESET, s)) : 0;
	(i == 6) ? (ft_printf(RED "ERROR, too much commands '%s'\n" RESET, s)) : 0;
	(i == 7) ? (ft_printf(MAG "Syntax error in the "
								  "string \"%s\"\n" RESET, s)) : 0;
	(i == 8) ? (ft_printf(RED "Invalid instruction at line "
								  "[%03d]\n" RESET, g_asm.l)) : 0;
	(i == 9) ?
	(ft_printf(YEL "Lexical error at line [%03d]\n" RESET, g_asm.l)) : 0;
	(i == 10) ?
	(ft_printf(MAG "Syntax error. No token ':' after label, "
					   "line [%03d]\n" RESET, g_asm.l)) : 0;
	(i == 11) ?
	(ft_printf(MAG "Syntax error at line [%03d]\n" RESET, g_asm.l)) : 0;
	return (0);
}