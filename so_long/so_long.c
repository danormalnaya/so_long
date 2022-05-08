/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 12:06:00 by lloko             #+#    #+#             */
/*   Updated: 2022/05/08 19:17:34 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(char *file, t_game *carta)
{
	carta->e_count = 0;
	carta->c_count = 0;
	carta->p_count = 0;
	carta->score = 0;
	carta->coll = 0;
	carta->mlx = mlx_init();
	read_map(file, carta);
}

int	main(int argc, char **argv)
{
	t_game	carta;

	if (argc == 2)
	{
		init_game(argv[1], &carta);
		push_image_from_file(&carta);
		carta.win = mlx_new_window(carta.mlx, (carta.map.x - 1) * SPRITE, carta.map.y * SPRITE, "so_long");
		paint(&carta);
		mlx_loop(carta.mlx);
	}
	else
		game_over("You lose!\n");
}
