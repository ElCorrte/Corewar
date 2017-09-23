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
# include "op.h"

typedef struct s_file	t_file;
typedef struct s_labels	t_labels;

typedef struct         s_op
{
	char             *name;
	short             numb_of_arg;
	t_arg_type         arg[3];
	short            opcode;
	short            cycles;
	short             codage;
	short            dir_size;
}                    t_op;

struct 				s_labels
{
	char 			*str;
	t_labels		*next;
};

struct 				s_file
{
	char 			*file_name;
	char 			*name;
	char 			*comm;
	t_labels		*labels;
	t_file			*next;
};

typedef struct		s_asm
{
	int 			a;
	int 			c;
	int 			fd;
	int 			f_name;
	int 			f_comment;
	int 			line;
	int 			column;
}					t_asm;

t_asm				g_asm;
t_file				*g_file;

void				print_usage(int i, char *str);
void				lets_get_null(void);
void				lets_get_null_for_file(void);
int 				g_validation(char *str);
t_file				*record_file(char *str, int y);
void				record_labels(char *line);
void				add_file(t_file *file, char *str);
void				add_label(char *line, t_labels *labels);
int 				looking_for_errors(void);
int 				checkout_name_comm(t_file *tmp, int a);
int 				check_comment(t_file *tmp, int i, int a);
int 				check_no_repit(void);
/*void				print_with_a(char *str);
void				creat_file(char *str);*/
/*void				print_all_this_shit();*/

#endif
