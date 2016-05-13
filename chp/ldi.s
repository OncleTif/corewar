.name "LDI"
.comment "I'M LDI"


l2:		ldi	1401, %0, r3	; fffe = 65534 + 1365 = 66899 % 4096 = 1363 = a8a90ee4 = -2
		sti r3, %-200, %0    ; 1396 e4057400
		ldi	-20, %0, r1
		sti r1, %-200, %0
		ldi	-10, %0, r1
		sti r1, %-200, %0
		ldi 0, %0, r1  	;ok
		sti r1, %-200, %0
		ldi	2, %1, r1 ;ok
		sti r1, %-200, %0
		ldi	:live, r1, r4
		sti r1, %-200, %0
		ldi	%:live, %1, r5
		sti r5, %-200, %0
		ldi	%2, %3, r6;
		sti r6, %-200, %0
		and r1, %0, r1


		ldi	1401, %0, r3   ; fffe = 65534 + 1365 = 66899 % 4096 = 1363 = a8a90ee4
				sti r3, %-200, %0    ; 1396 e4057400
				ldi	%2, %3, r2;3020ed4
				sti r2, %200, %0
				ldi	:live, r1, r4
				sti r4, %200, %0
				ldi	%:live, %1, r5
				sti r5, %200, %0
				and r1, %0, r1

		ldi	-511, %3000, r3   ; fffe = 65534 + 1365 = 66899 % 4096 = 1363 = a8a90ee4 = -2
		sti r3, %200, %0    ; 1396 e4057400
		ldi	2, %2, r2;
		sti r2, %200, %0; ecrit 0
		ldi	:live, r7, r4
		sti r4, %200, %0 ; ecrit 0
		ldi	%:live, %1, r5 ; 36 1 r5
		sti r5, %200, %0
		ldi	%2, %3, r6;
		sti r6, %200, %0
		and r1, %0, r1

		live:	live %13421772
				zjmp %:live
