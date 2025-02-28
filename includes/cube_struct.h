typedef struct	s_map
{
	int	**map;
	int	mapX;
	int	mapY;
	int	mapS;
}				t_map;

typedef struct	s_img
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		x;
	int		y;
	t_map	map;
	int	bits_per_pixel;
	int	line_lenght;
	int	endian;
	double	time;
	double	OldTime;
}				t_img;

typedef struct	s_camera
{
	double	cameraX;
	double	cameraY;
	double	rayDirX;
	double	rayDirY;
	double	planeX;
	double	planeY;
	double	time;
	double	oldTime;
}				t_camera;

typedef struct	s_player
{
	double 	px;
	double 	py;
	float 	pa;
	float 	speed_moove;
	float 	speed_rotate;
	double	dirX;
	double	dirY;
}				t_player;

typedef struct	s_cube
{
	t_img *img;
	t_map	map;
	t_player	*P;
	t_camera	*cam;
}				t_cube;

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;