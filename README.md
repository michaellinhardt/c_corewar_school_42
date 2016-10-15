# [ COREWAR PROJECT ]
- Langage: C
- Date: April 2016
- Team: abary jgeslin pba mlinhard

![alt tag](*img link*)

#THE GAME
The Corewar is an arena (a virtual machine ) where many processes called 
champions (a maximum of 4 champions) fight. A champion is a list of instructions
written in a look-alike disassembly language. The goal of each champion is to 
be the last process alive, i.e the last one to write on the memory. 
when all processes are dead the game ends.

USAGE
./server <port>
./client <address> <port>

1- Send a champion
champion <path to a champion>

OCP (Octet de Codage des Parametres)
L'octet de codage des parametres permet de savoir les differents types de 
parametres de l'instruction.
- Un Registre = TREG => 1 (code sur 2 bits)
- Un Indirect = une valeur ou un label precede de ':' => 4 (code sur 2 bits)
- Un Direct = '%' + :label ou valeur => 2 (code sur 4 bits)

ANALYSE DE L'HEXA
Instruction (representee par un numero) + OCP + valeurs

PRECOMPILE HEADER
Le header de precompilation est la representation interne faite par le 
compilateur apres parsing et analyse semantique. Elle composee de :
	- un magic number => permet de connaitre le type de fichier. Pour les
		executables le magic en hexa == 0xea83f3.
	- le nom du programme dans un tableau statique de chars.
	- la taille du programme dans un unsigned int.
	- un commentaire dans un tableau statique de chars.
Dans un hexdump le header est ecrite avant le programme a proprement parler.
