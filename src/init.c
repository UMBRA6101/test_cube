#include "../includes/cube3d.h"

static t_texture *init_tex(void	*mlx)
{
	t_texture	*tex;
	int			i;

	i = 0;
	tex = NULL;
	if (!(tex = (t_texture *)ft_calloc(sizeof(t_texture), 4)))
		return (NULL);
	tex[0].tex = mlx_xpm_file_to_image(mlx, "./tex/north.xpm", &(tex[0].width), &(tex[0].height));
	tex[1].tex = mlx_xpm_file_to_image(mlx, "./tex/greystone.xpm", &(tex[1].width), &(tex[1].height));
	tex[2].tex = mlx_xpm_file_to_image(mlx, "./tex/mossy.xpm", &(tex[2].width), &(tex[2].height));
	tex[3].tex = mlx_xpm_file_to_image(mlx, "./tex/redbrick.xpm", &(tex[3].width), &(tex[3].height));
	while (i <= 3)
	{
		tex[i].addr = mlx_get_data_addr(tex[i].tex, &tex[i].bpp, &tex[i].line_lenght, &tex[i].endian);
		i++;
	}
	return (tex);
}

static t_camera	*init_cam()
{
	t_camera *cam;

	if (!(cam = calloc(sizeof(t_camera), 1)))
		return (NULL);
	cam->planeX = 0;
	cam->planeY = 0.66;
	cam->rayDirX = 0;
	cam->rayDirY = 0;
	cam->cameraX = 0;
	cam->cameraY = 0;
	return (cam);
}

static t_img	*init_img()
{
	t_img	*img;
	int		i;

	i = 0;
	img = NULL;
	if (!(img = (t_img *)calloc(sizeof(t_img), 1)))
		return (NULL);
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cube3D");
	img->tex = init_tex(img->mlx);
	img->texture_pixel = ft_calloc(SCREEN_HEIGHT + 1, sizeof(int *));
	while (i < SCREEN_HEIGHT)
		img->texture_pixel[i++] = ft_calloc(SCREEN_WIDTH + 1, sizeof(int));
	img->img = NULL;
	return (img);
}

static t_player	*init_play()
{
	t_player *P;

	if (!(P = calloc(sizeof(t_player), 1)))
		return (NULL);
	P->px = 2;
	P->py = 20;
	P->dirX = -1;
	P->dirY = 0;
	P->speed_moove = 0.2;
	P->speed_rotate = 0.06;
	return (P);
}

t_cube	*init_cube()
{
	t_cube	*cube;

	cube = NULL;
	if (!(cube = (t_cube *)calloc(sizeof(t_cube), 1)))
		return (NULL);
	if (!(cube->cam = init_cam()))
		return (NULL);
	if (!(cube->img = init_img()))
		return (NULL);
	if (!(cube->P = init_play()))
		return (NULL);
	return (cube);
}