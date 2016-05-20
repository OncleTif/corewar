.name "add_chp"
.comment "ADD TEST MOTHER FUCKER"

adopi:	sub	r1, r2, r2 ; ret != 0 jump FAILED
		;sub		r2, r2, r2 ; ret == 0 jump OK
		zjmp %:l3
l3:		st r2, 200
