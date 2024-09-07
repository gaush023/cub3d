#include "../includes/cub3d.h"

char *get_next_line(int fd, t_game *game)
{
    static char line[BUFFER_SIZE + 1];
    char *line_ptr; 
    char *temp;
    int cnt;
    int copy;

    line_ptr = my_strdup(line, game->node);
    cnt = read(fd, line_ptr, BUFFER_SIZE);
    while(ft_strchr(line_ptr, '\n') == NULL && cnt > 0)
    {
        cnt = read(fd, line, BUFFER_SIZE);
        if (cnt == 0)
            return (NULL);
        line[cnt] = '\0';
        line_ptr = my_strjoin(line_ptr, line, game->node);
    }
    if(ft_strlen(line_ptr) == 0)
    {
        my_free(line_ptr, game->node);
        return (NULL);
    }
    temp = ft_strchr(line_ptr, '\n');
    if (temp != NULL)
    {
        copy = temp - line_ptr + 1;
        ft_strlcpy(line, temp + 1, BUFFER_SIZE + 1);
    }
    else
    {
        copy = ft_strlen(line_ptr);
        ft_strlcpy(line, "", BUFFER_SIZE + 1);
    }
    line_ptr[copy] = '\0';
    return (line_ptr);
}
