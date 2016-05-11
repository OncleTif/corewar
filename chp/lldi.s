.name "LLDI"
.comment "I'M LLDI"


l2:		lldi	1401, %1, r3   ; fffe = 65534 + 1365 = 66899 % 4096 = 1363 = a8a90ee4 = -2
		sti r3, %100, %0    ; 1396 e4057400
		lldi	2, %2, r2;
		sti r2, %150, %0; ecrit 0
		lldi	:live, r7, r4
		sti r4, %200, %0 ; ecrit 0
		lldi	%:live, %1, r5
		sti r5, %250, %0
		lldi	%2, %3, r6;
		sti r6, %300, %0
		and r1, %0, r1

live:	live %13421772
		zjmp %:live





		;live %196868
