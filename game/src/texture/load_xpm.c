#include "../../include/ex_cub.h"
#include <stdio.h>
#include <string.h>

typedef struct s_xpm_color
{
	char	key[10];
	uint32_t color;
} t_xpm_color;

static int	quoted_line(FILE *file, char *line, size_t size)
{
	char	*start;
	char	*end;

	start = NULL;
	while (!start && fgets(line, size, file))
		start = strchr(line, '"');
	if (!start)
		return (0);
	end = strrchr(start + 1, '"');
	if (!end)
		return (0);
	*end = '\0';
	memmove(line, start + 1, ft_strlen(start + 1) + 1);
	return (1);
}

static uint32_t	parse_color(char *value)
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;

	if (ft_strncmp(value, "None", 4) == 0)
		return (0);
	if (sscanf(value, "#%2x%2x%2x", &red, &green, &blue) != 3)
		return (0);
	return ((red << 24) | (green << 16) | (blue << 8) | 0xFF);
}

static int	find_color(t_xpm_color *colors, int count, char *key)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (ft_strncmp(colors[i].key, key, 10) == 0)
			return (i);
		i++;
	}
	return (-1);
}

static int	color_index(char *key, int cpp, int *lookup,
		t_xpm_color *colors, int count)
{
	int	index;

	if (cpp == 2)
		return (lookup[((unsigned char)key[0] << 8) | (unsigned char)key[1]]);
	index = find_color(colors, count, key);
	return (index);
}

mlx_texture_t	*load_xpm(const char *path)
{
	FILE			*file;
	mlx_texture_t	*texture;
	t_xpm_color	colors[256];
	char			line[4096];
	char			key[10];
	char			*value;
	int			width;
	int			height;
	int			color_count;
	int			cpp;
	int			i;
	int			x;
	int			y;
	int			lookup[65536];

	file = fopen(path, "r");
	if (!file || !fgets(line, sizeof(line), file)
		|| !quoted_line(file, line, sizeof(line))
		|| sscanf(line, "%d %d %d %d", &width, &height, &color_count, &cpp) != 4
		|| width <= 0 || height <= 0 || color_count <= 0 || color_count > 256
		|| cpp <= 0 || cpp >= (int)sizeof(key))
		return (file && fclose(file), NULL);
	texture = ft_calloc(1, sizeof(*texture));
	if (!texture)
		return (fclose(file), NULL);
	texture->width = width;
	texture->height = height;
	texture->bytes_per_pixel = 4;
	texture->pixels = ft_calloc((size_t)width * height, 4);
	if (!texture->pixels)
		return (free(texture), fclose(file), NULL);
	i = 0;
	ft_bzero(lookup, sizeof(lookup));
	while (i < 65536)
		lookup[i++] = -1;
	i = 0;
	while (i < color_count && quoted_line(file, line, sizeof(line)))
	{
		memcpy(colors[i].key, line, cpp);
		colors[i].key[cpp] = '\0';
		value = strchr(line + cpp, '#');
		if (!value)
			value = strstr(line + cpp, "None");
		if (!value)
			return (free(texture->pixels), free(texture), fclose(file), NULL);
		colors[i].color = parse_color(value);
		if (cpp == 2)
			lookup[((unsigned char)colors[i].key[0] << 8)
				| (unsigned char)colors[i].key[1]] = i;
		i++;
	}
	y = 0;
	while (y < height && quoted_line(file, line, sizeof(line)))
	{
		x = 0;
		while (x < width)
		{
			memcpy(key, line + x * cpp, cpp);
			key[cpp] = '\0';
			i = color_index(key, cpp, lookup, colors, color_count);
			if (i < 0)
				return (free(texture->pixels), free(texture), fclose(file), NULL);
			((uint32_t *)texture->pixels)[y * width + x] = colors[i].color;
			x++;
		}
		y++;
	}
	fclose(file);
	if (y != height)
		return (free(texture->pixels), free(texture), NULL);
	return (texture);
}
