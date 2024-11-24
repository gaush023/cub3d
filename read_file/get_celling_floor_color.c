#include "../includes/cub3d.h"

static size_t coutout_line(int *tmp, size_t row, size_t column, t_game *game)
{
    int start_pos;

    start_pos = column;
    while(game->mapinfo.file[row][column] != ',' )
    {
        if (!ft_isdigit(game->mapinfo.file[row][column]) && !is_space(game->mapinfo.file[row][column]))
            goodbye(game, ERROR, "rgb color format is invalid aa\n");
        column++;
    }
    *tmp = ft_atoi(&game->mapinfo.file[row][start_pos]);
    if (*tmp < 0 || *tmp > 255)
        goodbye(game, ERROR, "rgb color format is invalid bb\n");
    return (column);
}

static void copy_rgb_color_helper(size_t row, size_t column, t_game *game, int type)
{
    int *tmp;
    
    if(type == CEILING)
    {
        game->texinfo.ceiling = (int *)my_calloc(1, sizeof * game->texinfo.ceiling, game->node);
        if (!game->texinfo.ceiling)
            goodbye(game, ERROR, "Error allocating memory\n");
        tmp = game->texinfo.ceiling;
    }
    else
    {
        game->texinfo.floor = (int *)my_calloc(1, sizeof * game->texinfo.floor, game->node);
        if (!game->texinfo.floor)
            goodbye(game, ERROR, "Error allocating memory\n");
        tmp = game->texinfo.floor;
    }
    column = coutout_line(&tmp[0], row, column, game);
    column = coutout_line(&tmp[1], row, column + 1, game);
    tmp[2] = ft_atoi(&game->mapinfo.file[row][column + 1]);
    if (tmp[2] < 0 || tmp[2] > 255)
        goodbye(game, ERROR, "rgb color format is invalid cc\n");
}

static void copy_rgb_color(size_t row, size_t column, t_game *game, int type)
{
    size_t comma;
    size_t start_pos;

    while(!ft_isdigit(game->mapinfo.file[row][column]))
        column++;
    start_pos = column;
    if (game->mapinfo.file[row][column] == '\0')
        goodbye(game, ERROR, "rgb color format is winvalid\n");
    comma = 0;
    while (game->mapinfo.file[row][column] != '\0')
    {
        column++;
        if (game->mapinfo.file[row][column] == ',')
            comma++;
    }
    if(comma != 2)
        goodbye(game, ERROR, "rgb color format is invalid A\n");
    copy_rgb_color_helper(row, start_pos, game, type);
}

static unsigned long convert_rgb_to_hex(int *rgb)
{
    unsigned long result;
    int r;
    int g;
    int b;

    r = rgb[0];
    g = rgb[1];
    b = rgb[2];
    result = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
    return (result);
}

void get_celling_floor_color(t_game *game)
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
                 copy_rgb_color( row,  column,  game, CEILING);
            else if (game->mapinfo.file[row][column] == 'F')
                copy_rgb_color(row, column, game, FLOOR);
            column++;
        }
        row++;
    }
    if (!game->texinfo.ceiling || !game->texinfo.floor)
        goodbye(game, ERROR, "rgb color format is invalid\n");
    game->texinfo.hex_ceiling = convert_rgb_to_hex(game->texinfo.ceiling);
    game->texinfo.hex_floor = convert_rgb_to_hex(game->texinfo.floor);
    return ;
}
