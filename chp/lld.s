.name "LLD"
.comment "I'M LLD"

l2:		lld	1365, r1 ; NO
		sti r1, %-250, %0
		lld	%-42, r1
		sti r1, %-250, %0
		lld	:live, r1 ; NO
		sti r1, %-250, %0
		lld	%:live, r1
		sti r1, %-250, %0
		lld		-256, r1
		sti r1, %-250, %0
		lld		-4, r1
		sti r1, %-250, %0
		lld      512, r1
		sti r1, %-250, %0
		lld      -4, r1
		sti r1, %-250, %0
		lld      4096, r1
		sti r1, %-250, %0
		lld      -4, r1
		sti r1, %-250, %0
		lld		4095, r1
		sti r1, %-250, %0
		lld		-4, r1
		sti r1, %-250, %0
		lld		-4, r1
		sti r1, %-250, %0
		lld		4094, r1
		sti r1, %-250, %0
		lld		1024, r1
		sti r1, %250, %0
		lld		901, r1
		sti r1, %250, %0
		lld		2049, r1
		sti r1, %250, %0
		lld		-4, r1
		sti r1, %250, %0
		lld		2047, r1
		sti r1, %250, %0
		lld		-4, r1
		sti r1, %250, %0
		lld		2046, r1
		sti r1, %250, %0
		lld		-4, r1
		sti r1, %250, %0
		lld		513, r1
		sti r1, %250, %0
		lld		-4, r1
		sti r1, %250, %0
		lld		512, r1
		sti r1, %250, %0
		lld		-0, r1
		sti r1, %250, %0
		lld		-4, r1
		sti r1, %250, %0
		lld		2048, r1
		sti r1, %250, %0
		lld		2048, r1
		sti r1, %250, %0
		and r1, %0, r1

live:	live %65534
		zjmp %:live
