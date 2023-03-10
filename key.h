/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:00:38 by otangkab          #+#    #+#             */
/*   Updated: 2023/01/25 16:15:33 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT	17
# ifdef __linux__
#  define KEY_ESC	65307
#  define KEY_LEFT	65361
#  define KEY_RIGHT	65363
#  define KEY_UP	65362
#  define KEY_DOWN	65364
#  define KEY_A		97
#  define KEY_S		115
#  define KEY_D		100
#  define KEY_W		119
# else
#  define KEY_ESC	53
#  define KEY_LEFT	123
#  define KEY_RIGHT	124
#  define KEY_UP	126
#  define KEY_DOWN	125
#  define KEY_A		0
#  define KEY_S		1
#  define KEY_D		2
#  define KEY_W		13
# endif
#endif
