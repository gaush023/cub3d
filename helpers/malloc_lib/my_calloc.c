/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:47:26 by etakaham          #+#    #+#             */
/*   Updated: 2024/09/07 21:31:16 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_lib.h"
#include <unistd.h>
# define SIZE_MAX 9223372036854775807

static void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	tmp = (unsigned char *)b;
	while (i < len)
	{
		tmp[i] = (unsigned char)c;
		i++;
	}
	return (tmp);
}

static void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*my_calloc(size_t count, size_t size, t_node *node)
{
	void	*ptr;

	if (count && size > SIZE_MAX / count)
		return (NULL);
	if (size * count == 0)
		return (NULL);
	ptr = my_malloc(count * size, node);
	if (ptr == NULL)
	{
		write(1, "ERROR:insufficient memory\n", 26);
		my_exit(1, node);
	}
	ft_bzero(ptr, size * count);
	return (ptr);
}
