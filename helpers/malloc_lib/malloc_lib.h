/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_lib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:48:21 by etakaham          #+#    #+#             */
/*   Updated: 2024/08/31 03:18:47 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_LIB_H
# define MALLOC_LIB_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_node
{
	void			*ptr;
	bool			is_free;
	size_t			size;
	struct s_node	*next;
}					t_node;

void				*my_malloc(size_t size, t_node *node);
void				*my_calloc(size_t count, size_t size, t_node *node);
void				*my_realloc(void *ptr, size_t size, t_node *node);
int					malloc_startup(t_node *head);
int					my_free(void *ptr, t_node *node);
int					malloc_end(t_node *node);
void				my_exit(int status, t_node *node);
char				*my_itoa(int num, t_node *node);
char				**my_split(const char *s, char c, t_node *node);
char				*my_strdup(const char *s1, t_node *node);
char				*my_strjoin(const char *s1, const char *s2, t_node *node);
char				*my_strmapi(const char *s, char (*f)(unsigned int, char),
						t_node *node);
char				*my_strndup(const char *s1, size_t n, t_node *node);
void	my_free_tab(void **tab, t_node *node);
#endif
