# Cub3D

## Introduction

Cub3D is a 3D game developed in C at 1337 Coding School, part of the 42 Network. The project uses raycasting to transform a 2D map into a 3D first-person view.

The project was completed by a team of two students. We divided the work into two main parts: my teammate handled map parsing, while I focused on raycasting. My teammate also contributed to other parts of the project, including texture rendering.

Our project received a score of **100/100** during the school evaluation.

## Project Idea and Rules

The goal was to create a simple 3D game using the following requirements:

- Develop the project using only the C programming language.
- Use the graphics library provided for the project.
- Read a `.cub` file, parse its contents, and render the map as a 3D environment.
- Represent the player using one of four starting directions: `N`, `S`, `E`, or `W`.
- Use `1` for walls and `0` for empty, walkable spaces.
- Prevent the player from walking through walls or leaving the map boundaries.
- Validate the input file and map, and handle invalid input properly.

### Example Map

```text
111111111111
100000000001
100N00000001
100000000001
100000000001
111111111111
```

In this example, the player starts in the center of the cell marked `N`, facing north.

## Parsing

We defined a structure called `data` to store the information required to initialize the game, including the player's starting position, the map as a 2D array, texture paths, and other configuration data.

My teammate implemented a function called `parsing_part`, which takes the data structure and `av[1]`, the path to the input map file, as arguments.

The function begins by initializing the data fields to zero or `NULL`. It then checks whether the filename is valid and has the correct `.cub` extension.

After validating the filename, the program opens the file and reads it line by line. Each line is checked for validity, and the map is verified against the project rules.

For example, the parser checks that the map is enclosed by walls and that the player exists in a valid position inside the map.

If an error occurs, the program displays an error message and exits with status code `1`.

## Raycasting

This is where my part of the project begins.

After my teammate validates the input and initializes the necessary data, I call a function named `start`, which takes the data structure as its only argument.

Inside `start`, I initialize several structures. Two of the most important are `t_player` and `t_mlx`.

- `t_player` stores the player's position and rotation.
- `t_mlx` stores the information required to initialize and manage the graphics.

### Finding the Player's Position

The `find_player_position` function performs two main tasks.

First, it searches the map array for the player's starting position and stores the coordinates in the player structure. I add `0.5` to both the X and Y coordinates so that the player starts in the center of their map cell.

Next, I determine the player's starting direction (`N`, `S`, `E`, or `W`) and store the corresponding angle in radians in `player->radiant`.

Once the player's position and direction are initialized, I set up the graphics system and the rendering loop. `mlx_init()` initializes the graphics context, while `mlx_loop()` runs the application's event loop until the program exits.

### Drawing the Map

```c
int	draw_map(t_pixel *pixel, t_mlx *new_mlx, t_player *player)
{
	pixel->img = mlx_new_image(new_mlx->mlx, WIDTH, HEIGHT);
	pixel->addr = mlx_get_data_addr(pixel->img, &pixel->bits_per_pixel,
		&pixel->line_length, &pixel->endian);
	load_texture(player);
	player_view(pixel, player);
	mlx_put_image_to_window(new_mlx->mlx, new_mlx->win_mlx,
		pixel->img, 0, 0);
	return (1);
}
```

This function creates a new image using `mlx_new_image()`. I think of it as a large sheet of paper on which I can draw individual pixels.

I obtain access to the image's pixel data, load the textures, render the player's view, and display the resulting image in the window using `mlx_put_image_to_window()`.

### Casting Rays Across the Field of View

```c
void	player_view(t_pixel *pixel, t_player *player)
{
	int		i;
	double	ray_angle;

	i = 0;
	ray_angle = player->radiant - degree_to_radiant(VIEW / 2);
	ray_angle = reset_radiant(ray_angle);
	while (i < WIDTH)
	{
		draw_line(pixel, player, ray_angle, i);
		ray_angle += degree_to_radiant(VIEW) / WIDTH;
		i++;
	}
}
```

In this function, I use the direction the player is facing to cast rays across their field of view.

I start at the left edge of the view and cast one ray for each vertical screen column. After each ray, I increment the angle by a small amount until the entire field of view has been covered.

Each ray is handled by `draw_line()`, which determines whether the ray hits a wall and calculates the wall's intersection position.

### Calculating Wall Intersections

```c
void	draw_line(t_pixel *pixel, t_player *player, double ray_angle, int i)
{
	ray_angle = reset_radiant(ray_angle);
	where_is_facing(ray_angle, player);
	the_intersects_horizontal(ray_angle, player);
	horizontal_ray(player);
	the_intersects_vertical(ray_angle, player);
	vertical_ray(player);
	check_the_small_distance(player);
	drawing_wall(player, pixel, i, ray_angle);
	return ;
}
```

The `where_is_facing()` function determines the direction in which the ray is travelling. For example, if the angle is greater than `0` and less than `M_PI`, the ray points downward; otherwise, it points upward. We also check whether the ray points left or right to determine its full direction.

The `the_intersects_horizontal()` function calculates the horizontal grid intersections using the DDA (Digital Differential Analyzer) approach. Instead of checking every pixel along the ray, I work with map-grid coordinates and calculate the distance between successive intersections.

This allows the ray to advance directly from one grid intersection to the next, making the process more efficient than checking every pixel individually.

The `the_intersects_vertical()` function performs a similar calculation for vertical grid intersections.

The horizontal and vertical ray functions then follow their respective intersections until a wall is hit, storing the intersection information along the way. After both checks, `check_the_small_distance()` compares the two distances and selects the closest wall intersection.

### Rendering the Walls and Textures

Finally, `drawing_wall(player, pixel, i, ray_angle)` renders the wall for the current screen column.

This part of the project combines my raycasting implementation with my teammate's texture-rendering logic. My part calculates the ray direction and determines where it intersects a wall. My teammate contributed to calculating the appropriate texture position and drawing the corresponding pixels.

Since the visible wall height and texture position vary depending on the distance and location of the intersection, the rendering logic must determine which portion of the texture to display and how to map it onto the wall.

This allows us to render textured walls instead of displaying them as single solid colours.
