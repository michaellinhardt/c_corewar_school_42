.name "z
	 efi	befef
	 qwehfqvefqwe97fgqe f
	 quiwegfyuqwevfefqwef
	 qwfqvwefyygqwfv qwpeygfqvwefork"
.comment "I'M ALIIIIVE"
live %1
zjmp %34
sti r4 , %:live, r2
live : a
and :live, %0, r1 # COMMENT
live:	live %1
		zjmp %:live
		and :live, %0, r1
live1:	live %36
		zjmp %:live
		and :live1, %0, r1
label1:
		and :live1, %0, r1
		and :live1, %0, r1
