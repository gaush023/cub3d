#include "../includes/cub3d.h"


void read_file(char *file_path, t_game *game)
{
    ini_player(&game->player);
    ini_texture(&game->texinfo);
    check_file_extension(file_path, game);
    read_map_info(file_path, game);
    check_file_data(game);
    get_celling_floor_color(game);
    printf("game->texinfo.hex_ceiling = %ld\n", game->texinfo.hex_ceiling);
    printf("game->texinfo.hex_floor = %ld\n", game->texinfo.hex_floor);
    printf("game->player.pos_x = %f\n", game->player.pos_x);
    printf("game->player.pos_y = %f\n", game->player.pos_y);
}


