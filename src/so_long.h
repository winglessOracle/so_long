/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlo <carlo@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 10:29:04 by Carlo Wesse   #+#    #+#                 */
/*   Updated: 2023/01/27 15:39:01 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_enemy
{
	xpm_t			**enemy_t_r;
	xpm_t			**enemy_t_l;
	xpm_t			**enemy_t_u;
	xpm_t			**enemy_t_d;
	mlx_image_t		*enemy_imgh;
	mlx_image_t		*enemy_imgv;
	int				dir_hori;
	int				dir_vert;
	int				e_x;
	int				e_y;
	int				img_count;
}	t_enemy;

typedef struct s_player
{
	xpm_t			**player_t_r;
	xpm_t			**player_t_l;
	xpm_t			**player_t_u;
	xpm_t			**player_t_d;
	mlx_image_t		*player_img;
	int				p_x;
	int				p_y;
	int				life;
	int				img_count;
}	t_player;

typedef struct s_collectable
{
	int				offset_x;
	int				offset_y;
	int				c_x;
	int				c_y;
	xpm_t			*collectable_t;
	mlx_image_t		*collectable_img;
}	t_collectable;

typedef struct s_map
{
	xpm_t			*open_sp_t;
	xpm_t			*wall_texture;
	xpm_t			*exit_texture;
	xpm_t			*open_exit_texture;
	xpm_t			*black_texture;
	xpm_t			*heart_texture;
	mlx_image_t		*collectable_img;
	mlx_image_t		*exit_img;
	mlx_image_t		*open_exit_img;
	mlx_image_t		*black_img;
	mlx_image_t		*bg_img;
	mlx_image_t		*walls_img;
	mlx_image_t		*heart_img;
	int				base_width;
	int				base_height;
}	t_map;

typedef struct s_font
{
	int				offset_x;
	int				offset_y;
	xpm_t			**d_t;
	xpm_t			*zero_texture;
	xpm_t			*one_texture;
	xpm_t			*two_texture;
	xpm_t			*three_texture;
	xpm_t			*four_texture;
	xpm_t			*five_texture;
	xpm_t			*six_texture;
	xpm_t			*seven_texture;
	xpm_t			*eight_texture;
	xpm_t			*nine_texture;
	mlx_image_t		*fd_img;
	mlx_image_t		*sd_img;
	mlx_image_t		*td_img;
}	t_font;

typedef struct s_g
{
	char			**grid;
	mlx_t			*mlx;
	t_font			*font;
	t_collectable	*collectable;
	t_player		*player;
	t_enemy			*enemy;
	t_map			*map;
	xpm_t			*end_screen_t;
	xpm_t			*death_screen_t;
	mlx_image_t		*screen_img;
	int				grid_width;
	int				grid_height;
	int				count_steps;
	int				count_collect;
	int				count_to_exit;
	int				count_exit;
	int				count_player;
	int				count_level;
	int				last_level;
	int				count_enemyh;
	int				count_enemyv;
	int				put_enemyh;
	int				put_enemyv;
	bool			at_exit;
	bool			exit_open;
	char			*current_map;
	double			time_attack;
	char			*allowed_symbols;
}	t_g;

typedef struct s_flood
{
	char		**map;
	int			cols;
	int			rows;
	int			count_collect;
	int			p_x;
	int			p_y;
	bool		exit_found;
}	t_flood;

//checks
int		check_grid(t_g *g);
void	check_grid_symbols(t_g *g);
void	check_grid_shape(t_g *g);
void	set_enemy_counter(t_g *g);
void	check_new_ppos(t_g *g);
void	check_enemy_attack(t_g *g);
void	remove_collectable(t_g *g);
void	remove_heart(t_g *g);
bool	check_valid_move(int y, int x, char **grid);

//delete
void	delete_textures(t_g *g);
void	del_tex_map(t_map *map);
void	del_tex_play(t_player *player);
void	del_tex_eny(t_enemy *enemy);
void	del_tex_font(t_font *font);

//error_exit
void	error_msg_mapgen1(char *msg, t_g *g);
void	error_msg_mapgen(char *msg, char *line, char *joinedlines, t_g *g);
void	error_msg_pre_load(char *msg, t_g *g);
void	free_all(t_g *g);
void	error_msg(char *msg, t_g *g);
void	clean_exit(char *msg, t_g *g);

//flood
void	flood_check(char *input_file, t_g *g);
void	flood_fill(int x, int y, t_flood *flood, t_g *g);
void	init_flood(char *input_file, t_flood *flood);
void	find_pc(t_flood *flood);
char	**generate_map_flood(char *input_file);

//hooks
void	keyhook(mlx_key_data_t keydata, void *param);
void	closehook(void *param);
void	set_hooks(t_g *g);

//init
void	init_new_g(char *input_file);
void	init_g(t_g *g);
void	load_data(t_g *g);
void	build_images(t_g *g);
int		malloc_structs(t_g *g);

void	init_map(char *input_file, t_g *g);

//lvl mgt
void	end_g(t_g *g);
void	death(t_g *g);
void	next_level(t_g *g);
void	restart_map(char *map, t_g *g);

//load
void	load_map(t_g *g);
void	load_collectable(t_g *g);
void	load_font(t_g *g);
void	load_player(t_g *g);
void	load_pup(t_g *g);
void	load_pdown(t_g *g);
void	load_pleft(t_g *g);
void	load_pright(t_g *g);
void	load_enemy(t_g *g);
void	load_eup(t_g *g);
void	load_edown(t_g *g);
void	load_eleft(t_g *g);
void	load_eright(t_g *g);

//move
void	pmove_up(t_g *g);
void	pmove_down(t_g *g);
void	pmove_left(t_g *g);
void	pmove_right(t_g *g);
void	move_enemy_vert(t_g *g);
void	move_enemy_down(int i, t_g *g);
void	move_enemy_up(int i, t_g *g);
void	move_enemy_hori(t_g *g);
void	move_enemy_right(int i, t_g *g);
void	move_enemy_left(int i, t_g *g);

//put
void	put_font_heart(t_g *g);
void	put_exit_collect(t_g *g);
void	put_player(t_g *g);
void	put_enemy(int x, int y, t_g *g);
void	put_collectable(int x, int y, t_g *g);
void	put_bg(t_g *g);
void	black_line(int x, int y, t_g *g);

//step counter
void	add_step_img(t_g *g);
void	count_one_dig(char *steps, t_g *g);
void	count_two_dig(char *steps, t_g *g);
void	count_three_dig(char *steps, t_g *g);

//utils
int		ft_check_extention(const char *file, const char *extention);
void	ft_check_params(int argc, char *argv);
void	ft_free_array(char **arr);
void	free_flood(t_flood *flood);
void	leaks(void);
char	**generate_map(char *input_file, t_g *g);
void	put_img(mlx_image_t *img, int x, int y, t_g *g);

#endif
