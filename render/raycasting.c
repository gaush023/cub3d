#include "../includes/cub3d.h"


staitc init_raycasting_info(int x, t_ray *ray, t_player *player)
{
    init_ray(ray);
    ray->camera_x = 2 * x / (double)game->window_width - 1;
    ray->dir_x = player->direction_x + player->plane_x * ray->camera_x;
    ray->dir_y = player->direction_y + player->plane_y * ray->camera_x;
    ray->map_x = (int)player->pos_x;
    ray->map_y = (int)player->pos_y;
    ray->deltadist_x = fabs(1 / ray->dir_x);
    ray->deltadist_y = fabs(1 / ray->dir_y);
}

static void set_dda(t_ray *ray, t_player *player)
{
    if(ray->dir_x < 0)
    {
        ray->step_x = -1;
        ray->sidedist_x = (player->pos_x - ray->map_x) * ray->deltadist_x;
    }
    else
    {
        ray->step_x = 1;
        ray->sidedist_x = (ray->map_x + 1.0 - player->pos_x) * ray->deltadist_x;
    }
    if(ray->dir_y < 0)
    {
        ray->step_y = -1;
        ray->sidedist_y = (player->pos_y - ray->map_y) * ray->deltadist_y;
    }
    else
    {
        ray->step_y = 1;
        ray->sidedist_y = (ray->map_y + 1.0 - player->pos_y) * ray->deltadist_y;
    }
}

static void perform_dda(t_game *game, t_ray *ray)
{
    bool hit;
    
    hit = false;
    while(!hit)
    {
        if(ray->sidedist_x < ray->sidedist_y)
        {
            ray->sidedist_x += ray->deltadist_x;
            ray->map_x += ray->step_x;
            ray->side = 0;
        }
        else
        {
            ray->sidedist_y += ray->deltadist_y;
            ray->map_y += ray->step_y;
            ray->side = 1;
        }
        if(ray->map_y < 0.25 || ray->map_y > data->mapinfo.height - 0.25 || ray->map_x > data->mapinfo.width - 1.25)
            break;
        else
        if(game->map[ray->map_x][ray->map_y] == '1')
            hit = true;
    }
}

int raycasting(t_plaeyr *player, t_game *game)
{
    t_ray ray;
    int x;

    x = 0;
    while(x < game->window_width)
    {
        init_raycasting_info(x, &ray, player);
        set_dda(&ray, player);
