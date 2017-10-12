/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_basic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 17:31:08 by vpoltave          #+#    #+#             */
/*   Updated: 2017/09/10 17:31:09 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

void			just_read(t_skrr *skrr, char *argv, int argc, t_chmp *chmp)
{
	unsigned char 	magic[4];
	unsigned int 	m[4];

	(read(skrr->fd, magic, 4) < 0) ? chk_open(skrr, &argv, argc, 3) : 0;
	skrr->i = 0;
	skrr->shift = 24;
	while (skrr->i < 4)
	{
		m[skrr->i++] = get_magic_size(magic[skrr->i], skrr->shift);
		skrr->shift -= 8;
	}
	chmp->header.magic = m[0] | m[1] | m[2] | m[3];
	if (chmp->header.magic == COREWAR_EXEC_MAGIC)
		get_name_comments(skrr, argv, argc, chmp);
	else
		chk_open(skrr, &argv, argc, 2);
}

void			get_name_comments(t_skrr *skrr, char *argv, int argc, t_chmp *chmp)
{
	(lseek(skrr->fd, 4, SEEK_SET) < 0) ? exit(0) : 0;
	(read(skrr->fd, chmp->header.prog_name, PROG_NAME_LENGTH + 1) < 0) ? exit(0)
																	   : 0;
	(lseek(skrr->fd, COMMENT_POS, SEEK_SET) < 0) ? exit(0) : 0;
	(read(skrr->fd, chmp->header.comment, COMMENT_LENGTH + 1) < 0) ? exit(0)
																   : 0;
	(lseek(skrr->fd, SIZE_POS, SEEK_SET) < 0) ? exit(0) : 0;
	prog_size(skrr, argv, argc, chmp);
	(lseek(skrr->fd, COMMANDS_POS, SEEK_SET) < 0) ? exit(0) : 0;
}

void			chk_size(t_skrr *skrr, char *argv, unsigned char *line, t_chmp *chmp)
{
	skrr->i = 0;
	while (read(chmp->fd, &line, 1))
		skrr->i++;
	if (chmp->header.prog_size != skrr->i)
	{
		ft_printf("Error: File"RED" %s "RESET"has a code size that differ "
						  "from what its header says\n", argv);
		exit (0);
	}
	(lseek(chmp->fd, COMMANDS_POS, SEEK_SET) < 0) ? exit(0) : 0;
}

void			prog_size(t_skrr *skrr, char *argv, int argc, t_chmp *chmp)
{
	unsigned char 	size[4];
	unsigned int	s[4];

	(read(skrr->fd, size, 4) < 0) ? chk_open(skrr, &argv, argc, 3) : 0;
	skrr->i = 0;
	skrr->shift = 24;
	while (skrr->i < 4)
	{
		s[skrr->i++] = get_magic_size(size[skrr->i], skrr->shift);
		skrr->shift -= 8;
	}
	chmp->header.prog_size = s[0] | s[1] | s[2] | s[3];
	if (chmp->header.prog_size > CHAMP_MAX_SIZE)
	{
		ft_printf("Error: File" RED" %s "RESET "has too large a code "
						  "(%u bytes vs %u bytes)\n",
				  argv, chmp->header.prog_size, CHAMP_MAX_SIZE);
		exit(0);
	}
}

unsigned int	get_magic_size(unsigned int m, int shift)
{
	unsigned int magic;

	magic = 0;
	(shift == 24) ? (magic = m << shift) : 0;
	(shift == 16) ? (magic = m << shift & 0x00ffffff) : 0;
	(shift == 8) ? (magic = m << shift & 0x0000ffff) : 0;
	(shift == 0) ? (magic = m & 0x000000ff) : 0;
	return (magic);
}
