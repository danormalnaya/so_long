/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:27:04 by lloko             #+#    #+#             */
/*   Updated: 2022/05/05 13:00:38 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct	s_map
{
	int		x;
	int		y;
	char	**arr;
}				t_map;

typedef struct	s_game
{
	int		wall;
	int		space;
	int		p_count;
	int		e_count;
	int		c_count;
	int		player_x;
	int		player_y;
	int		score; /*определить сколько колекционных предметов есть на карте */
	int		coll; /* вначале игры будет 0, то количество предметов которые мы собрали в игре */
	int		exit;
	int		end_game;
	t_map	map;
}				t_game;

int	map_check(char **map, char *file);

#endif
