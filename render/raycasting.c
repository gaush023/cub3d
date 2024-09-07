#include "../includes/cub3d.h"


void init_raycasting_info(int x, t_ray *ray, t_player *player, t_game *game)
{
    ini_ray(ray);
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
            ray->side = SIDE_X;
        }
        else
        {
            ray->sidedist_y += ray->deltadist_y;
            ray->map_y += ray->step_y;
            ray->side = SIDE_Y;
        }
        if(ray->map_y < 0.25 || ray->map_y > game->mapinfo.height - 0.25 || ray->map_x > game->mapinfo.width - 1.25)
            break;
        else
        if(game->map[ray->map_x][ray->map_y] == '1')
            hit = true;
    }
}

static void caluc_line_height(t_ray *ray, t_player *player, t_game *game)
{
    if(ray->side == 0)
        ray->wall_dist = (ray->sidedist_x - ray->deltadist_x);
    else 
        ray->wall_dist = (ray->sidedist_y - ray->deltadist_y);
    ray->line_height = (int)(game->window_height / ray->wall_dist);
    ray->draw_start = -(ray->line_height) / 2 + game->window_height / 2;
    if(ray->draw_start < 0)
        ray->draw_start = 0;
    if(ray->draw_end >= game->window_height)
        ray->draw_end = game->window_height - 1;
    if(ray->side == SIDE_X)
        ray->wall_x = player->pos_y + ray->wall_dist * ray->dir_y;
    else 
        ray->wall_x = player->pos_x + ray->wall_dist * ray->dir_x;
    ray->wall_x -= floor(ray->wall_x);
}


void get_texture_index(t_game *game, t_ray *ray)
{
    if(ray->side == SIDE_X)
    {
        if(ray->dir_x > 0)
            game->texinfo.index = WEST;
        else 
            game->texinfo.index = EAST;
    }
    else {
        if(ray->dir_y > 0)
            game->texinfo.index = SOUTH;
        else 
            game->texinfo.index = NORTH;
    }
}

void update_texture_pixel(t_game *game, t_texinfo *tex, t_ray *ray, int x)
{
    int y;
    int color;

    get_texture_index(game, ray);
    tex->x = (int)(ray->wall_x * tex->size);
    if((ray->side == SIDE_X && ray->dir_x < 0) || (ray->side == SIDE_Y && ray->dir_y > 0))
        tex->x = tex->size - tex->x -1;
    tex->step = 1.0 * tex->size / ray->line_height;
    tex->pos = (ray->draw_start - game->window_height / 2 + ray->line_height / 2) * tex->step;
    y = ray->draw_start;
    while(y < ray->draw_end)
    {
        tex->y = (int)tex->pos & (tex->size - 1);    
        tex->pos += tex->step;
        color = game->texture_pixels[tex->index][tex->y * tex->size + tex->x];
        if(tex->index == NORTH || tex->index == SOUTH)
            color = (color >> 1) & GREY;
        if(color > 0)
            game->texture_pixels[y][x] = color;
        y++;
    }
}

int raycasting(t_player *player, t_game *game)
{
    t_ray ray;
    int x;

    x = 0;
    while(x < game->window_width)
    {
        init_raycasting_info(x, &ray, player, game);
        set_dda(&ray, player);
        perform_dda(game, &ray);
        caluc_line_height(&ray, player, game);
        update_texture_pixel(game, &game->texinfo,&ray, x);
        x++;
    }
    return (SUCCESS);
}   
        



