/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuga <shuga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:45:46 by shuga             #+#    #+#             */
/*   Updated: 2024/12/15 20:06:03 by shuga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_strndup(const char *s, size_t n)
{
    char	*str;
    size_t	i;

    i = 0;
    str = (char *)malloc(sizeof(char) * (n + 1));
    if (!str)
        return (NULL);
    while (s[i] != '\0' && i < n)
    {
        str[i] = s[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

