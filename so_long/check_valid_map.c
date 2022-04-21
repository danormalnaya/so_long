/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:34:54 by lloko             #+#    #+#             */
/*   Updated: 2022/04/21 19:18:06 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	valid_positions(char **map, t_map *carta)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				carta->e_count++;
			if (map[i][j] == 'P')
				carta->p_count++;
			if (map[i][j] == 'C')
				carta->c_count++;
			j++;
		}
		i++;
	}
	if (carta->e_count != 1 || carta->p_count != 1 || carta->c_count == 0)
	{
		write(1, "The map contains an error\n", 26);
		return (0);
	}
	return (1);
}

static int	valid_walls(char **map)
{
	int	i;
	int	j;
	int	col;
	int	row;

	col = ft_strlen(map[0]);
	row = 0;
	while (map[row])
		row++;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[0][j] != 1 || map[row - 1][j] != 1
				|| map[i][0] != 1 || map[i][col - 1] != 1)
				return (0);
			j++;
		}
		if (j != col)
			return (0);
		i++;
	}
	return (1);
}

static int	valid_characters(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' || map[i][j] != '1' || map[i][j] != 'C'
				|| map[i][j] != 'E' || map[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	valid_extention_file(char *file)
{
	char	*name;

	if (!file)
		return (0);
	name = ft_strrchr(file, '.');
	if (ft_strncmp(name, ".ber", 5))
		return (0);
	return (1);
}

void	map_init(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		whle(game->map[i][j])
		{
			if (game->map[i][j] == '1')
				game->wall++;
			
		}
	}
}

static int	map_check(char **map, char *file)
{
	t_map	carta;
	
	return (!valid_positions(map, &carta) || !valid_walls(map)
		|| !valid_characters(map) || !valid_extention_file(file));
}

int main(char **argv)
{
	t_game game;
	if (map_check(game.map, argv[1]))
		return (0);
}