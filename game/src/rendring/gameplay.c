#include "../../include/ex_cub.h"

static double	angle_delta(double angle)
{
	while (angle > M_PI)
		angle -= 2 * M_PI;
	while (angle < -M_PI)
		angle += 2 * M_PI;
	return (angle);
}

static int	can_see_player(t_player *player, double x, double y)
{
	double	dx;
	double	dy;
	double	length;
	int		steps;
	int		i;

	dx = player->x - x;
	dy = player->y - y;
	length = sqrt(dx * dx + dy * dy);
	steps = length * 8;
	i = 1;
	while (i < steps)
	{
		if (is_wall(player->data, x + dx * i / steps,
				y + dy * i / steps))
			return (0);
		i++;
	}
	return (1);
}

static void	add_coin(t_data *data, double x, double y)
{
	if (data->coin_count >= 32)
		return ;
	data->coins[data->coin_count].x = x + 0.5;
	data->coins[data->coin_count].y = y + 0.5;
	data->coins[data->coin_count].active = 1;
	data->coin_count++;
}

void	gameplay_init(t_player *player)
{
	int	x;
	int	y;

	y = 0;
	while (player->data->maps[y])
	{
		x = 0;
		while (player->data->maps[y][x])
		{
			if (player->data->maps[y][x] == 'G')
			{
				player->data->goblin_x = x + 0.5;
				player->data->goblin_y = y + 0.5;
			}
			else if (player->data->maps[y][x] == 'M')
			{
				player->data->mage_x = x + 0.5;
				player->data->mage_y = y + 0.5;
			}
			else if (player->data->maps[y][x] == 'K')
				add_coin(player->data, x, y);
			x++;
		}
		y++;
	}
	if (player->data->coin_count < 10)
	{
		y = 1;
		while (player->data->maps[y] && player->data->coin_count < 10)
		{
			x = 1;
			while (player->data->maps[y][x]
				&& player->data->coin_count < 10)
			{
				if (player->data->maps[y][x] == '0'
					&& calculate_distance(player->x, player->y, x + 0.5,
						y + 0.5) > 2.0)
					add_coin(player->data, x, y);
				x++;
			}
			y++;
		}
	}
	if (!player->data->goblin_x && !player->data->goblin_y)
	{
		player->data->goblin_x = player->x + 3.5;
		player->data->goblin_y = player->y;
	}
	if (!player->data->mage_x && !player->data->mage_y)
	{
		player->data->mage_x = player->x + 4.5;
		player->data->mage_y = player->y;
	}
	player->data->mage_alive = player->data->level > 1;
	player->data->mage_last_attack = mlx_get_time();
	player->data->goblin_last_x = player->data->goblin_x;
	player->data->goblin_last_y = player->data->goblin_y;
	player->data->goblin_alive = 1;
	player->data->goblin_hp = 2 + player->data->level;
}

static void	collect_coins(t_player *player)
{
	int	i;

	i = 0;
	while (i < player->data->coin_count)
	{
		if (player->data->coins[i].active
			&& calculate_distance(player->x, player->y,
				player->data->coins[i].x, player->data->coins[i].y) < 0.75)
		{
			player->data->coins[i].active = 0;
			player->data->collected_coins++;
			if (player->data->collected_coins % 3 == 0)
				player->data->fireball_ammo += 2;
		}
		i++;
	}
	if (player->data->fireball_ammo > 0)
		player->data->attack_unlocked = 1;
	if (player->data->collected_coins == player->data->coin_count)
	{
		player->data->level_complete = 1;
		mlx_close_window(player->mlx->mlx);
	}
}

