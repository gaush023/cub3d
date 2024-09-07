#include "../includes/cub3d.h"

void read_file(char *file_path, t_game *game)
{
    check_file_extension(file_path, game);
    read_map_info(file_path, game);
    check_file_data(game);
    read_texture_info(game);
}

