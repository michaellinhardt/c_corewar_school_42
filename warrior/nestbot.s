#by zaz, still not as good as rainbowdash though
#2013

.name		"nestbot"
.comment	"pick a cookie !"

live_code:
	ld		%1, r8

write_live:
#write r6 to live_1
	sti		r6, %:live_1, %1

live_1:
	live	%255
