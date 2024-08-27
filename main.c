/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:28:02 by sagemura          #+#    #+#             */
/*   Updated: 2024/08/28 01:17:21 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (print_error("Invalid number of arguments\n"));
	if (check_parse(av[1]) == ERROR)
		return (print_error("Error parsing the file\n"));
}
