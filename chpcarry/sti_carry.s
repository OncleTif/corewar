
.name "add_chp"
.comment "ADD TEST MOTHER FUCKER"

	;sti r2, 0, %-1 ; resultqt == 0  jump FAILED
	sti r1, 0, %-1 ; resultqt == 0  jump FAILED
	zjmp %:l3
	l3:		st r5, 200
