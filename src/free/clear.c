//
// Created by umbra on 3/7/25.
//
#include "../../includes/cube3d.h"

void	clear_dubl_buff(int **buff)
{
	int i;

	i = 0;
	while (buff[i])
		free(buff[i++]);
	free(buff);
}