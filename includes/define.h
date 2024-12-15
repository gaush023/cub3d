/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuga <shuga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:28:17 by sagemura          #+#    #+#             */
/*   Updated: 2024/12/15 21:00:28 by shuga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define SUCCESS 0
# define ERROR 1
# define WIN_WIDTH 640
# define WIN_HEIGHT 480
# define TEX_SIZE 64
# define SIDE_X 0
# define SIDE_Y 1
# define GREY 8355711
# define BUFFER_SIZE 4096
# define CEILING 0
# define FLOOR 1
# define MOVESPEED 0.0125
# define ROTSPEED 0.015

# define XK_Escape 53 // Escape key
# define XK_Left 123  // Left arrow key
# define XK_Right 124 // Right arrow key
# define XK_w 13      // 'w' key
# define XK_a 0       // 'a' key
# define XK_s 1       // 's' key
# define XK_d 2       // 'd' key

// X11 event masks
# define KeyPress 2
# define KeyRelease 3
# define ClientMessage 33
# define NoEventMask 0L
# define KeyPressMask (1L << 0)
# define KeyReleaseMask (1L << 1)

#endif
