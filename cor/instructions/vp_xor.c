/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 18:41:18 by yzakharc          #+#    #+#             */
/*   Updated: 2017/09/02 18:41:19 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

int 	xor_instr(t_skrr *skrr, t_proc *process)
{
	unsigned char	*q;
	int 			address;
	int 			reg;

	if ((process->current_cycles != 0) &&
		(process->current_cycles) % (g_tab[skrr->op].cycles) == 0)
	{
		if (!(q = malloc(sizeof(unsigned char) * g_tab[skrr->op].numb_of_arg)))
			exit(0);
		if (!(same_start(q, skrr, process, g_tab[skrr->op].numb_of_arg)))
			return (0);
		address = determination_of_action(q, skrr, 0, 5, process);
		process->tmp_pc += 1;
		if (!(reg = reg_param(skrr, process, 2)) && (g_err) && !(g_err = 0))
			return (0);
		process->registry[reg] = (unsigned int) address;
		address == 0 ? process->carry = 1 : 0;
		process->pc += skrr->chmp->offset + 2;
		ft_printf("xor\tcurrent_cycles: %d\npc: %d\n", process->current_cycles,
				  process->pc);
	}
	return (1);
}