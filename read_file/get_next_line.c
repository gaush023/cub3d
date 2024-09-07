#include "../includes/cub3d.h"

static char	*extract_next_line(char *str, t_game *game)
{
	char	*line;
	char	*newline_pos;

	if (!str || !str[0])
		return (NULL);
	newline_pos = ft_strchr(str, '\n');
	if (newline_pos)
		line = my_strndup(str, newline_pos - str + 1, game->node);
	else
		line = my_strdup(str, game->node);
	return (line);
}

static char	*next_point(char *str, t_game *game)
{
	char	*point;
	char	*stock_str;

	point = ft_strchr(str, '\n');
	if (!point)
	{
		free(str);
		return (NULL);
	}
	else
	{
		point += 1;
		stock_str = my_strdup(point, game->node);
		my_free(str, game->node);
		return (stock_str);
	}
}

static char	*stock_str(char *ptr, char *tmp, int rv, t_game *game)
{
	char	*new_str;

	tmp[rv] = '\0';
	if (!ptr)
		return (my_strdup(tmp, game->node));
	new_str = my_strjoin(ptr, tmp, game->node);
	my_free(ptr, game->node);
	return (new_str);
}

static char	*free_buffers(char *tmp, char *ptr, int free_ptr_flag, t_game *game)
{
	my_free(tmp, game->node);
	if (free_ptr_flag)
		my_free(ptr, game->node);
	return (NULL);
}

char	*get_next_line(int fd, t_game *game)
{
	static char	*ptr;
	char		*tmp;
	int			rv;
    (void)game;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	rv = 1;
	while (rv != 0 && !(ptr && ft_strchr(ptr, '\n')))
	{
		rv = read(fd, tmp, BUFFER_SIZE);
		if (rv == -1)
			return (free_buffers(tmp, ptr, 1, game));
		tmp[rv] = '\0';
		ptr = stock_str(ptr, tmp, rv, game);
		if (ptr == NULL)
			return (free_buffers(tmp, ptr, 0, game));
	}
	free(tmp);
	tmp = extract_next_line(ptr, game);
	ptr = next_point(ptr, game);
	return (tmp);
}