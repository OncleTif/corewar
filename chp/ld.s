.name "LD"
.comment "I'M LD"

l2:		ld 1, r2
		st r2, 50
		st r2, r4
		ld %2, r3
		st r3, 100
		st r3, r5
		and r1, %0, r1

live:	live %1
		zjmp %:live
