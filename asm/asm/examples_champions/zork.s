.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, %:live, %1
		and r1, %0, r1

live:	live %1
		zjmp %:live




0b 68 		01 000f 0001
06 64		01 00000000 01
01			00000001 
09			ff fb
