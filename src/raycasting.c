#include "../../includes/cube3d.h"

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
	int color;

	x = 0;
	(*cube)->img->img = mlx_new_image((*cube)->img->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	(*cube)->img->addr = mlx_get_data_addr((*cube)->img->img, &((*cube)->img->bits_per_pixel), &((*cube)->img->line_lenght), &((*cube)->img->endian));
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
		//int texNum = worldMap[(*cube)->map.mapX][(*cube)->map.mapY] - 1;
		double	wallX;
		if (side == 0)
			wallX = (*cube)->P->py + perWallDist * (*cube)->cam->rayDirY;
		else
			wallX = (*cube)->P->px + perWallDist * (*cube)->cam->rayDirX;
		wallX -= floor(wallX);
		int texX = (int)(wallX * (*cube)->img->tex.line_lenght);
		if (side == 0 && (*cube)->cam->rayDirX > 0) texX = (*cube)->img->tex.line_lenght - texX - 1;
		if (side == 1 && (*cube)->cam->rayDirY < 0) texX = (*cube)->img->tex.line_lenght - texX - 1;
		double	step = 1.0 * (*cube)->img->tex.height / lineHeight;
		double	texPos = (drawStart - pitch - SCREEN_HEIGHT / 2 + lineHeight / 2) * step;
		for (int y = drawStart; y < drawEnd; y++)
		{
			int texY = (int)texPos & ((*cube)->img->tex.line_lenght - 1);
			texPos += step;
			color = (*cube)->img->tex.addr[((*cube)->img->tex.line_lenght * texY + texX)];
			//if (side == 1) color = (color >> 1) & 8355711;
			if (color > 0)
				(*cube)->img->texture_pixel[y][x] = color;
		}
		x++;
	}
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

int	raycasting(t_cube *cube)
{

	return (-1);
}