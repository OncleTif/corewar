.name "ERROR LDI"
.comment "I'M ERROR LDI"


l2:		;ldi	100, %0, r2 ;retour != 0   jump ko
		ldi	100, %100, r2 ;retour == 0 jump ko
		zjmp %:l3
l3:		sti r2, %-200, %0
