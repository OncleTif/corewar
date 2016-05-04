#include "../includes/corewar.h"

int		stock_dir(t_process *proc, t_vm *vm, int i)
{
	union u_4o tmp4;
	int k;

	tmp4.i = 0;
	k = 3;
	if (proc->ir.index)
		k = 1;
	while (k >= 0)
	{
		tmp4.c[k] = proc->ir.irstr[proc->pcdelta];
		k--;
		proc->pcdelta += 1;
	}
	
	return (0);
}

int		stock_reg(t_process *proc, int i)
{
	int		reg;

	reg = proc->ir.irstr[proc->pcdelta] - 1;
	proc->pcdelta += 1;
	if (reg < 0 || reg > 15)
	{
		proc->ir_error = 1;
		return (0);
	}
	proc->ir.args[i] = proc->reg[reg];
	return (1);
}

int		stock_ind(t_process *proc, t_vm *vm, int i, int j)
{
	int			k;
	union u_2o	tmp;
	union u_4o	tmp1;

	k = 0;
	while (k < 2)
	{
		tmp.c[k] = proc->ir.irstr[j];
		k += 0x01;
		j += 0x01;
	}
	k = 0;
	while (k < 4)
	{
		tmp1.c[k] = vm->bcore.core[(r4oi(proc->pc) + r4oi(tmp.i) + k) % MEM_SIZE];
		k++;
	}
	proc->ir.args[i] = tmp.i;
	return (0x00);
}
