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

int	check_code2(unsigned char *ir, int j)
{
	int	i;

	i = ocp >> 6 - (2 * j);
	if (i == 3)
		i = 4;
	if (i & g_op_tab[ir[0] - 1].att[j])
	{
		return (i);
	}
	return(0);
}


int		check_ocp(int *tab, unsigned char *ir, t_ir *pir)
{
	int		i;
	int		u;
	int	j;

	j = 0;
	ret = 1;
	while (j < 4 && ret)
	{
		if (j < g_op_tab[ir[0] - 1].att_num)
		{
			if ((ret = check_code2(ir, j)))
				pir->code_args[j] = ret;  // STOCK T_REG T_IND TDIR
		}
		else
			ret = !(ir[1] >> (6 - (2 * j)) & 3)
		j++;
	}
	return (ret);
}
