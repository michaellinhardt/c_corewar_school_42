.name		"nestbot"
.comment	"pick a cookie !!"

prep_live:
	sti		r1, %:live1, %1
	sti		r1, %:last_live, %1

live1:
	live	%255

zero:
	ld		%0, r7

erase_bot:
	sti		r1, %:beegees, %1

last_live:
	live	%255
