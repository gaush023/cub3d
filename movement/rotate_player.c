#include "../includes/cub3d.h"

 int x = 0;

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
    printf("rotate_player_direction\n");
    printf("tmp_dir_x = %f\n", tmp_dir_x);
    printf("sin(rot_speed) = %f\n", sin(rot_speed));
    printf("tmp_dir_x * sin(rot_speed) = %f\n", tmp_dir_x * sin(rot_speed));
    printf("p->plane_y = %f\n", p->plane_y);
    printf("cos(rot_speed) = %f\n", cos(rot_speed));
    printf("p->plane_y * cos(rot_speed) = %f\n", p->plane_y * cos(rot_speed));
    printf("p->plane_y = %f\n", p->plane_y);
    printf("p->direction_x * cos(rot_speed) = %f\n", p->direction_x * cos(rot_speed));
    printf("p->direction_y * sin(rot_speed) = %f\n", p->direction_y * sin(rot_speed));
    printf("p->direction_x = p->direction_x * cos(rot_speed) - p->direction_y * sin(rot_speed) = %f\n", p->direction_x);
    x++;
    printf("x = %d\n", x);
    if (x == 3)
        exit(0);
    return (1);
}


int rotate_player(t_game *game, double rotate_direction)
{
    int moved;
    double rot_speed;
    
    printf("rotate_player\n");
    printf("rotate_direction = %f\n", rotate_direction);
    moved = 0;
    rot_speed = ROTSPEED * rotate_direction;
    moved += rotate_player_direction(game, rot_speed);
    printf("moved = %d\n", moved);
    return (moved);
}