void	gameplay_update(t_player *player)
{
	double	dt;
	double	distance;
	double	step;
	double	nx;
	double	ny;

	dt = player->mlx->mlx->delta_time;
	if (player->data->health <= 0)
	{
		mlx_close_window(player->mlx->mlx);
		return ;
	}
	collect_coins(player);
	if (player->data->goblin_alive)
	{
		distance = calculate_distance(player->x, player->y,
			player->data->goblin_x, player->data->goblin_y);
		step = 1.0 * dt;
		if (can_see_player(player, player->data->goblin_x,
				player->data->goblin_y))
		{
			player->data->goblin_last_x = player->x;
			player->data->goblin_last_y = player->y;
		}
		if (distance > 0.45 && distance > 0.1 && (can_see_player(player,
				player->data->goblin_x, player->data->goblin_y)
			|| calculate_distance(player->data->goblin_x,
				player->data->goblin_y, player->data->goblin_last_x,
				player->data->goblin_last_y) < 4.0))
		{
			distance = calculate_distance(player->data->goblin_x,
				player->data->goblin_y, player->data->goblin_last_x,
				player->data->goblin_last_y);
			nx = player->data->goblin_x + (player->data->goblin_last_x
				- player->data->goblin_x) / distance * step;
			ny = player->data->goblin_y + (player->data->goblin_last_y
				- player->data->goblin_y) / distance * step;
			if (!is_wall(player->data, nx, player->data->goblin_y))
				player->data->goblin_x = nx;
			if (!is_wall(player->data, player->data->goblin_x, ny))
				player->data->goblin_y = ny;
		}
		else
			player->data->goblin_wander += dt;
		if (distance <= 0.5 && can_see_player(player,
				player->data->goblin_x, player->data->goblin_y)
			&& mlx_get_time() - player->data->last_damage > 1.0)
		{
			player->data->health -= 15;
			player->data->last_damage = mlx_get_time();
			player->data->damage_flash = mlx_get_time() + 0.3;
			if (player->data->health <= 0)
				player->data->health = 0;
		}
	}
	if (player->data->mage_alive && can_see_player(player,
			player->data->mage_x, player->data->mage_y)
		&& mlx_get_time() - player->data->mage_last_attack >= 5.0)
	{
		player->data->enemy_projectile_active = 1;
		player->data->enemy_projectile_x = player->data->mage_x;
		player->data->enemy_projectile_y = player->data->mage_y;
		player->data->mage_last_attack = mlx_get_time();
	}
	if (player->data->enemy_projectile_active)
	{
		distance = calculate_distance(player->x, player->y,
			player->data->enemy_projectile_x, player->data->enemy_projectile_y);
		if (distance > 0.4)
		{
			nx = player->data->enemy_projectile_x + (player->x
				- player->data->enemy_projectile_x) / distance * 5.0 * dt;
			ny = player->data->enemy_projectile_y + (player->y
				- player->data->enemy_projectile_y) / distance * 5.0 * dt;
			if (is_wall(player->data, nx, ny))
				player->data->enemy_projectile_active = 0;
			else
			{
				player->data->enemy_projectile_x = nx;
				player->data->enemy_projectile_y = ny;
			}
		}
		else
		{
			player->data->health -= 20;
			player->data->damage_flash = mlx_get_time() + 0.3;
			player->data->enemy_projectile_active = 0;
		}
	}
	if (player->data->health <= 0)
		mlx_close_window(player->mlx->mlx);
	if (player->data->projectile_active)
	{
		step = 8.0 * dt;
		player->data->projectile_x += cos(player->radiant) * step;
		player->data->projectile_y += sin(player->radiant) * step;
		if (is_wall(player->data, player->data->projectile_x,
				player->data->projectile_y))
			player->data->projectile_active = 0;
		if (player->data->goblin_alive
			&& calculate_distance(player->data->projectile_x,
				player->data->projectile_y, player->data->goblin_x,
				player->data->goblin_y) < 0.55)
		{
			player->data->projectile_active = 0;
			player->data->goblin_hp--;
			if (player->data->goblin_hp <= 0)
				player->data->goblin_alive = 0;
		}
	}
}

void	gameplay_fire(t_player *player)
{
	if (player->data->fireball_ammo > 0 && !player->data->projectile_active
		&& player->data->goblin_alive)
	{
		player->data->fireball_ammo--;
		player->data->projectile_active = 1;
		player->data->projectile_x = player->x;
		player->data->projectile_y = player->y;
	}
}

