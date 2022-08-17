/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:24:08 by jeujeon           #+#    #+#             */
/*   Updated: 2021/05/18 23:58:47 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_move_up_down(t_game *game, int keycode)
{
	double	delta_x;
	double	delta_y;
	double	step;
	int		back_front_decision;

	delta_x = cos(game->param.angle);
	delta_y = sin(game->param.angle);
	step = (fabs(delta_x) > fabs(delta_y)) ? fabs(delta_x) : fabs(delta_y);
	back_front_decision = keycode == KEY_W ? 1 : -1;
	delta_x /= step;
	delta_y /= step;
	game->param.x += delta_x * back_front_decision / 10;
	game->param.y += delta_y * back_front_decision / 10;
	if (game->map.map[(int)floor(game->param.y)]\
	[(int)floor(game->param.x)] == 1)
	{
		game->param.x -= delta_x * back_front_decision / 10;
		game->param.y -= delta_y * back_front_decision / 10;
	}
}

void	player_move_left_right(t_game *game, int keycode)
{
	double	delta_x;
	double	delta_y;
	double	step;
	int		left_right_decision;

	delta_x = cos(game->param.angle + M_PI_2);
	delta_y = sin(game->param.angle + M_PI_2);
	step = (fabs(delta_x) > fabs(delta_y)) ? fabs(delta_x) : fabs(delta_y);
	left_right_decision = keycode == KEY_D ? -1 : 1;
	delta_x /= step;
	delta_y /= step;
	game->param.x += delta_x / 10 * left_right_decision;
	game->param.y += delta_y / 10 * left_right_decision;
	if (game->map.map[(int)floor(game->param.y)]\
	[(int)floor(game->param.x)] == 1)
	{
		game->param.x += delta_x / -10 * left_right_decision;
		game->param.y += delta_y / -10 * left_right_decision;
	}
}

int		key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		player_move_up_down(game, keycode);
	else if (keycode == KEY_S)
		player_move_up_down(game, keycode);
	else if (keycode == KEY_A)
		player_move_left_right(game, keycode);
	else if (keycode == KEY_D)
		player_move_left_right(game, keycode);
	else if (keycode == KEY_LEFT)
	{
		game->param.angle += M_PI / 30;
		if (game->param.angle >= 2 * M_PI)
			game->param.angle = 0;
	}
	else if (keycode == KEY_RIGHT)
	{
		game->param.angle -= M_PI / 30;
		if (game->param.angle <= -2 * M_PI)
			game->param.angle = 0;
	}
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}
