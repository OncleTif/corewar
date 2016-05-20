.name "ERROR LDI"
.comment "I'M ERROR LDI"


l2:		st r1, 100 ; ret != 0 jump KO
		;st r2, 100; ret == 0 jump KO
		zjmp %:l3
l3:		sti r2, %-200, %0
