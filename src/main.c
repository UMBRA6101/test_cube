/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodos-s <thodos-s@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:39:57 by thodos-s          #+#    #+#             */
/*   Updated: 2025/02/03 13:47:19 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cude3d.h"

int worldMap[mapWidth][mapHeight]=
		{
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
				{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
				{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
		};

void ft_put_pixel(t_img *img, int x, int y, int color);

int ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
/*

t_point set_point(int x, int y)
{
	t_point p;

	p.x = x;
	p.y = y;
	return (p);
}
*/

/*void	breshman(t_img *img,t_point p1, t_point p2, int color)
{
	float	x = 0, y = 0, dx = 0, dy = 0, e = 0;
	int step;

	step = 0;
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	e =	ft_max(abs((int)dx), abs((int)dy));
	dx /= e;
	dy /= e;
	x = p1.x;
	y = p1.y;
	while (step < e)
	{
		ft_put_pixel(img, x, y, color);
		x += dx;
		y += dy;
		step++;
	}
}

void	draw_cube(t_img *img, t_point p1, t_point p2, int color)
{
	int x;
	int y;

	x = p1.x;
	y = p1.y;
	while (y < p2.y)
	{
		x = p1.x;
		while (x < p2.x)
		{
			ft_put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	print_map(t_img *img)
{
	t_point p1;
	t_point	p2;
	int	x;
	int y;
	int color = 0x00FF0000;

	x = 0;
	y = 0;
	while (y < worldMap[x][y])
	{
		x = 0;
		while (x < worldMap[x][y])
		{
			if (img->map.map[y][x] >= 1)
				color = 0x00FF0000;
			else
				color = 0;
			p1.x = x * img->map.mapS;
			p1.y = y * img->map.mapS;
			p2.x = p1.x + img->map.mapS - 1;
			p2.y = p1.y + img->map.mapS - 1;
			draw_cube(img, p1, p2, color);
			x++;
		}
		y++;
	}
}*/

