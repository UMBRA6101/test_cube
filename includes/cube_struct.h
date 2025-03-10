typedef struct	s_map
{
	int	**map;
	int	mapX;
	int	mapY;
	int	mapS;
}				t_map;

typedef struct	s_wall
{
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perWallDist;
	double	texPos;
	double	step;
	double	wallX;
	int texX;
	int texY;
	int	texNum;
	int StepX;
	int StepY;
	int side;
	int lineHeight;
	int drawStart;
	int drawEnd;
}				t_wall;

typedef struct	s_texture
{
	int		*tex;
	int		width;
	int		height;
	int		*addr;
	int		bpp;
	int		line_lenght;
	int		endian;
}				t_texture;

typedef struct	s_fc
{
	float	rayDirX0;
	float	rayDirY0;
	float	rayDirX1;
	float	rayDirY1;
	float	posZ;
	float	rowDistance;
	float	floorStepX;
	float	floorStepY;
	float	floorX;
	float	floorY;
	int		cellX;
	int 	cellY;
	int		tx;
	int 	ty;
	int 	floorTexture;
	int 	celingTexture;
	t_texture	*tex;
}				t_fc;

typedef struct	s_img
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			x;
	int			y;
	int			endian;
	int			line_lenght;
	int			bits_per_pixel;
	int			**texture_pixel;
	t_texture 	*tex;
	char		*tex_pix_addr;
	t_map		map;
}				t_img;

typedef struct	s_camera
{
	double	cameraX;
	double	cameraY;
	double	rayDirX;
	double	rayDirY;
	double	planeX;
	double	planeY;
}				t_camera;

typedef struct	s_player
{
	float 	px;
	float 	py;
	float 	pa;
	double 	speed_move;
	double 	speed_rotate;
	double	dirX;
	double	dirY;
	int 	pitch;
}				t_player;

typedef struct	s_cube
{
	int	*tab_key;
	t_img *img;
	t_map	*map;
	t_wall	*w;
	t_player	*P;
	t_camera	*cam;
}				t_cube;

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;