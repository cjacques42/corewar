.name"zork" #lol
.comment	"I'M ALIIIIIIVE" ;lol
;
entry:		sti r1, %:zork, %1
			ld %0, r16

zork:		live %2
			st r1, 100
			zjmp %:zork
			live %41
