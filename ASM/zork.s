.name  "zork"

.comment "I'M ALIIIIVE"

l1:
lol:
l2: zjmp %:live
	sti r1,%:live,%1
	and	r1, %1, r1

live:live %112
		zjmp%:live
