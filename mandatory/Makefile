CC = cc
CFLAGS = -Wall -Werror -Wextra -Iinclude #-fsanitize=address -g3
MLX_FLAG = -lmlx -framework OpenGL -framework AppKit -lm
SRCS2 = \
	rendring/start.c\
	rendring/draw.c\
	rendring/object.c\
	rendring/player.c\
	rendring/view.c\
	rendring/mlx_inputs.c\
	rendring/movement.c\
	rendring/helper.c\
	rendring/drawing_wall.c\
	texture/load_text.c\
	texture/load_texture_utils1.c\
	texture/load_texture_utils2.c\
	rendring/intersect.c

SRCS = \
	main.c \
	pars/parsing.c \
	pars/parsing_helper.c \
	pars/utils1.c \
	pars/utils2.c \
	pars/utils2_helper.c \
	pars/utils3.c \
	pars/utils4.c \
	pars/utils5.c \
	Libft/ft_atoi.c \
	Libft/ft_alpha.c \
	Libft/ft_lstadd_back.c \
	Libft/ft_lstclear.c \
	Libft/ft_lstdelone.c \
	Libft/ft_lstiter.c \
	Libft/ft_lstlast.c \
	Libft/ft_lstnew.c \
	Libft/ft_lstsize.c \
	Libft/ft_putchar_fd.c \
	Libft/ft_putnbr_fd.c \
	Libft/ft_putstr_fd.c \
	Libft/ft_split.c \
	Libft/ft_strchr.c \
	Libft/ft_strdup.c \
	Libft/ft_strjoin.c \
	Libft/ft_strlen.c \
	Libft/ft_strncmp.c \
	Libft/ft_strrchr.c \
	Libft/ft_substr.c\
	next_line/get_next_line.c \
	next_line/get_next_line_utils.c \
	$(SRCS2)



OBJS = $(SRCS:.c=.o)
NAME = cub3d

all: $(NAME)

start: all clean
	./cub3d input2.cub

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MLX_FLAG) $(OBJS) $(LDFLAGS) $(LIBS_TO_LINK) -o $(NAME)

%.o: %.c include/cub.h include/ex_cub.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
