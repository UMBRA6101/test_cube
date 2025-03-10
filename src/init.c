#include "../includes/cube3d.h"

int worldMap[mapWidth][mapHeight]=
		{
				{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
				{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
				{4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
				{4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
				{4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
				{4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
				{4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
				{4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
				{4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
				{4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
				{4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
				{4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
				{6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
				{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
				{6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
				{4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
				{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
				{4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
				{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
				{4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
				{4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
				{4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
				{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
				{4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
		};

static int *test(void *mlx, t_texture *tex, char *path)
{
	t_texture tmp;
	int *buffer;

	tmp.tex = mlx_xpm_file_to_image(mlx, path, &tex->width, &tex->height);
	tmp.addr = (int *)mlx_get_data_addr(tmp.tex, &(tex->bpp), &(tex->line_lenght), &(tex->endian));
	buffer = ft_calloc(1, sizeof(int) * tex->height * tex->width + 1);
	for (int y = 0; y < tex->height; y++)
	{
		for (int x = 0;x < tex->width; x++)
		{
			buffer[y * tex->width + x] = tmp.addr[y * tex->width + x];
		}
	}
	mlx_destroy_image(mlx, tmp.tex);
	return (buffer);
}

t_fc	*init_fc(t_cube *cube)
{
	t_fc *fc;

	fc = (t_fc *)ft_calloc(sizeof(t_fc), 1);
	fc->tex = ft_calloc(sizeof(t_texture), 1);
	fc->tex->addr = test(cube->img->mlx, fc->tex, "./tex/wood.xpm");
	return (fc);
}

static t_texture *init_tex(void	*mlx)
{
	t_texture	*tex;
	int			i;

	i = 0;
	tex = NULL;
	if (!(tex = (t_texture *)ft_calloc(sizeof(t_texture), 5)))
		return (NULL);
	/*tex[0].tex = mlx_xpm_file_to_image(mlx, "./tex/north.xpm", &(tex[0].width), &(tex[0].height));
	tex[1].tex = mlx_xpm_file_to_image(mlx, "./tex/greystone.xpm", &(tex[1].width), &(tex[1].height));
	tex[2].tex = mlx_xpm_file_to_image(mlx, "./tex/mossy.xpm", &(tex[2].width), &(tex[2].height));
	tex[3].tex = mlx_xpm_file_to_image(mlx, "./tex/redbrick.xpm", &(tex[3].width), &(tex[3].height));
	while (i <= 3)
	{
		tex[i].addr = (int *)mlx_get_data_addr(tex[i].tex, &tex[i].bpp, &tex[i].line_lenght, &tex[i].endian);
		i++;
	}*/
	tex[0].addr = test(mlx, &tex[0], "./tex/north.xpm");
	tex[1].addr = test(mlx, &tex[1], "./tex/greystone.xpm");
	tex[2].addr = test(mlx, &tex[2], "./tex/mossy.xpm");
	tex[3].addr = test(mlx, &tex[3], "./tex/redbrick.xpm");
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
	P->speed_move = 0.06;
	P->speed_rotate = 0.03;
	P->pitch = 0;
	return (P);
}

static t_map *init_map()
{
	t_map *map;
	int i;

	i = 0;
	map = NULL;
	if (!(map = ft_calloc(sizeof(t_map), 1)))
		return (NULL);
	if (!(map->map = ft_calloc(sizeof(int *), mapWidth)))
		return (NULL);
	while (i < mapWidth) {
		if (!(map->map[i++] = ft_calloc(sizeof(int), mapHeight)))
			clear_dubl_buff(map->map);
	}
	for (int x = 0; x < mapWidth; x++)
	{
		for (int y = 0; y < mapHeight; y++)
		{
			map->map[x][y] = worldMap[x][y];
		}
	}
	return (map);
}

t_cube	*init_cube()
{
	t_cube	*cube;

	cube = NULL;
	if (!(cube = (t_cube *)ft_calloc(sizeof(t_cube), 1)))
		return (NULL);
	if (!(cube->tab_key = ft_calloc(sizeof(int), 256)))
		return (NULL);
	if (!(cube->map = init_map()))
		return (NULL);
	if (!(cube->cam = init_cam()))
		return (NULL);
	if (!(cube->img = init_img()))
		return (NULL);
	if (!(cube->P = init_play()))
		return (NULL);
	return (cube);
}