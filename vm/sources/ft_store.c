/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 16:19:10 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/12 20:42:13 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_st(t_vm *vm, t_process *proc)
{
	if (proc->ir.code_args[1] == T_IND)
		put_mem(vm, proc, proc->ir.args[1],
				proc->reg[proc->ir.args[0]]);
	else
		proc->reg[proc->ir.args[1]] = proc->reg[proc->ir.args[0]];
	proc->carry = !proc->reg[proc->ir.args[0]];
}

void	ft_sti(t_vm *vm, t_process *proc)
{
	//	int	val;
	int	off;
	int	mod;

	if (proc->num_plr == -2)
		printf ("\n_____\nARGS %d\nMOD %d\n ",proc->ir.args[1],proc->ir.args[2] );
	if (proc->ir.code_args[2] == T_REG)
		mod = proc->reg[proc->ir.args[2]];
	else
		mod = proc->ir.args[2];
	if (proc->ir.code_args[1] == T_IND)
		off = get_mem_idx(vm, proc->pc, proc->ir.args[1]);// + mod);
	else if (proc->ir.code_args[1] == T_REG)
		off = proc->reg[proc->ir.args[1]];
	else
		off = proc->ir.args[1];
	if (proc->num_plr == -2)
	{
		printf ("OFF %d\n ",off);
	printf("(OFF + MOD) IDXMOD %d\n",((off  + mod) % IDX_MOD));
}
	put_mem(vm, proc, off + mod,
			proc->reg[proc->ir.args[0]]);
	proc->carry = !proc->reg[proc->ir.args[0]];
}
/*
void	ft_sti(t_vm *vm, t_process *proc)
{
	//	int	val;
	short int	off;
	short int	mod;
//	short int	sum;

	ft_putendl("pc sti:");
	ft_putnbrendl(proc->pc);
	if (proc->ir.code_args[2] == T_REG)
		mod = proc->reg[proc->ir.args[2]];
	else
		mod = proc->ir.args[2];
	if (proc->ir.code_args[1] == T_IND)
		off = get_mem_idx(vm, proc->pc, proc->ir.args[1]);
	else if (proc->ir.code_args[1] == T_REG)
		off = proc->reg[proc->ir.args[1]];
	else
		off = proc->ir.args[1];
//	while (mod < 0 && proc->ir.code_args[1] == T_IND)
//		mod = mod + 1024;
//	sum = mod + off;
//	if (mod >= 512)
//		sum = sum -512;
//	if (off >= 512)
//		sum = sum -512;

//	if ((mod < 0 && off >= 0) || (mod >= 0 && off < 0 ))
//		sum = sum - 512; // sum
	put_mem(vm, proc, off + mod,
			proc->reg[proc->ir.args[0]]);
	proc->carry = !proc->reg[proc->ir.args[0]];
	// ft_putstr("                            ");
	// ft_putnbr(proc->ir.args[1]);
	// ft_putstr(" & ");
	// ft_putnbr(off % 1024 - 512);
	// ft_putstr(" & ");
	// ft_putnbr(mod % 1024 - 512);
	// ft_putstr(" & ");
	// ft_putnbr((off % 1024 - 512) + (mod % 1024 - 512));
	// ft_putstr(" & ");
	// ft_putnbrendl(sum % 512);
}
*/
//-255
