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

/*int worldMap[mapWidth][mapHeight]=
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
		};*/

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




/*static void	draw_vertical_line(t_cube *cube, int x, int start, int end, char *tex)
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
}*/

/*int	key_press(int key, void *param)
{
	t_cube *cube;

	cube = (t_cube *)param;
	mlx_destroy_image(cube->img->mlx, cube->img->img);
	mlx_clear_window(cube->img->mlx, cube->img->win);
	if (key == 65307)
		exit(0);
	if (key == W_KEY)
	{
		if (cube->map->map[(int)(cube->P->px + cube->P->dirX * cube->P->speed_move)][(int)(cube->P->py)] == 0)
			cube->P->px += cube->P->dirX * cube->P->speed_move;
		if (cube->map->map[(int)(cube->P->px)][(int)(cube->P->py + cube->P->dirY * 1)] == 0)
			cube->P->py += cube->P->dirY * cube->P->speed_move;
	}
	else if (key == S_KEY)
	{
		if (cube->map->map[(int)(cube->P->px - cube->P->dirX * cube->P->speed_move)][(int)(cube->P->py)] == 0)
			cube->P->px -= cube->P->dirX * cube->P->speed_move;
		if (cube->map->map[(int)(cube->P->px)][(int)(cube->P->py - cube->P->dirY * cube->P->speed_move)] == 0)
			cube->P->py -= cube->P->dirY * cube->P->speed_move;
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
	put_wall(&cube);
	return 0;
}*/

void	set_parm(t_cube *cube)
{
	if (cube->tab_key[W_KEY] == 1)
	{
		if (cube->map->map[(int)(cube->P->px + cube->P->dirX * cube->P->speed_move)][(int)(cube->P->py)] == 0)
			cube->P->px += cube->P->dirX * cube->P->speed_move;
		if (cube->map->map[(int)(cube->P->px)][(int)(cube->P->py + cube->P->dirY * 1)] == 0)
			cube->P->py += cube->P->dirY * cube->P->speed_move;
	}
	else if (cube->tab_key[S_KEY] == 1)
	{
		if (cube->map->map[(int)(cube->P->px - cube->P->dirX * cube->P->speed_move)][(int)(cube->P->py)] == 0)
			cube->P->px -= cube->P->dirX * cube->P->speed_move;
		if (cube->map->map[(int)(cube->P->px)][(int)(cube->P->py - cube->P->dirY * cube->P->speed_move)] == 0)
			cube->P->py -= cube->P->dirY * cube->P->speed_move;
	}
	if (cube->tab_key[A_KEY] == 1)
	{
		double oldDirX = cube->P->dirX;
		cube->P->dirX = cube->P->dirX * cos(cube->P->speed_rotate) - cube->P->dirY * sin(cube->P->speed_rotate);
		cube->P->dirY = oldDirX * sin(cube->P->speed_rotate) + cube->P->dirY * cos(cube->P->speed_rotate);
		double oldPlaneX = cube->cam->planeX;
		cube->cam->planeX = cube->cam->planeX * cos(cube->P->speed_rotate) - cube->cam->planeY * sin(cube->P->speed_rotate);
		cube->cam->planeY = oldPlaneX * sin(cube->P->speed_rotate) + cube->cam->planeY * cos(cube->P->speed_rotate);
	}
	else if (cube->tab_key[D_KEY] == 1)
	{
		double oldDirX = cube->P->dirX;
		cube->P->dirX = cube->P->dirX * cos(-cube->P->speed_rotate) - cube->P->dirY * sin(-cube->P->speed_rotate);
		cube->P->dirY = oldDirX * sin(-cube->P->speed_rotate) + cube->P->dirY * cos(-cube->P->speed_rotate);
		double oldPlaneX = cube->cam->planeX;
		cube->cam->planeX = cube->cam->planeX * cos(-cube->P->speed_rotate) - cube->cam->planeY * sin(-cube->P->speed_rotate);
		cube->cam->planeY = oldPlaneX * sin(-cube->P->speed_rotate) + cube->cam->planeY * cos(-cube->P->speed_rotate);
	}
	put_wall(&cube);
}

int	key_press(int key, void *param)
{
	t_cube *cube;

	cube = (t_cube *)param;
	if (key > 256)
		return (0);
	if (cube->tab_key[key] == 0)
		cube->tab_key[key] = 1;
	else if (cube->tab_key[key] == 1)
		cube->tab_key[key] = 0;
	return (0);
}

int key_release(int key, void *param)
{
	t_cube *cube;

	cube = (t_cube *)param;
	if (key == S_KEY)
	{
		cube->tab_key[0] = 0;
	}
	return (0);
}

int	current_loop(t_cube *cube)
{
	set_parm(cube);
	mlx_put_image_to_window(cube->img->mlx, cube->img->win, cube->img->img, 0, 0);
	return (0);
}
/*
 *	cree une tableau pour les key et cree une gestion avec mlx_hook 1 si presser 0 si relacher
 * */
int	main()
{
	t_cube	*cube;
	cube = init_cube();
	put_wall(&cube);
	mlx_hook(cube->img->win, 02, 1L<<0, key_press, cube);
	mlx_hook(cube->img->win, 03, 1L<<1, key_press, cube);
	//mlx_hook(cube->img->win, 02, 1L<<0, key_press, cube);
	//key_control(cube);
	mlx_loop_hook(cube->img->mlx, current_loop, cube);
	mlx_loop(cube->img->mlx);
}