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

#include "cube3d.h"

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
	unsigned int	color;

	x = 0;
	(*cube)->img->img = mlx_new_image((*cube)->img->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	(*cube)->img->addr = mlx_get_data_addr((*cube)->img->img, &((*cube)->img->bits_per_pixel),
		&((*cube)->img->line_lenght), &((*cube)->img->endian));
	while (x < SCREEN_WIDTH)
	{
		(*cube)->cam->cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
		(*cube)->cam->rayDirX = (*cube)->P->dirX + (*cube)->cam->planeX * (*cube)->cam->cameraX;
		(*cube)->cam->rayDirY = (*cube)->P->dirY + (*cube)->cam->planeY * (*cube)->cam->cameraX;
		(*cube)->map.mapX = (int)((*cube)->P->px);
		(*cube)->map.mapY = (int)((*cube)->P->py);
		deltaDistX = ((*cube)->cam->rayDirX == 0) ? 1e30 : fabs(1 / ((*cube)->cam->rayDirX));
		deltaDistY = ((*cube)->cam->rayDirY == 0) ? 1e30 : fabs(1 / ((*cube)->cam->rayDirY));
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
		int pitch = 0;
		drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2 + pitch;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2 + pitch;
		if (drawEnd >= SCREEN_HEIGHT)
			drawEnd = SCREEN_HEIGHT - 1;
		int texNum = worldMap[(*cube)->map.mapX][(*cube)->map.mapY] - 1;
		if (texNum > 3)
			texNum = 3;
		double	wallX;
		if (side == 0)
			wallX = (*cube)->P->py + perWallDist * (*cube)->cam->rayDirY;
		else
			wallX = (*cube)->P->px + perWallDist * (*cube)->cam->rayDirX;
		wallX -= floor(wallX);
		int texX = (int)(wallX * (*cube)->img->tex[side].line_lenght);
		if (side == 0 && (*cube)->cam->rayDirX > 0) texX = (*cube)->img->tex[side].line_lenght - texX - 1;
		if (side == 1 && (*cube)->cam->rayDirY < 0) texX = (*cube)->img->tex[side].line_lenght - texX - 1;
		double	step = 1.0 * (*cube)->img->tex[side].height / lineHeight;
		double	texPos = (drawStart - pitch - SCREEN_HEIGHT / 2 + lineHeight / 2) * step;
		for (int y = drawStart; y < drawEnd; y++)
		{
			int texY = (int)texPos & ((*cube)->img->tex[side].line_lenght - 1);
			texPos += step;
			//color = (*cube)->img->tex[side].addr[((*cube)->img->tex[side].line_lenght * texY + texX)];
			color = (unsigned int)(*cube)->img->tex[side].addr[((*cube)->img->tex[side].line_lenght * texY + texX)];
			//if (side == 1) color = (color >> 1) & 8355711;
			if (color > 0)
				(*cube)->img->texture_pixel[y][x] = color;
		}
		x++;
	}
	//ft_bzero((*cube)->img->addr, SCREEN_WIDTH * SCREEN_HEIGHT * ((*cube)->img->bits_per_pixel) / 8);
	for (int y = 0; y < SCREEN_HEIGHT; y++)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			if ((*cube)->img->texture_pixel[y][x] > 0)
			{
				/*pixel = y * ((*cube)->img->line_lenght /2) + x;
				(*cube)->img->addr[pixel] = (*cube)->img->tex.texture_pixel[y][x];*/
				ft_put_pixel((*cube)->img, x, y, (*cube)->img->texture_pixel[y][x]);
			}
			/*else if (y < SCREEN_HEIGHT / 2)
				ft_put_pixel((*cube)->img, x, y, 0xe400ff);
			else if (y < SCREEN_HEIGHT - 1)
				ft_put_pixel((*cube)->img, x, y, 0x00fff3);*/
			x++;
		}
	}
	for (int y = 0;y < SCREEN_HEIGHT; y++)
	{
		for (int z = 0; z < SCREEN_WIDTH; z++)
			(*cube)->img->texture_pixel[y][z] = 0;
	}
	mlx_put_image_to_window((*cube)->img->mlx, (*cube)->img->win, (*cube)->img->img, 0, 0);
	return (0);
}

int	key_press(int key, void *param)
{
	t_cube *cube;

	cube = (t_cube *)param;
	mlx_destroy_image(cube->img->mlx, cube->img->img);
	mlx_clear_window(cube->img->mlx, cube->img->win);
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
	put_cube(&cube);
	return 0;
}

int	key_control(t_cube *cube)
{
	printf("hey\n");
	mlx_key_hook(cube->img->win, key_press, cube);
	return (0);
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