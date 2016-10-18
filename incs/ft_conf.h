#ifndef FT_CONF_H
# define FT_CONF_H

/*
**	Header pour les parametre réglable
*/
# define GRAPHIC_MODE 1
# define CONSOLE_LOG 0
# define WIN_TITLE "Corewar"
# define WIN_X 1920
# define WIN_Y 1200

/*
**  COULEUR DE LA VM
*/
# define ARENE_CODE_COLOR_WHITE 0xa6a6a6
# define ARENE_CODE_COLOR_P1 0x1eff00
# define ARENE_CODE_COLOR_P2 0xf4532a
# define ARENE_CODE_COLOR_P3 0x1fbdff
# define ARENE_CODE_COLOR_P4 0xeaff00
# define RED "\033[0;31m"
# define WHITE "\033[1;37m"
# define BLUE "\033[0;34m"
# define GREEN "\033[0;32m"
# define CYAN "\033[0;36m"
# define YELLOW "\033[0;33m"
# define PURPLE "\033[0;35m"
# define NEUTRE "\033[0;m"

/*
**  DONNEE DE LA VM
*/
# define SIZE_CHAR_ARENE (MEM_SIZE * 2)
# define CHAMP_NAME_SIZE 2048
# define CYCLE_PER_LOOP 50
# define CPERLOOP_INC 10
# define CPERLOOP_MAX 200
# define ARENE_CODE_COLOR 0xCCCCCC

/*
** GESTION DU TEMPS D'ARRET DE LA BOUCLE SI RIEN N'EST A AFFICHER
** Cela évite de spam le processeur du PC pour RIEN
*/
# define USLEEP_TIME 20000
# define USLEEP_BOOL 1

/*
** CONF PROPRE A MLX
** SCENE_MAX: taille statiquement alloué pour stoquer les scene dans un tableau
** pareil pour SCENE_IMG_MAX concernant les images de chaque scenes
*/
# define SCENE_MAX 20
# define SCENE_IMG_MAX 50
# define SCENE_START VM_INIT
# define EFFECTS_MAX_SLOT 20

/*
** DOSSIER DEPUIS LEQUEL SONT AUTOMATIQUEMENT IMPORTé LES GIFS
** ET CHEMINS DES FICHIERS ASCII
*/
# define GIF_DIR "./gif/"
# define ASC_LOGO "./ascii/logo"
# define ASC_INIT "./ascii/init"
# define ASC_LOG "./ascii/log"
# define ASC_FREEDATA "./ascii/freedata"
# define ASC_EXIT_0 "./ascii/exit0"
# define ASC_EXIT_1 "./ascii/exit1"

/*
** CHAINE DE CARACTER POUR LES BOX DU TERMINAL
*/
# define TERMINAL_COLOR "\e[93m"
# define LINE_GREY "\e[93m║\e[90m"
# define LINE_GREEN "\e[93m║\e[92m"
# define LINE_BLUE "\e[93m║\e[36m"
# define LINE_GREEN2 "\e[93m║\e[32m"
# define LINE_MAG "\e[93m║\e[35m"
# define LINE_YEL "\e[93m║"

/*
** AFFICHAGE OU NON DES LOG,
** LOG_DISPLAY: autorise ou non les log
** LOG_ALL: force tous les log à 1
*/
# define LOG_DISPLAY 1
# define LOG_ALL 0
# define LOG_DEBUG 0
# define LOG_DEBUG_DETAILED 0
# define LOG_DEBUG_CHECKLIVE 0
# define LOG_GENERAL 0
# define LOG_KEY 0
# define LOG_ITOW 0
# define LOG_SCENE 0
# define LOG_MOUSE 0
# define LOG_LOOP 0
# define LOG_FREE 0
# define LOG_XTOI 0
# define LOG_NEWI 0
# define LOG_MLX 0
# define LOG_VM 0
# define LOG_PROC 0
# define LOG_INST 0
# define LOG_DISPLAYING 0
# define LOG_EFFECT 0

#endif