static void	draw_sprite(t_pixel *pixel, t_player *player,
		mlx_texture_t *texture, double x, double y)
{
	double	dx;
	double	dy;
	double	distance;
	double	angle;
	double	plane;
	double	size;
	int		screen_x;
	int		start_x;
	int		end_x;
	int		start_y;
	int		end_y;
	int		column;
	int		row;
	int		tex_x;
	int		tex_y;
	uint32_t	color;

	dx = x - player->x;
	dy = y - player->y;
	distance = sqrt(dx * dx + dy * dy);
	angle = angle_delta(atan2(dy, dx) - player->radiant);
	if (distance < 0.1 || fabs(angle) > degree_to_radiant(VIEW / 2))
		return ;
	plane = (WIDTH / 2) / tan(degree_to_radiant(VIEW / 2));
	size = (OBJECT / (distance * OBJECT)) * plane;
	if (size < 1)
		size = 1;
	screen_x = WIDTH / 2 + (int)(tan(angle) * plane);
	start_x = screen_x - size / 2;
	end_x = screen_x + size / 2;
	start_y = HEIGHT / 2 - size / 2;
	end_y = HEIGHT / 2 + size / 2;
	column = start_x;
	while (column <= end_x)
	{
		if (column >= 0 && column < WIDTH && distance * OBJECT < player->zbuffer[column])
		{
			tex_x = ((column - start_x) * texture->width) / size;
			if (tex_x >= (int)texture->width)
				tex_x = texture->width - 1;
			row = start_y;
			while (row <= end_y)
			{
				if (row >= 0 && row < HEIGHT)
				{
					tex_y = ((row - start_y) * texture->height) / size;
					if (tex_y >= (int)texture->height)
						tex_y = texture->height - 1;
					color = ((uint32_t *)texture->pixels)[tex_y * texture->width + tex_x];
					if ((color & 0xFF) != 0)
						pixel_putter(pixel, column, row, color);
				}
				row++;
			}
		}
		column++;
	}
}

static void	draw_hud(t_pixel *pixel, t_player *player)
{
	int	x;
	int	y;
	int	color;

	color = 0x222222;
	y = 12;
	while (y < 212)
	{
		x = WIDTH - 32;
		while (x < WIDTH - 12)
			pixel_putter(pixel, x++, y, color);
		y++;
	}
	color = 0x22CC55;
	if (player->data->health < 20)
		color = 0xDD3333;
	y = 212 - player->data->health * 4;
	while (y < 207)
	{
		x = WIDTH - 29;
		while (x < WIDTH - 15)
			pixel_putter(pixel, x++, y, color);
		y++;
	}
	if (mlx_get_time() < player->data->damage_flash)
	{
		color = 0xDD2222;
		x = 0;
		while (x < WIDTH)
		{
			pixel_putter(pixel, x, 0, color);
			pixel_putter(pixel, x, HEIGHT - 1, color);
			x++;
		}
		y = 0;
		while (y < HEIGHT)
		{
			pixel_putter(pixel, 0, y, color);
			pixel_putter(pixel, WIDTH - 1, y, color);
			y++;
		}
	}
	color = player->data->fireball_ammo > 0 ? 0xFFAA22 : 0x555555;
	y = 35;
	while (y < 48)
	{
		x = 12;
		while (x < 62)
			pixel_putter(pixel, x++, y, color);
		y++;
	}
	color = 0xFFAA22;
	x = 12;
	while (x < 12 + player->data->fireball_ammo * 8)
	{
		y = 52;
		while (y < 60)
			pixel_putter(pixel, x, y++, color);
		x += 8;
	}
	color = 0x555555;
	x = 72;
	while (x < 72 + player->data->coin_count * 12)
	{
		y = 35;
		while (y < 48)
			pixel_putter(pixel, x, y++, color);
		x += 12;
	}
	color = 0xFFD633;
	x = 72;
	while (x < 72 + player->data->collected_coins * 12)
	{
		y = 35;
		while (y < 48)
			pixel_putter(pixel, x, y++, color);
		x += 12;
	}
}

void	draw_gameplay(t_pixel *pixel, t_player *player)
{
	int	i;

	if (player->data->goblin_alive)
		draw_sprite(pixel, player, player->data->goblin_texture,
			player->data->goblin_x, player->data->goblin_y);
	if (player->data->mage_alive)
		draw_sprite(pixel, player, player->data->mage_texture,
			player->data->mage_x, player->data->mage_y);
	i = 0;
	while (i < player->data->coin_count)
	{
		if (player->data->coins[i].active)
			draw_sprite(pixel, player, player->data->coin_texture,
				player->data->coins[i].x, player->data->coins[i].y);
		i++;
	}
	if (player->data->projectile_active)
		draw_sprite(pixel, player, player->data->fireball_texture,
			player->data->projectile_x, player->data->projectile_y);
	if (player->data->enemy_projectile_active)
		draw_sprite(pixel, player, player->data->fireball_texture,
			player->data->enemy_projectile_x,
			player->data->enemy_projectile_y);
	draw_hud(pixel, player);
}
