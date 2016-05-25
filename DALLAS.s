.name "DALLAS"
.comment "WTF"

first:
	sti		r1, %:l1, %1
	sti		r1, %:l1, %1
	sti		r1, %:l1, %1

l1:
	live %42
	;ld	%57672193, r2
	ld %57672192, r2
	ld %369324035, r3
	ld %1377136, r4
	;ld %33560067, r5
	ld %67113987,r5
	ld %1879375891, r6
	st r2, 256
	st r3, 255
	st r4, 254
	st r5, 253
	st r6, 252
	and r6, r6, r6
	fork %:l1
	zjmp	%192
