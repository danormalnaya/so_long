/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:22:32 by lloko             #+#    #+#             */
/*   Updated: 2022/05/15 18:43:37 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SPRITE 64

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct s_map
{
	int		x;
	int		y;
	char	**arr;
}				t_map;

typedef struct s_player
{
	int		player_x;
	int		player_y;
	void	*move_pl;
}				t_player;

typedef struct s_sprite
{
	void	*wall;
	void	*background;
	void	*exit;
	void	*collect;
}				t_sprite;

typedef struct s_game
{
	int			p_count;
	int			e_count;
	int			c_count;
	int			coll;
	int			step;
	void		*mlx;
	void		*win;
	t_map		map;
	t_player	player;
	t_sprite	sprite;
}				t_game;

int		map_check(char **map, char *file, t_game *carta);
void	read_map(char *file, t_game *carta);
void	init_game(char *file, t_game *carta);
int		game_over(char *str);
int		move_player(t_game *carta, int y, int x);
void	count_rows(char *file, t_game *carta);
void	push_image_from_file(t_game *carta);
int		paint(t_game *carta);
void	move(t_game *carta);

#endif
