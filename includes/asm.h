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
	int 			p;
	int 			c;
	int 			fd;
	int 			f_name;
	int 			f_comment;
	int 			line;
	int 			l;
	int				q;
}					t_asm;

extern t_asm		g_asm;
extern t_file		*g_file;
t_op				g_tab[17];

int					print_usage(int i, char *s);
int					print_usage_1(int i, char *s, int param, char *p);
void				lets_get_null(void);
void				lets_get_null_for_file(void);
int 				g_validation(char *str);
t_file				*record_file(char *str, int y);
void				record_labels(char *line);
void				add_file(t_file *file, char *str);
void				add_label(char *line, t_labels *labels);
int 				looking_for_errors(t_file *t);
int 				checkout_name_comm(t_labels *tmp, int a);
int 				check_comment(t_labels *tmp, int i, int a);
int 				check_no_repit(t_labels *tmp);
t_labels			*skip_blank_lines(t_labels *tmp, int f);
int 				finaly_check_name_comm(t_labels *tmp, int i, int n, int a);
int 				checkout_body(t_labels *tmp, int a, int i);
int 				check_param(t_labels *tmp, int i);
int 				find_name(t_labels *tmp, int i);
int 				find_char(char c, int i);
int 				instruction_with_one_param(t_labels *tmp, int i);
int 				check_direct(t_labels *tmp, int i, int q);
int 				check_separator(t_labels *tmp, int q, int i, char *s);
int 				find_label(t_labels *tmp, t_file *t, int i);
/*void				print_with_a(char *str);
void				creat_file(char *str);*/

#endif
