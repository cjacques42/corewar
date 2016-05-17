.name  "zork"

.comment "I'M ALIIIIVE"

l1:
lol:
l2: zjmp %:live %1
	sti r1,%:live,%1
	and	r1, %1, r1

live:live %11
		zjmp%:live
