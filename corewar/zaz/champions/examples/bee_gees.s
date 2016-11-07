.name "stayin' alive"
.comment "Ha, Ha, Ha, stayiiiiin' aliiiiiiiiiive"

sti	r1, %:live, %1			;change live by the right value
sti	r1, %:live2, %1			;change live by the right value
ld	%1, r3			;carry = 0
ld	%33, r6			;carry = 0
#While (r2 < 10)
forks:
add	r2, r3, r2		;increment r2 (carry = 0 car addition avec r3 qui vaut tjrs == 1)
xor	r2, %15, r4		;if (r4 == 10) {carry = 0} (r2 ^ 15 vaudra 0 si r2 == 15)
live2:
	live 	%4
zjmp	%:endwhile		;if (carry) (au premier passage, carry == 0)
fork	%:forks
ld	%0, r4			;carry = 1 (car le résultat vaut 0 donc le carry passe a 1)
zjmp	%:forks		; ici on jump TOUJOURS car le carry vaut 1 du tour davant
#EndWhile
endwhile:
ld	%0, r4			;carry = 1 -> on arrive ici quand on a fais 10 tour de boucle

live:
live %4				; apres les 10 tour de boucle on live en boucle comme un idiot
zjmp %:live
