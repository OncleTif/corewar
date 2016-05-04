#include "../includes/corewar.h"

int		stock_dir(t_ir *pir, int i, int j)
{
	union u_4o tmp;
	int k;

	k = 0;
	while (k < 4)
	{
		tmp.c[k] = pir->irstr[j];
		k++;
		j++;
	}
	pir->args[i] = tmp.i;
	return (0x00);
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
