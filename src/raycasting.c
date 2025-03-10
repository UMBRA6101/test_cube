#include "../includes/cube3d.h"

int put_floor_ceiling(t_cube **cube)
{
	t_fc *fc;
	int	tx;
	int ty;
	int p;
	int color;

	fc = init_fc((*cube));
	for (int y = 0; y < SCREEN_HEIGHT; y++)
	{
		fc->rayDirX0 = (float)((*cube)->P->dirX - (*cube)->cam->planeX);
		fc->rayDirY0 = (float)((*cube)->P->dirY - (*cube)->cam->planeY);
		fc->rayDirX1 = (float)((*cube)->P->dirX + (*cube)->cam->planeX);
		fc->rayDirY1 = (float)((*cube)->P->dirY + (*cube)->cam->planeY);
		p = y - SCREEN_HEIGHT / 2;
		fc->posZ = (float)0.5 * SCREEN_HEIGHT;
		fc->rowDistance = fc->posZ / (float)(p);
		fc->floorStepX = fc->rowDistance * (fc->rayDirX1 - fc->rayDirX0) / SCREEN_WIDTH;
		fc->floorStepY = fc->rowDistance * (fc->rayDirY1 - fc->rayDirY0) / SCREEN_WIDTH;
		fc->floorX = (*cube)->P->px + fc->rowDistance * fc->rayDirX0;
		fc->floorY = (*cube)->P->py + fc->rowDistance * fc->rayDirY0;
		for (int x = 0;x < SCREEN_WIDTH; x++)
		{
			fc->cellX = (int)(fc->floorX);
			fc->cellY = (int)(fc->floorY);
			tx = (int)(fc->tex->width * (fc->floorX - fc->cellX)) & (fc->tex->width - 1);
			ty = (int)(fc->tex->height * (fc->floorY - fc->cellY)) & (fc->tex->height - 1);
			fc->floorX += fc->floorStepX;
			fc->floorY += fc->floorStepY;
			/*int	checkerBoardPattern = (int)(fc->cellX + fc->cellY) & 1;
			if (checkerBoardPattern == 0) fc->floorTexture = 3;
			else fc->floorTexture = 4*/
			color = fc->tex->addr[fc->tex->width * ty + tx];
			color = (color >> 1) & 8355711;
			(*cube)->img->texture_pixel[y][x] = color;
			(*cube)->img->texture_pixel[SCREEN_HEIGHT - y - 1][x] = color;
		}
	}
	return (0);
}

t_wall *init_wall()
{
	t_wall *wall;

	wall = ft_calloc(sizeof(t_wall), 1);
	wall->sideDistX = 0;
	wall->sideDistY = 0;
	wall->deltaDistX = 0;
	wall->deltaDistY = 0;
	wall->perWallDist = 0;
	wall->StepX = 0;
	wall->StepY = 0;
	wall->side = 0;
	wall->lineHeight = 0;
	wall->drawStart = 0;
	wall->drawEnd = 0;
	return (wall);
}

void	ft_dda(t_cube **cube)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if ((*cube)->w->sideDistX < (*cube)->w->sideDistY)
		{
			(*cube)->w->sideDistX += (*cube)->w->deltaDistX;
			(*cube)->map->mapX += (*cube)->w->StepX;
			(*cube)->w->side = 0;
		}
		else
		{
			(*cube)->w->sideDistY += (*cube)->w->deltaDistY;
			(*cube)->map->mapY += (*cube)->w->StepY;
			(*cube)->w->side = 1;
		}
		if ((*cube)->map->map[(*cube)->map->mapX][(*cube)->map->mapY] > 0)
			hit = 1;
	}
}

void	set_dda(t_cube **cube, const int x)
{
	(*cube)->cam->cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
	(*cube)->cam->rayDirX = (*cube)->P->dirX + (*cube)->cam->planeX * (*cube)->cam->cameraX;
	(*cube)->cam->rayDirY = (*cube)->P->dirY + (*cube)->cam->planeY * (*cube)->cam->cameraX;
	(*cube)->map->mapX = (int)((*cube)->P->px);
	(*cube)->map->mapY = (int)((*cube)->P->py);
	(*cube)->w->deltaDistX = ((*cube)->cam->rayDirX == 0) ? 1e30 : fabs(1 / ((*cube)->cam->rayDirX));
	(*cube)->w->deltaDistY = ((*cube)->cam->rayDirY == 0) ? 1e30 : fabs(1 / ((*cube)->cam->rayDirY));
	if ((*cube)->cam->rayDirX < 0)
	{
		(*cube)->w->StepX = -1;
		(*cube)->w->sideDistX = ((*cube)->P->px - (*cube)->map->mapX) * (*cube)->w->deltaDistX;
	}
	else
	{
		(*cube)->w->StepX = 1;
		(*cube)->w->sideDistX = ((*cube)->map->mapX + 1 - (*cube)->P->px) * (*cube)->w->deltaDistX;
	}
	if ((*cube)->cam->rayDirY < 0)
	{
		(*cube)->w->StepY = -1;
		(*cube)->w->sideDistY = ((*cube)->P->py - (*cube)->map->mapY) * (*cube)->w->deltaDistY;
	}
	else
	{
		(*cube)->w->StepY = 1;
		(*cube)->w->sideDistY = ((*cube)->map->mapY + 1 - (*cube)->P->py) * (*cube)->w->deltaDistY;
	}
}

