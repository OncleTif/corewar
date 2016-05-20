.name "ld carry"
.comment "LD TEST MOTHER FUCKER"

audi: 	ld		%256, r2 ; retour != 0  jump KO
		;ld		%0, r2 ; retour == 0  jump OK
		zjmp %:l2
l2:		st r2, 200
