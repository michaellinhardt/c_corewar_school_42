.name "z
efi    befef
gfqvwefork"
.comment "oooooooooooooooo
ooooooooooooooooooo
ooooooooooooooooooooo
ppppppppppppppppppp
"
live %1
zjmp %34
sti r4 , %:live, r1
and :live, %0, r1 # COMMENT
live:
live:   live %1
zjmp %:live
and :live, %0, r1
live1:  live %36
zjmp %:live
and :live1, %0, r1
live:
label1:
and :live, %0, r1
and :live1, %0, r1
