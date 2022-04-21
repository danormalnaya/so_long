/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:27:04 by lloko             #+#    #+#             */
/*   Updated: 2022/04/21 19:18:37 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct	s_game
{
	int	x;
	int	y;
	int	height;
	int	weight;
	int wall;
	int	space;
	int	player; /*определить позицию игрока */
	int	score; /*определить сколько колекционных предметов есть на карте */
	int	coll; /* вначале игры будет 0, то количество предметов которые мы собрали в игре */
	int	exit;
	int	end_game;
	char **map; /*чтение карты в двумерный массив */
}				t_game;

typedef struct	s_map
{
	int	col;
	int	row;
	int	e_count;
	int	p_count;
	int	c_count;
}				t_map;

static int	map_check(char **map, char *file);

#endif
