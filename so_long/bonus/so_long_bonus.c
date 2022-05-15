/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 12:06:00 by lloko             #+#    #+#             */
/*   Updated: 2022/05/15 20:03:59 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_game(char *file, t_game *carta)
{
	carta->e_count = 0;
	carta->c_count = 0;
	carta->p_count = 0;
	carta->v_count = 0;
	//carta->step = 1;
	carta->coll = 0;
	carta->step = 0;
	carta->mlx = mlx_init();
	read_map(file, carta);
}

int	main(int argc, char **argv)
{
	t_game	carta;

	if (argc == 2)
	{
		init_game(argv[1], &carta);
		// paint(&carta);
		// carta.win = mlx_new_window(carta.mlx, (carta.map.x - 1) * SPRITE,
		// 		carta.map.y * SPRITE, "so_long");
		// move(&carta);
		// mlx_loop(carta.mlx);
		// free(carta.map.arr);
		// game_over(NULL);
	}
	else
		game_over("Don't work!\n");
}
