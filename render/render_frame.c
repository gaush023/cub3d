#include "../includes/cub3d.h"

void init_img(t_game *game, t_img *image, int width, int height)
{
    set_img_zero(image);       
    if(!game->mlx)
        goodbye(game, ERROR, "Error initializing mlx\n");
    image->img = mlx_new_image(game->mlx, width, height);
    if (!image->img)
        goodbye(game, ERROR, "Error creating image\n");
    image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits, &image->size_line, &image->endian);

}

void set_image_pixel(t_img *image, int x, int y, int color)
{
    int pixel;

    pixel = y * (image->size_line / 4) + x;
    image->addr[pixel] = color;
}


void set_frame_pixel(t_game *game, t_img *image, int x, int y)
{
    if(game->texture_pixels[y][x] > 0)
    {
        set_image_pixel(image, x, y, game->texture_pixels[y][x]);
    }
    else if(y < game->window_height / 2)
    {
        set_image_pixel(image, x, y, game->texinfo.hex_ceiling);
    }
    else if(y < game->window_height - 1)
    {
        set_image_pixel(image, x, y, game->texinfo.hex_floor);
    }
}

void    render_frame(t_game *game)
{
    t_img  image;
    int   x;
    int   y;

    image.img = NULL;
    init_img(game, &image, game->window_width, game->window_height);
    y = 0;
    while( y < game->window_height)
    {
        x = 0;
        while(x < game->window_width)
        {
            set_frame_pixel(game, &image, x, y);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(game->mlx, game->win, image.img, 0, 0);
    mlx_destroy_image(game->mlx, image.img);
    
}   

