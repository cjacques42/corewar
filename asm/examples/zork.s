.name"zork" #lol
.comment	"I'M ALIIIIIIVE" ;lol
;
ntry:
nitry:		#lol
entry:		sti r1, %:zork, %1
			ld %0, r16

zork2:
zork:		live %2
			st r1, 100
			zjmp %:ntry
			live %41
