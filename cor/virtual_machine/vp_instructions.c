/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_virtual_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:12:55 by vpoltave          #+#    #+#             */
/*   Updated: 2017/08/08 15:42:25 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtualm.h"

int 	entry_point(t_skrr *skrr)
{
	skrr->PC = &skrr->map[skrr->player_pos];
	while ((skrr->cycle_to_die > 0))
	{
		if (!which_instr(skrr))
			ft_printf("NULL address!");
		if ((skrr->nbr_live == NBR_LIVE) && !(skrr->nbr_live = 0))
			skrr->cycle_to_die -= CYCLE_DELTA;
		if (g_CTD == skrr->cycle_to_die)
		{
//			ft_printf("CYCLE_TO_DIE : %4d\t\tCTD: %4d\n", skrr->cycle_to_die, g_CTD);
			skrr->cycle_to_die -= CYCLE_DELTA;
			g_CTD = 0;
		}
		g_iter++;
		g_CTD++;
	}
//	ft_printf("CYCLE_TO_DIE : [%d]\tCTD : [%d]\tg_iter : [%d]\n",
//			  skrr->cycle_to_die, g_CTD, g_iter);
	return (1);
}

int		which_instr(t_skrr *skrr)
{
	skrr->op = -1;
	if (skrr->PC == NULL)
		return (0);
	while (++skrr->op < 15)
		if (*skrr->PC == op_tab[skrr->op].opcode)
		{
			((skrr->op) == 0) ? live_instr(skrr) : 0;
			((skrr->op) == 1) ? ld_instr(skrr) : 0;
			((skrr->op) == 2) ? st_instr(skrr) : 0;
			((skrr->op) == 3) ? add_instr(skrr) : 0;
			((skrr->op) == 4) ? sub_instr(skrr) : 0;
			((skrr->op) == 5) ? and_instr(skrr) : 0;
			((skrr->op) == 6) ? or_instr(skrr) : 0;
			((skrr->op) == 7) ? xor_instr(skrr) : 0;
			((skrr->op) == 8) ? zjmp_instr(skrr) : 0;
			((skrr->op) == 9) ? ldi_instr(skrr) : 0;
			((skrr->op) == 10) ? sti_instr(skrr) : 0;
			((skrr->op) == 11) ? fork_instr(skrr) : 0;
			((skrr->op) == 12) ? lld_instr(skrr) : 0;
			((skrr->op) == 13) ? lldi_instr(skrr) : 0;
			((skrr->op) == 14) ? lfork_instr(skrr) : 0;
			((skrr->op) == 15) ? aff_instr(skrr) : 0;
		}
	return (1);
}