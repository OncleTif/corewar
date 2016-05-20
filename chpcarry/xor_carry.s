
.name "add_chp"
.comment "ADD TEST MOTHER FUCKER"


	xor		%0,	r1, r5 ; resultqt != 0  jump FAILED
	;xor		r2,	r2, r5 ; resultqt == 0  jump OK
	zjmp %:l3
	l3:		st r5, 200
