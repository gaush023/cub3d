#include "../includes/cub3d.h"


void copy_rgb_color(t_game *game, char **rgb_tab, t_size type)
{
    int *rgb;

    if(is_rgb_formatt(rgb_str)
    
}

static char **cutout_line(size_t row, size_t column, t_game *game)
{
    size_t start_pos;
    size_t comma;
    size_t digit_count;

    start_pos = column;
    while(!ft_isdigit(game->mapinfo.file[row][column]))
        column++;
    if (game->mapinfo.file[row][column] == '\0')
        goodbye(game, ERROR, "rgb color format is invalid\n");
    comma = 3;
    digit_count = 3;
    while (game->mapinfo.file[row][column] != '\0' && c_count > 0)
    {
        column++;
        if (game->mapinfo.file[row][column] == ',')
        {
            comma--;
            digit_count = 3;
        }
    }
    

}

void get_celling_floor_color(t_geme *game)
{
    size_t row;
    size_t column;

    row = 0;
    column = 0;
    while (game->mapinfo.file[row] != NULL)
    {
        column = 0;
        while (game->mapinfo.file[row][column] != '\0')
        {
            while(is_space(game->mapinfo.file[row][column]))
                column++;
            if (game->mapinfo.file[row][column] == 'C')
                copy_rgb_color(, row, column, CEILING);
            else if (game->mapinfo.file[row][column] == 'F')
                copy_rgb_color(game, row, column, FLOOR);
            column++;
        }
        row++;
    }
    write(1, "\n", 1);
    return ;
}
