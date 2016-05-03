.name "zork"
.comment "I'M ALIIIIVE"

entry:
	sti			r1, %:zork, %1
	ld			%0, r16

zork:
	live		%42
	st			r1, 100
	zjmp		%:zork
