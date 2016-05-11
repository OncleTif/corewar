.name "LLD"
.comment "I'M LLD"

l2:		lld	1365, r3
		;sti r1, %:live, %1
		lld	%-42, r2
		sti r2, %100, %0
		lld	:live, r4
		lld	%:live, r5
		and r1, %0, r1

live:	live %65534
		zjmp %:live
