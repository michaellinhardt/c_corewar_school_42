.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, %:live, %1
		lld 2048, r2
		st r2, 0
		aff r1
		af 431
		#and r1, %0, r1

live:	live %1
		zjmp %:live
