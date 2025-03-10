#ifndef	CUBE_H
# define CUBE_H

# include <stdlib.h>
# include <stdio.h>
# include "cube_struct.h"
# include "hey.h"
# include "mlx.h"
# include "libft.h"
# include <math.h>

# define mapWidth 24
# define mapHeight 24
# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480

/*----init*--------*/
t_cube  *init_cube();
t_fc	*init_fc(t_cube *cube);

/*----utils--------*/
void	reset_buff(int	**buff);

/*----raycasting---*/
int put_floor_ceiling(t_cube **cube);
int	put_wall(t_cube **cube);

/*----mlx utils----*/
void ft_put_pixel(t_img *img, int x, int y, unsigned int color);

/*----free---------*/
void	clear_dubl_buff(int **buff);

#endif