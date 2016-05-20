.name "ld carry"
.comment "LD TEST MOTHER FUCKER"

l2:		sti r1, %:live, %1
 		;ld		%256, r2 ; retour != 0  jump KO
		ld		%0, r2 ; retour == 0  jump OK
		fork %:z
live:	live %1
		fork %:z
z:		zjmp %:z
