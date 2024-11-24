#include "../includes/cub3d.h"

static bool is_all_space(char *line)
{
    size_t i;
    
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
    while(line[i] != '\0')
    {
        if(line[i] != '1' && !is_space(line[i]))
           return (false);
        i++;
    }
    if(is_all_space(line))
        return (false);
    return (true);
}

void print_map(t_game *game)
{
    int i;
    
    return ;
    i = 0;
    while(i != game->mapinfo.height)
    {
        printf("game->map[%d] = %s$\n", i, game->map[i]);
        i++;
    }
}

static void save_mapinfo_width_height(t_game *game, size_t map_start_row)
{
    size_t row;
    size_t column;
    int i;

    i = 0;
    game->map = NULL;
    row = map_start_row;
    row++;
    game->mapinfo.height = 0;
    while(game->mapinfo.file[row] != NULL && is_all_space(game->mapinfo.file[row]) == false)
        row++;
    game->mapinfo.height = row - map_start_row;
    column = 0;
    while(game->mapinfo.file[map_start_row][column] != '\0')
        column++;
    game->mapinfo.width = column;
    game->map = my_calloc(game->mapinfo.height, sizeof *game->map, game->node);
    while(i != game->mapinfo.height)
    {
        game->map[i] = my_strdup(game->mapinfo.file[map_start_row], game->node);
        map_start_row++;
        i++;
    }
    print_map(game);
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
        save_mapinfo_width_height(game, map_start_row);
        return ;
      }
      column++;
    }
    column = 0;
    row++;
  }
}


void read_file(char *file_path, t_game *game)
{
    ini_player(&game->player);
    ini_texture(&game->texinfo);
    ini_mapinfo(&game->mapinfo); 
    check_file_extension(file_path, game);
    read_map_info(file_path, game);
    check_file_data(game);
    get_celling_floor_color(game);
    get_player_position(game);
}


