.name "thunder"
.comment "you've been thunderstruck..."

main:
	sti			r1, %:start, %1
	sti			r1, %:live, %1
	ld			%0, r16
	fork		%:start

live:
	live		%42
	ld			%0, r2
	fork		%:front

back:
	live		%42

start:
	live		%42

front:
	live		%42
