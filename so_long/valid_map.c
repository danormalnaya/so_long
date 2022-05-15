/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 21:23:34 by lloko             #+#    #+#             */
/*   Updated: 2022/05/15 18:14:17 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	valid_positions(char **map, t_game *carta)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'E')
				carta->e_count++;
			if (map[i][j] == 'P')
			{
				carta->p_count++;
				carta->player.player_x = j;
				carta->player.player_y = i;
			}
			if (map[i][j] == 'C')
				carta->c_count++;
		}
	}
	if (carta->e_count != 1 || carta->p_count != 1 || carta->c_count < 1)
		return (1);
	return (0);
}

static int	valid_walls(char **map, t_game *carta)
{
	int	i;
	int	j;

	carta->map.x = ft_strlen(map[0]);
	carta->map.y = 0;
	while (map[carta->map.y])
		carta->map.y++;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\n')
				break ;
			if (map[0][j] != '1' || map[carta->map.y - 1][j] != '1'
				|| map[i][0] != '1' || map[i][carta->map.x - 2] != '1')
				return (1);
			j++;
		}
		if (j != carta->map.x - 1)
			return (1);
		i++;
	}
	return (0);
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
			if (map[i][j] == '\n')
				break ;
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != 'P')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	valid_extention_file(char *file)
{
	char	*name;

	if (!file)
		return (1);
	name = ft_strrchr(file, '.');
	if (ft_strncmp(name, ".ber", 4))
		return (1);
	return (0);
}

int	map_check(char **map, char *file, t_game *carta)
{
	if (map)
		if (valid_positions(map, carta) || valid_walls(map, carta)
			|| valid_characters(map) || valid_extention_file(file))
			return (1);
	return (0);
}
