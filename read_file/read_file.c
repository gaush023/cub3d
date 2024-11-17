#include "../includes/cub3d.h"

static bool is_all_space(char *line)
{
    size_t i;
    
    printf("is_all_space\n");
    printf("line = %s$\n", line);
    i = 0;
    while(line[i] != '\n')
    {
        if(!is_space(line[i]))
            return (false);
        i++;
    }
    return (true);
}

static bool is_all_one(char *line)
{
    size_t i;

    i = 0;
    printf("line = %s$\n", line);
    while(line[i] != '\0')
    {
        printf("line[i] = %c\n", line[i]);
        printf("is_space = %d\n", is_space(line[i]));
        if(line[i] != '1' && !is_space(line[i]))
           return (false);
        i++;
    }
    if(is_all_space(line))
        return (false);
    printf("line[i] = %c\n", line[i]);
    printf("line = %s$\n", line);
    return (true);
}

static void get_player_position(t_game *game)
{
  size_t row;
  size_t column;
  size_t map_start_row;

  row = 0;
  while(game->mapinfo.file[row] != NULL && is_all_one(game->mapinfo.file[row]) == false)
    row++;
  column = 0;
  printf("row = %zu\n", row);
  printf("game->mapinfo.file[row] = %s$\n", game->mapinfo.file[row]);
  map_start_row = row;
  row++;
  while(game->mapinfo.file[row] != NULL && is_all_one(game->mapinfo.file[row]) == false)
  {
    while(game->mapinfo.file[row][column] != '\0')
    {
      if(game->mapinfo.file[row][column] == 'N' || game->mapinfo.file[row][column] == 'S' || game->mapinfo.file[row][column] == 'W' || game->mapinfo.file[row][column] == 'E')
      {
        game->player.pos_x = (double)column + 0.5;
        game->player.pos_y = (double)(row - map_start_row) + 0.5;
        game->player.direction = game->mapinfo.file[row][column];
        return ;
      }
      column++;
    }
    column = 0;
    row++;
  }
  printf("Error\n");
}


void read_file(char *file_path, t_game *game)
{
    ini_player(&game->player);
    ini_texture(&game->texinfo);
    check_file_extension(file_path, game);
    read_map_info(file_path, game);
    check_file_data(game);
    get_celling_floor_color(game);
    get_player_position(game);
    printf("game->player.pos_x = %f\n", game->player.pos_x); 
    printf("game->player.pos_y = %f\n", game->player.pos_y);
}


