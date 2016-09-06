#ifndef FT_CONF_H
# define FT_CONF_H
/*
 *	Header pour les parametre réglable
 */
# define GRAPHIC_MODE 1
# define WIN_TITLE "Corewar"
# define WIN_X 1920
# define WIN_Y 1200

/*
**  DONNEE DE LA VM
*/
# define CHAMP_NAME_SIZE 2048
# define CYCLE_PER_LOOP 1
# define CYCLE_PER_PRINT 1

/* GESTION DU TEMPS D'ARRET DE LA BOUCLE SI RIEN N'EST A AFFICHER
 * Cela évite de spam le processeur du PC pour rien */
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

/* DOSSIER DEPUIS LEQUEL SONT AUTOMATIQUEMENT IMPORTé LES GIFS */
# define GIF_DIR "./gif/"

// # define ASC_USAGE "./ascii/help"
# define ASC_LOGO "./ascii/logo"
# define ASC_INIT "./ascii/init"
# define ASC_LOG "./ascii/log"
# define ASC_FREEDATA "./ascii/freedata"
# define ASC_EXIT_0 "./ascii/exit0"
# define ASC_EXIT_1 "./ascii/exit1"

/* CHAINE DE CARACTER POUR LES BOX DU TERMINAL */
# define TERMINAL_COLOR "\e[93m"
# define LINE_GREY "\e[93m║\e[90m"
# define LINE_GREEN "\e[93m║\e[92m"
# define LINE_BLUE "\e[93m║\e[36m"
# define LINE_GREEN2 "\e[93m║\e[32m"
# define LINE_MAG "\e[93m║\e[35m"
# define LINE_YEL "\e[93m║"

/* AFFICHAGE OU NON DES LOG,
 * LOG_DISPLAY: autorise ou non les log
 * LOG_ALL: force tous les log à 1 */
# define LOG_DISPLAY 1
# define LOG_ALL 1
# define LOG_DEBUG 1
# define LOG_DEBUG_DETAILED 1
# define LOG_DEBUG_CHECKLIVE 1
# define LOG_GENERAL 1
# define LOG_KEY 0
# define LOG_ITOW 1
# define LOG_SCENE 0
# define LOG_MOUSE 0
# define LOG_LOOP 0
# define LOG_FREE 0
# define LOG_XTOI 1
# define LOG_NEWI 0
# define LOG_MLX 0
# define LOG_VM 0
# define LOG_PROC 0

#endif
