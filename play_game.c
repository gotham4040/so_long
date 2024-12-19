/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thilefeb <thilefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:46:41 by thilefeb          #+#    #+#             */
/*   Updated: 2024/04/09 20:23:42 by thilefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_for_exit(struct s_mlx_var *s_mlx_var, char target_cell)
{
	if (target_cell == 'E' && \
			s_mlx_var->items_collected == s_mlx_var->item_image->count)
		close_window(s_mlx_var);
}

static int	remove_item_from_display(struct s_mlx_var *s_mlx_var, \
									int dx, int dy, int i)
{
	if (s_mlx_var->item_image->instances[i].x == \
		(s_mlx_var->player_image->instances[0].x + (dx * IMAGE_SIZE)) \
		&& s_mlx_var->item_image->instances[i].y == \
		(s_mlx_var->player_image->instances[0].y + (dy * IMAGE_SIZE)))
	{
		s_mlx_var->item_image->instances[i].enabled = false;
		s_mlx_var->items_collected++;
		return (1);
	}
	return (0);
}

static void	update_player_background(struct s_mlx_var *s_mlx_var, \
									int dx, int dy)
{
	s_mlx_var->map_content[s_mlx_var->coordinates[0]] \
							[s_mlx_var->coordinates[1]] = '0';
	s_mlx_var->map_content[s_mlx_var->coordinates[0] + dy] \
							[s_mlx_var->coordinates[1] + dx] = 'P';
}

void	move_player(struct s_mlx_var *s_mlx_var, int dx, int dy)
{
	char	target_cell;
	size_t	i;

	find_car(s_mlx_var, 'P', 0);
	target_cell = s_mlx_var->map_content[s_mlx_var->coordinates[0] + dy] \
										[s_mlx_var->coordinates[1] + dx];
	if (target_cell == '0' || target_cell == 'C')
	{
		if (target_cell == 'C')
		{
			i = 0;
			while (i < s_mlx_var->item_image->count)
			{
				if (remove_item_from_display(s_mlx_var, dx, dy, i))
					break ;
				i++;
			}
		}
		s_mlx_var->player_image->instances[0].x += dx * IMAGE_SIZE;
		s_mlx_var->player_image->instances[0].y += dy * IMAGE_SIZE;
		update_player_background(s_mlx_var, dx, dy);
	}
	check_for_exit(s_mlx_var, target_cell);
}
