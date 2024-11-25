#include "../includes/cub3d.h"

static int rotate_player_direction(t_game *game, double rot_speed)
{
    t_player *p;
    double tmp_dir_x;

    p = &game->player; 
    tmp_dir_x = p->direction_x;
    p->direction_x = p->direction_x * cos(rot_speed) - p->direction_y * sin(rot_speed);
    p->direction_y = tmp_dir_x * sin(rot_speed) + p->direction_y * cos(rot_speed);
    tmp_dir_x = p->plane_x;
    p->plane_x = p->plane_x * cos(rot_speed) - p->plane_y * sin(rot_speed);
    p->plane_y = tmp_dir_x * sin(rot_speed) + p->plane_y * cos(rot_speed);
    printf("p->direction_x = %f\n", p->direction_x);
    printf("p->direction_y = %f\n", p->direction_y);
    printf("p->plane_x = %f\n", p->plane_x);
    printf("p->plane_y = %f\n", p->plane_y);
    return (1);
}


int rotate_player(t_game *game, double rotate_direction)
{
    int moved;
    double rot_speed;
    
    printf("rotate_player\n");
    moved = 0;
    rot_speed = ROTSPEED * rotate_direction;
    moved += rotate_player_direction(game, rot_speed);
    return (moved);
}
