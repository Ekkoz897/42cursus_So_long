/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:37:08 by apereira          #+#    #+#             */
/*   Updated: 2023/01/13 13:04:13 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// passa o mapa para uma matris e conta as linhas (altura)
char	**map_cpy(int fd, char *argv, t_game	*game)
{
	while (get_next_line(fd))
		game->large++;
	close(fd);
	game->matriz = malloc(sizeof(char *) * game->large);
	fd = open(argv, O_RDONLY);
	while (game->large > 0)
	{
		game->matriz[game->tall] = get_next_line(fd);
		game->tall++;
		game->large--;
	}
	game->large = ft_strlen(game->matriz[0]);
	if (check_cpe(game->matriz, game))
		return (game->matriz);
	return (0);
}

// verifica se as bordas do mapa estão ok
int	wall_check(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(game->matriz[0]) - 1;
	game->large = ft_strlen(game->matriz[0]);
	while (i <= j)
	{
		if (game->matriz[0][i] != '1' || game->matriz[game->tall - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->tall)
	{
		if ((ft_strlen(game->matriz[i]) - 1) != j)
			return (0);
		if (game->matriz[i][0] != '1' || game->matriz[i][j] != '1')
			return (0);
		i++;
	}
	write(1, "\n\nChecking map components...\n\n", 30);
	return (check_path_check(game->matriz, game));
}

// verifica se o mapa tem todos os elementos obrigatorios
int	check_cpe(char **matriz, t_game *game)
{
	game->i = -1;
	while (++game->i < game->tall)
	{
		game->j = -1;
		while (matriz[game->i][++game->j])
		{
			if (matriz[game->i][game->j] == 'C')
				game->food++;
			else if (matriz[game->i][game->j] == 'P')
			{
				game->p++;
				game->p_x = game->j;
				game->p_y = game->i;
			}
			else if (matriz[game->i][game->j] == 'E')
				game->e++;
			else if (matriz[game->i][game->j] != '0' &&
				matriz[game->i][game->large] != '\n' &&
				matriz[game->i][game->j] != '1')
				return (0);
		}
	}
	if (game->food == 0 || game->p != 1 || game->e != 1)
		return (0);
	return (1);
}

// verifica se o resultado do path_check e valido
int	check_path_check(char **matriz, t_game *game)
{
	int	i;

	i = 0;
	game->e = 0;
	game->i = -1;
	while (++game->i < game->tall)
	{
		game->j = -1;
		while (matriz[game->i][++game->j])
		{
			if (matriz[game->i][game->j] == 'c')
				i++;
			else if (matriz[game->i][game->j] == 'e')
				game->e++;
		}
	}
	if (i != game->food || game->p != 1 || game->e != 1)
		return (0);
	return (1);
}

// verifica se o p tem um caminho de 0's ate todos os C e o E
int	check_path(int x, int y, t_game *game)
{
	if (game->matriz[x][y] == '0' || game->matriz[x][y] == 'P' ||
		game->matriz[x][y] == 'C' || game->matriz[x][y] == 'E')
	{
		if (game->matriz[x][y] == '0')
			game->matriz[x][y] = '-';
		if (game->matriz[x][y] == 'C')
			game->matriz[x][y] = 'c';
		if (game->matriz[x][y] == 'E')
			game->matriz[x][y] = 'e';
		if (check_path(x, y - 1, game))
			return (1);
		if (check_path(x + 1, y, game))
			return (1);
		if (check_path(x, y + 1, game))
			return (1);
		if (check_path(x - 1, y, game))
			return (1);
	}
	return (0);
}
