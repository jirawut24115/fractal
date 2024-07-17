#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "MLX42.h"

#define WIDTH 1600
#define HEIGHT 1600

typedef struct s_screen
{
	mlx_t *mlx;
	mlx_image_t *img;
}	t_screen;


void	change_color(mlx_image_t *img, unsigned int x)
{
	for (int i = img->width - 1; i > 0; i--)
	{
		for (int j = img->height - 1; j > 0; j--)
		{
			mlx_put_pixel(img, i, j, x);
		}
	}
}

void	keypress(mlx_key_data_t keydata, void *param)
{
	mlx_image_t *img;

	img = (mlx_image_t *)param;
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
		change_color(img, 0xFF00FFFF);
	if (keydata.key == MLX_KEY_V && keydata.action == MLX_PRESS)
		change_color(img, 0x00FFFFFF);
}

void	resize(int w, int h, void *param)
{
	printf("w = %d h = %d\n", w, h);
	t_screen *screen = (t_screen *)param;
	mlx_delete_image(screen->mlx, screen->img);
	screen->img = mlx_new_image(screen->mlx, w, h);
	mlx_image_to_window(screen->mlx, screen->img, 0,0);
	change_color(screen->img, 0xFFFFFFFF);
}

int	main(void)
{
	t_screen	*screen;

	screen = malloc(sizeof(t_screen));
	if (!screen)
		return (-1);
	screen->mlx = mlx_init(WIDTH, HEIGHT, "TEST", true);
	if (!screen->mlx)
		return (printf("Init Error\n"), -1);
	screen->img = mlx_new_image(screen->mlx, screen->mlx->width, screen->mlx->height);
	if (!screen->img || (mlx_image_to_window(screen->mlx, screen->img, 0, 0) < 0))
		return (printf("Img error\n"), -1);
	change_color(screen->img, 0xFFFFFFFF);
	mlx_key_hook(screen->mlx, &keypress, screen->img);
	mlx_resize_hook(screen->mlx, &resize, screen);
	mlx_loop(screen->mlx);
	mlx_terminate(screen->mlx);
}