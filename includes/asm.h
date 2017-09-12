/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 13:14:08 by kzakharc          #+#    #+#             */
/*   Updated: 2017/08/15 13:14:11 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
#define ASM_H

# include "../Lib/src/libft/libft.h"
# include "../Lib/src/ft_printf/ft_printf.h"
# include "../Lib/src/get_next_line/get_next_line.h"

typedef struct		s_asm
{
	int 			a;
}					t_asm;

t_asm				g_asm;

void				print_usage(int i, char *str);
void				check_and_read(char *str, int i);
void				lets_get_null(void);
int 				g_validation(char *str);
void				print_with_a(char *str);
void				creat_file(char *str);

#endif
