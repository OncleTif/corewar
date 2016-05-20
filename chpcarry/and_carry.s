
.name "add_chp"
.comment "ADD TEST MOTHER FUCKER"


	and		%0,	r1, r5 ; resultqt == 0  jump OK
	;and		r1,	r1, r5 ; resultqt != 0  jump FAILED
	zjmp %:l3
	l3:		st r5, 200
