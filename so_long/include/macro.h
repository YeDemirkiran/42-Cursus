#ifndef MACRO_H
# define MACRO_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef WINDOW_TITLE
#  define WINDOW_TITLE "So Long"
# endif

# ifndef RES_X
#  define RES_X 960
# endif

# ifndef RES_Y
#  define RES_Y 540
# endif

# ifndef ASSETS_PATH
#  define ASSETS_PATH "./assets/"
# endif

# ifndef TEXTURES_PATH
#  define TEXTURES_PATH "./assets/textures/"
# endif

# ifndef PLAYER_SPEED
#  define PLAYER_SPEED 1
# endif

# define OBJ_EMPTY_CHAR '0'
# define OBJ_WALL_CHAR '1'
# define OBJ_COLL_CHAR 'C'
# define OBJ_EXIT_CHAR 'E'
# define OBJ_START_CHAR 'P'

#endif
