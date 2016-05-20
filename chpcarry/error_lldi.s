.name "ERROR jump"
.comment "I'M ERROR JUMP"



lldi r1, %100, r2 ; retour  == 0 jump ok
;lldi r2, %0, r2 ; retour  != 0 jump KO
l2:	zjmp %3
	zjmp %3
	zjmp %3
	st r2, 200
