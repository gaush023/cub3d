/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuga <shuga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:30:10 by shuga             #+#    #+#             */
/*   Updated: 2024/12/11 01:59:24 by shuga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_strndup(char *s1, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	while (s1[i] != '\0' && i < n)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*extract_next_line(char *str)
{
	char	*line;
	char	*newline_pos;

	if (!str || !str[0])
		return (NULL);
	newline_pos = ft_strchr(str, '\n');
	if (newline_pos)
		line = ft_strndup(str, newline_pos - str + 1);
	else
		line = ft_strdup(str);
	return (line);
}

static char	*next_point(char *str)
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
		stock_str = ft_strdup(point);
		free(str);
		return (stock_str);
	}
}

static char	*stock_str(char *ptr, char *tmp, int rv)
{
	char	*new_str;

	tmp[rv] = '\0';
	if (!ptr)
		return (ft_strdup(tmp));
	new_str = ft_strjoin(ptr, tmp);
	free(ptr);
	return (new_str);
}

static char	*free_buffers(char *tmp, char *ptr, int free_ptr_flag)
{
	free(tmp);
	if (free_ptr_flag)
		free(ptr);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*ptr;
	char		*tmp;
	int			rv;

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
			return (free_buffers(tmp, ptr, 1));
		tmp[rv] = '\0';
		ptr = stock_str(ptr, tmp, rv);
		if (ptr == NULL)
			return (free_buffers(tmp, ptr, 0));
	}
	free(tmp);
	tmp = extract_next_line(ptr);
	ptr = next_point(ptr);
	return (tmp);
}
