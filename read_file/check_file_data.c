#include "../includes/cub3d.h"

void print_maps(t_game *game)
{
    size_t row;
    size_t column;

    row = 0;
    column = 0;
    while(game->mapinfo.file[row] != NULL)
    {
        column = 0;
        while (game->mapinfo.file[row][column])
        {
            write(1, &game->mapinfo.file[row][column], 1);
            column++;
        }
        row++;
    }
    write(1, "\n", 1);
    return ;
}

void which_direction_and_copy(t_game *game, size_t row, size_t column)
{ 
    printf("check\n");
    printf("game->mapinfo.file[row][column] = %c\n", game->mapinfo.file[row][column]);
    printf("game->mapinfo.file[row][column + 1] = %c\n", game->mapinfo.file[row][column + 1]);
    printf("game->mapinfo.file[row][column + 2] = %c\n", game->mapinfo.file[row][column + 2]);
    printf("game->mapinfo.file[row][column] = %s\n", &game->mapinfo.file[row][column]);
    if(game->mapinfo.file[row][column] == 'N' && game->mapinfo.file[row][column + 1] == 'O')
        game->texinfo.north = my_strdup(&game->mapinfo.file[row][column], game->node);
    else if(game->mapinfo.file[row][column] == 'S' && game->mapinfo.file[row][column + 1] == 'O')
        game->texinfo.south = my_strdup(&game->mapinfo.file[row][column], game->node);
    else if(game->mapinfo.file[row][column] == 'W' && game->mapinfo.file[row][column + 1] == 'E')
        game->texinfo.west = my_strdup(&game->mapinfo.file[row][column], game->node);
    else if(game->mapinfo.file[row][column] == 'E' && game->mapinfo.file[row][column + 1] == 'A')
        game->texinfo.east = my_strdup(&game->mapinfo.file[row][column], game->node);
    else
        goodbye(game, ERROR, "Invalid map\nxpm file is invalid direction\n");
}

void copy_xpm_path(t_game *game, size_t row, size_t column)
{
    size_t start_pos;
    
    start_pos = column;

    while(game->mapinfo.file[row][column] != '\n')
        column++;
    printf("column = %zu\n", column);
    printf("start_pos = %zu\n", start_pos);
    printf("column char = %c\n", game->mapinfo.file[row][column]);
    if(game->mapinfo.file[row][column - 1] != 'm' && game->mapinfo.file[row][column - 2] != 'p' && game->mapinfo.file[row][column - 3] != 'x' && game->mapinfo.file[row][column - 4] != '.')
        goodbye(game, ERROR, "Invalid map\nxpm file is invalid extension\n");
    column = start_pos;
    which_direction_and_copy(game, row, column);
    printf("check\n");
}

bool is_four_xpmlines(t_game *game)
{
    size_t row;
    size_t column;
   
    row = 0;
    column = 0;
    while(game->mapinfo.file[row] != NULL)
    {
        column = 0;
        while (game->mapinfo.file[row][column])
        {
           while(is_space(game->mapinfo.file[row][column]) == true)
                column++;
           if(game->mapinfo.file[row][column] == 'N' || game->mapinfo.file[row][column] == 'S' || game->mapinfo.file[row][column] == 'W' || game->mapinfo.file[row][column] == 'E')
                copy_xpm_path(game, row, column);
            if(game->texinfo.north != NULL && game->texinfo.south != NULL && game->texinfo.west != NULL && game->texinfo.east != NULL)
                return (true);
            column++;
        }
        row++;
    }
    return (true);
}

void check_file_data(t_game *game)
{
    print_maps(game);
    if(is_four_xpmlines(game) == ERROR)
        goodbye(game, ERROR, "Invalid map\n xpm data is not enough\n");
    return ;
}
