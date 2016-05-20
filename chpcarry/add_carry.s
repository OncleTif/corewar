.name "add_chp"
.comment "ADD TEST MOTHER FUCKER"

adopi:	add	r1, r1, r2 ; ret != 0 jump FAILED
		;add		r2, r2, r2 ; ret == 0 jump OK
		zjmp %:l3
l3:		st r2, 200
