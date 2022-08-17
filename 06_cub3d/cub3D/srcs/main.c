/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:18:42 by jeujeon           #+#    #+#             */
/*   Updated: 2021/05/19 13:22:57 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int					main_loop(t_game *game)
{
	draw_floor(game);
	draw_sky(game);
	main_draw(game);
	draw_rectangles(game);
	draw_lines(game);
	draw_player(game);
	if (game->save == 1)
		ft_save(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	free_visible_zbuf(game);
	return (0);
}

void				main_draw(t_game *game)
{
	int		x;
	double	dist;

	x = 0;
	game->zbuf = malloc(sizeof(double) * game->map.r[0] + 1);
	init_visible(game);
	while (x < game->map.r[0])
	{
		dist = get_dist(game, x);
		game->zbuf[x] = dist;
		draw_wall(game, dist, x);
		x++;
	}
	draw_sprites(game);
}

void				ft_exception(int argc, char **argv, t_game *game)
{
	game->save = 0;
	if (argc != 2 && argc != 3)
		ft_exit("Cub3D Error! Invalid arguments");
	if (argc == 2 || argc == 3)
	{
		if (ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])) == NULL)
			ft_exit("Cub3D Error! Invalid arguments");
		if (argc == 3 && \
		(ft_strncmp(argv[2], "--save", ft_strlen(argv[2])) != 0 \
		|| (ft_strlen(argv[2]) != ft_strlen("--save"))))
			ft_exit("Cub3D Error! Invalid arguments");
	}
	if (argc == 3)
		game->save = 1;
}

int					main(int argc, char **argv)
{
	t_game	game;

	ft_exception(argc, argv, &game);
	parsing_init(&game, argv[1]);
	player_init(&game);
	win_init(&game);
	img_init(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.win, 17, 0L, ft_exit, "Exit Cub3D");
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
