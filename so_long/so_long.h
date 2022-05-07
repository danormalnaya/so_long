/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:22:32 by lloko             #+#    #+#             */
/*   Updated: 2022/05/07 20:56:09 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h> /*удалить из проекта */
//# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct s_map
{
	int		x;
	int		y;
	char	**arr;
}				t_map;

typedef struct s_game
{
	int			wall;
	int			space;
	int			p_count;
	int			e_count;
	int			c_count;
	int			score;
	int			coll;
	int			exit;
	int			end_game;
	t_map		map;
	t_player	player;
}				t_game;

typedef struct s_player
{
	int		player_x;
	int		player_y;
}				t_player;

int		map_check(char **map, char *file);
int		game_over(char *str);
void	read_map(char *file, t_game *carta);

#endif
