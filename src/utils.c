#include "../includes/cube3d.h"

void ft_put_pixel(t_img *img, int x, int y, unsigned int color)
{
	char *dst;
	if (x >= SCREEN_WIDTH)
		x = SCREEN_WIDTH;
	if (y >= SCREEN_HEIGHT)
		y = SCREEN_HEIGHT;
	dst = img->addr + (y * img->line_lenght) + (x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	reset_buff(int	**buff)
{
	int i;
	int k;

	i = 0;
	while (buff[i])
	{
		k = 0;
		while (buff[i][k])
			buff[i][k++] = 0;
		i++;
	}
}