#include "../../include/ex_cub.h"

static mlx_texture_t	*load_png(const char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		return (NULL);
	return (texture);
}

int	load_texture(t_player *player)
{
	if (!player || !player->data || !player->mlx || !player->mlx->mlx)
		return (1);
	if (player->data->wall_texture)
		return (0);
	player->data->sky_texture = load_png("textures/sky.png");
	player->data->ground_texture = load_png("textures/ground.png");
	player->data->wall_texture = load_png("textures/wall.png");
	player->data->goblin_texture = load_png("textures/goblin.png");
	player->data->mage_texture = load_png("textures/mage.png");
	player->data->coin_texture = load_png("textures/coin.png");
	player->data->fireball_texture = load_png("textures/fireball.png");
	if (!player->data->sky_texture || !player->data->ground_texture
		|| !player->data->wall_texture
		|| !player->data->goblin_texture || !player->data->mage_texture
		|| !player->data->coin_texture
		|| !player->data->fireball_texture)
		return (1);
	player->data->no_address = player->data->wall_texture->pixels;
	player->data->so_address = player->data->wall_texture->pixels;
	player->data->we_address = player->data->wall_texture->pixels;
	player->data->ea_address = player->data->wall_texture->pixels;
	player->data->tex_with = player->data->wall_texture->width;
	player->data->tex_height = player->data->wall_texture->height;
	return (0);
}
