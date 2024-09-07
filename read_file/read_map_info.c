#include "../includes/cub3d.h"

static size_t get_line_counts(char *file_path, t_game *game)
{
    int fd;
    char *line;
    size_t row;

    row = 0;
    fd = open(file_path, O_RDONLY);
    if(fd < 0)
         goodbye(game, ERROR, "File not found\n");
    else
    {
        line = get_next_line(fd, game);
        while(get_next_line(fd, game))
        {     
            row++;
            my_free(line, game->node);
            line = get_next_line(fd, game);
        }
    }
    close(fd);
    return (row);
}

void copy_file_data(t_game *game,  size_t column, size_t row, size_t i)
{
    char *line;

    line = get_next_line(game->mapinfo.fd, game);
    while(line != NULL)
    {
        game->mapinfo.file[row] = my_calloc(ft_strlen(line) + 1, sizeof(char), game->node);
        if(game->mapinfo.file[row] == NULL)
        {
            goodbye(game, 1, "Malloc failed\n");
            return(my_free_tab((void *)game->mapinfo.file, game->node));
        }
        while(line[i] != '\0')
        {
            game->mapinfo.file[row][column++] = line[i];
            i++;
        }
        game->mapinfo.file[row++][column] = '\0';
        column = 0;
        i = 0;
        my_free(line, game->node);
        line = get_next_line(game->mapinfo.fd, game);
    }
    game->mapinfo.file[row] = NULL;
}

void    read_map_info(char *file_path, t_game *game)
{
    size_t row;
    size_t i;
    size_t colunm;

    i = 0;
    row = 0;
    colunm = 0;
    game->mapinfo.line_count = get_line_counts(file_path, game);
    game->mapinfo.path = file_path;
    game->mapinfo.file = my_calloc(game->mapinfo.line_count + 1, sizeof(char *), game->node);
    if (game->mapinfo.file == NULL)
    {
        goodbye(game, 1, "Malloc failed\n");
        return ;
    }
    game->mapinfo.fd = open(file_path, O_RDONLY);
    if (game->mapinfo.fd < 0)
        goodbye(game, 1, "File not found\n");
    else
    {
        copy_file_data(game, colunm, row, i);
        close(game->mapinfo.fd);
    }
}
