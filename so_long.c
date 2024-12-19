/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thilefeb <thilefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:10:43 by thilefeb          #+#    #+#             */
/*   Updated: 2024/05/02 01:54:33 by thilefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map(char **argv, struct s_mlx_var *s_mlx_var)
{
	s_mlx_var->buffer[1] = '\0';
	s_mlx_var->fd = open(argv[1], O_RDONLY);
	if (s_mlx_var->fd == -1)
	{
		ft_printf("Error opening file");
		exit(EXIT_FAILURE);
	}
	s_mlx_var->raw_content = calloc(1, sizeof(char));
	if (s_mlx_var->raw_content == NULL)
	{
		ft_printf("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	while (read(s_mlx_var->fd, s_mlx_var->buffer, 1) == 1)
		s_mlx_var->raw_content = \
		ft_strjoin_f_s1(s_mlx_var->raw_content, s_mlx_var->buffer);
	s_mlx_var->map_content = ft_split(s_mlx_var->raw_content, '\n');
	s_mlx_var->map_content_copy = ft_split(s_mlx_var->raw_content, '\n');
	free(s_mlx_var->raw_content);
	if (close(s_mlx_var->fd) == -1)
	{
		ft_printf("Error closing the map file.");
		exit(EXIT_FAILURE);
	}
}

void	close_window(void *p)
{
	struct s_mlx_var	*s_mlx_var;

	s_mlx_var = (struct s_mlx_var *)p;
	ft_freetab(s_mlx_var->map_content_copy);
	ft_freetab(s_mlx_var->map_content);
	mlx_delete_texture(s_mlx_var->player_texture);
	mlx_delete_texture(s_mlx_var->wall_texture);
	mlx_delete_texture(s_mlx_var->grass_texture);
	mlx_delete_texture(s_mlx_var->item_texture);
	mlx_delete_texture(s_mlx_var->exit_texture);
	mlx_delete_image(s_mlx_var->connection, s_mlx_var->player_image);
	mlx_delete_image(s_mlx_var->connection, s_mlx_var->wall_image);
	mlx_delete_image(s_mlx_var->connection, s_mlx_var->grass_image);
	mlx_delete_image(s_mlx_var->connection, s_mlx_var->item_image);
	mlx_delete_image(s_mlx_var->connection, s_mlx_var->exit_image);
	mlx_close_window(s_mlx_var->connection);
}

void	key_detected(mlx_key_data_t keydata, void *p)
{
	struct s_mlx_var	*s_mlx_var;

	s_mlx_var = (struct s_mlx_var *)p;
	if (keydata.key == ESCAPE)
		close_window(p);
	else if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S \
		|| keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D) \
		&& keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_W)
			move_player(s_mlx_var, 0, -1);
		else if (keydata.key == MLX_KEY_S)
			move_player(s_mlx_var, 0, 1);
		else if (keydata.key == MLX_KEY_A)
			move_player(s_mlx_var, -1, 0);
		else if (keydata.key == MLX_KEY_D)
			move_player(s_mlx_var, 1, 0);
		s_mlx_var->number_of_moves++;
		ft_printf("%d\n", s_mlx_var->number_of_moves);
	}
}

int	correct_filename_extension(char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		i = ft_strlen(s);
		if (i > 4)
		{
			if (ft_strncmp(s + ft_strlen(s) - 4, ".ber", 4) == 0)
				return (1);
		}
	}
	ft_printf("Error\nWrong filename extension\n");
	return (0);
}

int	main(int argc, char *argv[])
{
	struct s_mlx_var	s_mlx_var;

	if (argc == 2)
	{	
		s_mlx_var.items_collected = 0;
		s_mlx_var.number_of_moves = 0;
		if (correct_filename_extension(argv[1]))
		{
			get_map(argv, &s_mlx_var);
			if (check_map_1(&s_mlx_var) && check_map_2(&s_mlx_var))
				setup_window(&s_mlx_var);
			else
			{
				ft_freetab(s_mlx_var.map_content);
				ft_freetab(s_mlx_var.map_content_copy);
			}
		}
	}
	else
		ft_printf("Error\nThe program needs two arguments!\n");
	return (0);
}

// already free'd:
// s_mlx_var->raw_content, s_mlx_var->map_content, s_mlx_var->map_content_copy