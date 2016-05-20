.name "ld carry"
.comment "LD TEST MOTHER FUCKER"

audi: 	;lld		%256, r2 ; retour != 0  jump KO
		lld		%0, r2 ; retour == 0  jump OK
		zjmp %:l2
l2:		st r2, 200
