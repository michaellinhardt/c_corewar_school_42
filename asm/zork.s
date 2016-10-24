.name "z
	 efi	befef
	 qwehfqvefqwe97fgqe f
	 quiwegfyuqwevfefqwef
	 qwfqvwefyygqwfv qwpeygfqvwefork"
.comment "I'M ALIIIIVE"
l2:		sti r1, %:live, %1
		and r1, %0, r1

live:	live %1
		zjmp :live