void ft_put_pixel(t_img *img, int x, int y, int color)
{
	char *dst;
	/*if (x >= SCREEN_WIDTH)
		x = SCREEN_WIDTH;
	if (y >= SCREEN_HEIGHT)
		y = SCREEN_HEIGHT;*/
	dst = img->addr + (y * img->line_lenght + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


static	double	ft_abs(double num)
{
	if (num > 0)
		return (num);
	return (num * -1);
}

static void	draw_vertical_line(t_cube *cube, int x, int start, int end, char *tex)
{
	int itr;

	itr = 0;
	while (start < end)
	{
		//ft_put_pixel(cube->img, x, start, color);
		cube->img->addr[start * cube->img->line_lenght + x * (cube->img->bits_per_pixel / 8)] = tex[itr * cube->img->line_lenght + x * (cube->img->bits_per_pixel / 8)];
		itr++;
		start++;
	}
}

int	put_cube(t_cube **cube)
{
	int x;
	int y;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perWallDist;
	int StepX;
	int StepY;
	int hit;
	int side;
	int lineHeight;
	int drawStart;
	int drawEnd;
	int color;

	x = 0;
	ft_bzero((*cube)->img->addr, SCREEN_WIDTH * SCREEN_HEIGHT * ((*cube)->img->bits_per_pixel) / 8);
	(*cube)->img->img = mlx_new_image((*cube)->img->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	(*cube)->img->addr = mlx_get_data_addr((*cube)->img->img, &((*cube)->img->bits_per_pixel), &((*cube)->img->line_lenght), &((*cube)->img->endian));
	while (x < SCREEN_WIDTH)
	{
		(*cube)->cam->cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
		(*cube)->cam->rayDirX = (*cube)->P->dirX + (*cube)->cam->planeX * (*cube)->cam->cameraX;
		(*cube)->cam->rayDirY = (*cube)->P->dirY + (*cube)->cam->planeY * (*cube)->cam->cameraY;
		(*cube)->map.mapX = (int)((*cube)->P->px);
		(*cube)->map.mapY = (int)((*cube)->P->py);
		deltaDistX = ((*cube)->cam->rayDirX == 0) ? 1e30 : ft_abs(1 / ((*cube)->cam->rayDirX));
		deltaDistY = ((*cube)->cam->rayDirY == 0) ? 1e30 : ft_abs(1 / ((*cube)->cam->rayDirY));
		hit = 0;
		if ((*cube)->cam->rayDirX < 0)
		{
			StepX = -1;
			sideDistX = ((*cube)->P->px - (*cube)->map.mapX) * deltaDistX;
		}
		else
		{
			StepX = 1;
			sideDistX = ((*cube)->map.mapX + 1 - (*cube)->P->px) * deltaDistX;
		}
		if ((*cube)->cam->rayDirY < 0)
		{
			StepY = -1;
			sideDistY = ((*cube)->P->py - (*cube)->map.mapY) * deltaDistY;
		}
		else
		{
			StepY = 1;
			sideDistY = ((*cube)->map.mapY + 1 - (*cube)->P->py) * deltaDistY;
		}
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				(*cube)->map.mapX += StepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				(*cube)->map.mapY += StepY;
				side = 1;
			}
			if (worldMap[(*cube)->map.mapX][(*cube)->map.mapY] > 0)
				hit = 1;
		}
		if (side == 0)
			perWallDist = (sideDistX - deltaDistX);
		else
			perWallDist = (sideDistY - deltaDistY);
		lineHeight = (int)(SCREEN_HEIGHT / perWallDist);
		drawStart = (-lineHeight / 2) + (SCREEN_HEIGHT / 2) + 100;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = (lineHeight / 2) + (SCREEN_HEIGHT / 2) + 100;
		if (drawEnd >= SCREEN_HEIGHT)
			drawEnd = SCREEN_HEIGHT - 1;
		int texNum = worldMap[(*cube)->map.mapX][(*cube)->map.mapY] - 1;
		double	wallX;
		if (side == 0)
			wallX = (*cube)->P->py + perWallDist * (*cube)->cam->rayDirY;
		else
			wallX = (*cube)->P->px + perWallDist * (*cube)->cam->rayDirX;
		int texX = (int)(wallX * (*cube)->img->tex.width);
		if (side == 0 && (*cube)->cam->rayDirX > 0) texX = (*cube)->img->tex.width - texX - 1;
		if (side == 1 && (*cube)->cam->rayDirY > 0) texX = (*cube)->img->tex.width - texX - 1;
		draw_vertical_line((*cube), x, drawStart, drawEnd, (*cube)->img->tex.addr);
		x++;
	}
	mlx_put_image_to_window((*cube)->img->mlx, (*cube)->img->win, (*cube)->img->img, 0, 0);
	return (0);
}

int	key_press(int key, void *param)
{
	t_cube *cube;

	cube = (t_cube *)param;
	if (key == 65307)
		exit(0);
	if (key == W_KEY)
	{
		if (worldMap[(int)(cube->P->px + cube->P->dirX * cube->P->speed_moove)][(int)(cube->P->py)] == 0)
			cube->P->px += cube->P->dirX * cube->P->speed_moove;
		if (worldMap[(int)(cube->P->px)][(int)(cube->P->py + cube->P->dirY * 1)] == 0)
			cube->P->py += cube->P->dirY * cube->P->speed_moove;
	}
	else if (key == S_KEY)
	{
		if (worldMap[(int)(cube->P->px - cube->P->dirX * cube->P->speed_moove)][(int)(cube->P->py)] == 0)
			cube->P->px -= cube->P->dirX * cube->P->speed_moove;
		if (worldMap[(int)(cube->P->px)][(int)(cube->P->py - cube->P->dirY * cube->P->speed_moove)] == 0)
			cube->P->py -= cube->P->dirY * cube->P->speed_moove;
	}
	else if (key == A_KEY)
	{
		double oldDirX = cube->P->dirX;
		cube->P->dirX = cube->P->dirX * cos(cube->P->speed_rotate) - cube->P->dirY * sin(cube->P->speed_rotate);
		cube->P->dirY = oldDirX * sin(cube->P->speed_rotate) + cube->P->dirY * cos(cube->P->speed_rotate);
		double oldPlaneX = cube->cam->planeX;
		cube->cam->planeX = cube->cam->planeX * cos(cube->P->speed_rotate) - cube->cam->planeY * sin(cube->P->speed_rotate);
		cube->cam->planeY = oldPlaneX * sin(cube->P->speed_rotate) + cube->cam->planeY * cos(cube->P->speed_rotate);
	}
	else if (key == D_KEY)
	{
		double oldDirX = cube->P->dirX;
		cube->P->dirX = cube->P->dirX * cos(-cube->P->speed_rotate) - cube->P->dirY * sin(-cube->P->speed_rotate);
		cube->P->dirY = oldDirX * sin(-cube->P->speed_rotate) + cube->P->dirY * cos(-cube->P->speed_rotate);
		double oldPlaneX = cube->cam->planeX;
		cube->cam->planeX = cube->cam->planeX * cos(-cube->P->speed_rotate) - cube->cam->planeY * sin(-cube->P->speed_rotate);
		cube->cam->planeY = oldPlaneX * sin(-cube->P->speed_rotate) + cube->cam->planeY * cos(-cube->P->speed_rotate);
	}
	/*else if (key == D_KEY)
	{
		double OldDirX = cube->P->dirX;
		cube->P->dirX = cube->P->dirX * cos(-cube->P->speed_rotate) - cube->P->dirY * sin(-cube->P->speed_rotate);
		cube->P->dirY = OldDirX * sin(-cube->P->speed_rotate) + cube->P->dirY * cos(-cube->P->speed_rotate);
		double OldPlaneX = cube->cam->planeX;
		cube->cam->planeX = cube->cam->planeX * cos(-cube->P->speed_rotate) - cube->cam->planeY * sin(-cube->P->speed_rotate);
		cube->cam->planeY = OldPlaneX * sin(-cube->P->speed_rotate) - cube->cam->planeY * cos(-cube->P->speed_rotate);
	}
	else if (key == A_KEY)
	{
		double OldDirX = cube->P->dirX;
		cube->P->dirX = cube->P->dirX * cos(cube->P->speed_rotate) - cube->P->dirY * sin(cube->P->speed_rotate);
		cube->P->dirY = OldDirX * sin(cube->P->speed_rotate) + cube->P->dirY * cos(cube->P->speed_rotate);
		double OldPlaneX = cube->cam->planeX;
		cube->cam->planeX = cube->cam->planeX * cos(cube->P->speed_rotate) - cube->cam->planeY * sin(cube->P->speed_rotate);
		cube->cam->planeY = OldPlaneX * sin(cube->P->speed_rotate) + cube->cam->planeY * cos(cube->P->speed_rotate);
	}*/
	//mlx_destroy_image(cube->img->mlx, cube->img->img);
	//mlx_clear_window(cube->img->mlx, cube->img->win);
	put_cube(&cube);
	return 0;
}

int	key_control(t_cube *cube)
{
	printf("hey\n");
	mlx_key_hook(cube->img->win, key_press, cube);
	return (0);
}

t_texture init_tex(void	*mlx)
{
	t_texture tex;

	tex.tex = mlx_xpm_file_to_image(mlx, "./north.xpm", &(tex.width), &(tex.height));
	tex.addr = mlx_get_data_addr(tex.tex, &tex.bpp, &tex.line_lenght, &tex.endian);
	return (tex);
}

t_img	*init_img()
{
	t_img	*img;

	img = NULL;
	if (!(img = (t_img *)calloc(sizeof(t_img), 1)))
		return (NULL);
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cube3D");
	return (img);
}

t_camera	*init_cam()
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

t_player	*init_play()
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

int	current_loop(t_cube *cube)
{
	mlx_put_image_to_window(cube->img->mlx, cube->img->win, cube->img->img, 0, 0);
	return (0);
}

int	main()
{
	t_cube	*cube;
	cube = init_cube();
	put_cube(&cube);
	mlx_hook(cube->img->win, 02, 1L<<0, key_press, cube);
	//key_control(cube);
	mlx_loop_hook(cube->img->mlx, current_loop, cube);
	mlx_loop(cube->img->mlx);
}