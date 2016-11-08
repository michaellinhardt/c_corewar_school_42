.name		"nestbot"
.comment	"pick a cookie !!"

# ecris R1 dans param de live1
prep_live:
	sti		r1, %:live1, %1

# ecrase R1 avec les param de live1
erase_reg:
	ldi		%:live1, %1, r1

# ecris R1 dans param de live2
live_countdown:
	sti		r1, %:live2, %1

# remplace le deuxieme LD de live_code par R1
prep_live_code:
	sti		r1, %:live_code, %9

# embarque le code dun live pour mon champion
live_code:
	ld		%1, r8
	ld		%0, r9

# execute un live
live1:
	live	%255

# ecris un live a la place du prep_live pour proteger la reecriture
# du live
erase_prep:
	sti		r8, %:prep_live, %-1
	sti		r9, %:prep_live, %3

# boucle de reecriture
countdown_init:
	ld		%1, r7

#While (r7 < 255)
countdown_inc:
	add		r7, r8, r7

countdown_break:
	xor		r7, %255, r10

live2:
	live	%255

countdown_end:
	zjmp	%:countdown_over

countdown_restart:
	fork	%:prep_live
	ld		%0, r10
	zjmp	%:countdown_inc

countdown_over:
	zjmp	%:prep_live
