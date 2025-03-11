/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodos-s <thodos-s@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:52:39 by thodos-s          #+#    #+#             */
/*   Updated: 2025/03/10 14:54:53 by thodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static int uninit_map(t_map *map)
{
	int i;

	i = 0;
	while (i < mapWidth)
		free(map->map[i++]);
	free(map->map);
	free(map);
	return (0);
}

static int uninit_tex(t_cube *cube, t_texture *tex)
{
	int i;

	i = 0;
	while (i < 5)
	{
		free(tex[i].addr);
		i++;
	}
	(void)cube;
	free(tex);
	return (0);
}

static int	uninit_img(t_img *img)
{
	int	i;

	i = 0;
	mlx_destroy_window(img->mlx, img->win);
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	/*if (img->addr)
		free(img->addr);*/
	while (i < SCREEN_HEIGHT)
		free(img->texture_pixel[i++]);
	free(img->texture_pixel);
	free(img);
	return (0);
}

void	ft_exit(t_cube *cube, int exit_value)
{
	if (!cube)
		exit(0);
	if (cube->tab_key)
		free(cube->tab_key);
	if (cube->map)
		uninit_map(cube->map);
	if (cube->tex)
		uninit_tex(cube, cube->tex);
	if (cube->img)
		uninit_img(cube->img);
	if (cube->cam)
		free(cube->cam);
	if (cube->P)
		free(cube->P);
	if (cube->w)
		free(cube->w);
	free(cube);
	exit (exit_value);
}