void	ft_fov(t_cube **cube)
{
	if ((*cube)->w->side == 0)
		(*cube)->w->perWallDist = ((*cube)->w->sideDistX - (*cube)->w->deltaDistX);
	else
		(*cube)->w->perWallDist = ((*cube)->w->sideDistY - (*cube)->w->deltaDistY);
	(*cube)->w->lineHeight = (int)(SCREEN_HEIGHT / (*cube)->w->perWallDist);
	(*cube)->w->drawStart = -(*cube)->w->lineHeight / 2 + SCREEN_HEIGHT / 2 + (*cube)->P->pitch;
	if ((*cube)->w->drawStart < 0)
		(*cube)->w->drawStart = 0;
	(*cube)->w->drawEnd = (*cube)->w->lineHeight / 2 + SCREEN_HEIGHT / 2 + (*cube)->P->pitch;
	if ((*cube)->w->drawEnd >= SCREEN_HEIGHT)
		(*cube)->w->drawEnd = SCREEN_HEIGHT - 1;
}

void	ft_chose_and_set_tex(t_cube **cube)
{
	(*cube)->w->texNum = (*cube)->map->map[(*cube)->map->mapX][(*cube)->map->mapY] - 1;
	if ((*cube)->w->texNum > 3)
		(*cube)->w->texNum = 3;
	if ((*cube)->w->side == 0)
		(*cube)->w->wallX = (*cube)->P->py + (*cube)->w->perWallDist * (*cube)->cam->rayDirY;
	else
		(*cube)->w->wallX = (*cube)->P->px + (*cube)->w->perWallDist * (*cube)->cam->rayDirX;
	(*cube)->w->wallX -= floor((*cube)->w->wallX);
	(*cube)->w->texX = (int)((*cube)->w->wallX * (double)(*cube)->img->tex[(*cube)->w->side].width);
	if ((*cube)->w->side == 0 && (*cube)->cam->rayDirX > 0) (*cube)->w->texX = (*cube)->img->tex[(*cube)->w->side].width - (*cube)->w->texX - 1;
	if ((*cube)->w->side == 1 && (*cube)->cam->rayDirY < 0) (*cube)->w->texX = (*cube)->img->tex[(*cube)->w->side].width - (*cube)->w->texX - 1;
	(*cube)->w->step = 1.0 * (*cube)->img->tex[(*cube)->w->side].height / (*cube)->w->lineHeight;
	(*cube)->w->texPos = ((*cube)->w->drawStart - (*cube)->P->pitch - (double)SCREEN_HEIGHT / 2 + (double)((*cube)->w->lineHeight) / 2) * (*cube)->w->step;
}

void	ft_change_pix(t_cube **cube, const int x)
{
	int y;
	int color;

	y = (*cube)->w->drawStart;
	while (y < (*cube)->w->drawEnd)
	{
		(*cube)->w->texY = (int)(*cube)->w->texPos & ((*cube)->img->tex[(*cube)->w->side].height - 1);
		(*cube)->w->texPos += (*cube)->w->step;
		color = (*cube)->img->tex[(*cube)->w->side].addr[(((*cube)->img->tex[(*cube)->w->side].width) * (*cube)->w->texY + (*cube)->w->texX)];
		if ((*cube)->w->side == 1) color = (color >> 1) & 8355711;
		if (color > 0)
			(*cube)->img->texture_pixel[y][x] = color;
		y++;
	}
}

void	ft_cast_pix(t_cube **cube)
{
	int x;
	int y;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			if ((*cube)->img->texture_pixel[y][x] > 0)
				ft_put_pixel((*cube)->img, x, y, (*cube)->img->texture_pixel[y][x]);
			x++;
		}
		y++;
	}
	reset_buff((*cube)->img->texture_pixel);
}

int	put_wall(t_cube **cube)
{
	int x;

	x = 0;
	put_floor_ceiling(cube);
	(*cube)->w = init_wall();
	(*cube)->img->img = mlx_new_image((*cube)->img->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	(*cube)->img->addr = mlx_get_data_addr((*cube)->img->img, &((*cube)->img->bits_per_pixel),
			&((*cube)->img->line_lenght), &((*cube)->img->endian));
	while (x < SCREEN_WIDTH)
	{
		set_dda(cube, x);
		ft_dda(cube);
		ft_fov(cube);
		ft_chose_and_set_tex(cube);
		ft_change_pix(cube, x);
		x++;
	}
	ft_cast_pix(cube);
	mlx_put_image_to_window((*cube)->img->mlx, (*cube)->img->win, (*cube)->img->img, 0, 0);
	return (0);
}