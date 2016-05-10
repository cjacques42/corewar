.name"zork" #lol
.comment	"I'M ALIIIIIIVE" ;lol
;
ntry:
2nitry:		#lol
entry:		st r1, :ntry			  
			sti		   r1, %:zork			,     %80000#ll
#entry:		ld		%4294967295, r0
			ld %0, r16
#l
zork2:
zork:		live %2
			zjmp %:ntry
			live %41
			aff r1
