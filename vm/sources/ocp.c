#include "../includes/corewar.h"

int		check_code(unsigned char ocp, int decal)
{
	if (((ocp >> decal) & 3) == 0)
	{
		return (0);
	}
	return(1);
}

int 	stock_code_args(t_ir *pir, unsigned char ocp, int u, int i)
{
	pir->code_args[i] = ((ocp >> u) & 3);
	return (0);
}

int 	j_init(int i, t_ir *pir, int *j)
{
	int a;

	a = 0;
	if (pir->args[i] == 0x01)
	{
		a = 1;
	}
	if (pir->args[i] == 0x02)
	{
		a = 4;
	}
	if (pir->args[i] == 0x03)
	{
		a = 2;
	}
	*j += a;
	return (0);
}

int 	get_args(t_process *proc, t_vm *vm)
{
	int i;
	int j;

	i = 0;
	j = 2;
	while (i < 3)
	{
		//j_init(i, ir, &j);
		if (proc->ir.code_args[i] == 0x02)
		{
			stock_dir(&proc->ir, i, j);
			j += 4;
		}
		else if (proc->ir.code_args[i] == 0x03)
		{
			stock_ind(proc, vm, i, j);
			j += 2;
		}
		// else if (pir->code_args[i] == 0x04)
		// {
		// 	stock_reg();
		// }
		i++;
	}
	return (0);
}

int		check_ocp(int *tab, unsigned char *ir, t_ir *pir)
{
	int		i;
	int		u;

	i = 0;
	while (tab[i] != 0 && i < 3)
	{
		u = 6;
		if (!check_code(ir[1], u))
		{
			return (0);
		}
		else
		{
			stock_code_args(pir, ir[1], u, i);
		}
		i++;
		u -= 2;
	}
	return (1);
}
