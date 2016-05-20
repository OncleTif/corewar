.name "add_chp"
.comment "ADD TEST MOTHER FUCKER"

	ld %62 , r2
		aff		r2 ; ret == 0 jump OK
		zjmp %:l3
l3:		st r2, 200
