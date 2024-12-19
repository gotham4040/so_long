/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thilefeb <thilefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:02:42 by thilefeb          #+#    #+#             */
/*   Updated: 2024/04/09 21:11:55 by thilefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	what_img_to_show(struct s_mlx_var *s_mlx_var, int i, int y)
{
	if (s_mlx_var->map_content[i][y] == '1')
	{
		mlx_image_to_window(s_mlx_var->connection, \
		s_mlx_var->wall_image, y * IMAGE_SIZE, i * IMAGE_SIZE);
	}
	else if (s_mlx_var->map_content[i][y] == 'C')
	{
		mlx_image_to_window(s_mlx_var->connection, \
		s_mlx_var->item_image, y * IMAGE_SIZE, i * IMAGE_SIZE);
	}
	else if (s_mlx_var->map_content[i][y] == 'P')
	{
		mlx_image_to_window(s_mlx_var->connection, \
		s_mlx_var->player_image, y * IMAGE_SIZE, i * IMAGE_SIZE);
	}
	else if (s_mlx_var->map_content[i][y] == 'E')
	{
		mlx_image_to_window(s_mlx_var->connection, \
		s_mlx_var->exit_image, y * IMAGE_SIZE, i * IMAGE_SIZE);
	}
}

static void	show_images(struct s_mlx_var *s_mlx_var)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	mlx_image_to_window(s_mlx_var->connection, s_mlx_var->grass_image, 0, 0);
	while (i < s_mlx_var->num_rows)
	{
		while (y < s_mlx_var->num_cols)
		{
			what_img_to_show(s_mlx_var, i, y);
			y++;
		}
		y = 0;
		i++;
	}
}

static void	show_game(struct s_mlx_var *s_mlx_var)
{
	create_textures(s_mlx_var);
	create_images(s_mlx_var);
	resize_window(s_mlx_var);
	resize_images(s_mlx_var);
	show_images(s_mlx_var);
}

int	setup_window(struct s_mlx_var *s_mlx_var)
{	
	s_mlx_var->connection = mlx_init(1000, 1000, "./so_long", false);
	if (!s_mlx_var->connection)
	{
		perror("X Server Connection: Failure.\n");
		exit(EXIT_FAILURE);
	}
	mlx_key_hook(s_mlx_var->connection, key_detected, (void *)s_mlx_var);
	mlx_close_hook(s_mlx_var->connection, close_window, (void *)s_mlx_var);
	show_game(s_mlx_var);
	mlx_loop(s_mlx_var->connection);
	mlx_terminate(s_mlx_var->connection);
	return (1);
}
