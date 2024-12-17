/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:29:21 by aoger             #+#    #+#             */
/*   Updated: 2024/12/17 18:50:29 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../minilibx-linux/mlx.h"
# include "../g_libft/ft_std/libft.h"
# include "../g_libft/ft_printf/ft_printf.h"
# include "../g_libft/get_next_line/get_next_line_bonus.h"

# define IMG_SIZE 32
# define NEWLINE_CHAR 1
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_enemy
{
	int	x;
	int	y;
}	t_enemy;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		wd_width;
	int		wd_height;
	void	*bg_img;
	void	*coll_img;
	void	*hero_img;
	void	*hero_rev_img;
	void	*exit_close_img;
	void	*exit_open_img;
	void	*wall_img;
	void	*wall2_img;
	void	*enemy_img;
	char	**map;
	int		map_width;
	int		map_height;
	int		hero_x;
	int		hero_y;
	t_enemy	*enemies;
	int		nbr_enemies;
	int		nbr_coll;
	int		nbr_move;
	int		hero_direction;
	int		frame;
}	t_game;

int		ft_init_game(char *file_path, t_game *game);

int		ft_check_map(t_game *game);
int		ft_check_valid_path(t_game *game);

int		ft_setup_mlx(t_game *game);
void	ft_run_game(t_game *game);
void	ft_display_image(t_game *game, void *img, int x, int y);

char	**ft_load_map(char *file_path);

int		ft_load_assets(t_game *game);

void	ft_render_map(t_game *game);

int		ft_handle_close(t_game *game);
int		ft_handle_keypress(int keycode, t_game *game);

void	ft_move_hero(t_game *game, int move_x, int move_y);

void	*ft_realloc(void *ptr, size_t new_size);
void	ft_free_tab(char **tab, int size);

int		ft_init_enemies(t_game *game);
void	ft_move_enemy(t_game *game);

int		ft_animate_wall(void *param);

#endif