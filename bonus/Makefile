CC = cc
CFLAGS = -Wall -Werror -Wextra -Iinclude #-fsanitize=address -g3
MLX_FLAG = -lmlx -framework OpenGL -framework AppKit -lm
SRCS2 = \
	bonus/rendring/start.c\
	bonus/rendring/draw.c\
	bonus/rendring/object.c\
	bonus/rendring/player.c\
	bonus/rendring/view.c\
	bonus/rendring/mlx_inputs.c\
	bonus/rendring/movement.c\
	bonus/rendring/helper.c\
	bonus/rendring/drawing_wall.c\
	bonus/texture/load_text.c\
	bonus/texture/load_texture_utils1.c\
	bonus/texture/load_texture_utils2.c\
	bonus/texture/load_text_utils.c\
	bonus/rendring/intersect.c\
	bonus/rendring/bonus_events.c

SRCS = \
	bonus/main.c \
	bonus/pars/parsing.c \
	bonus/pars/parsing_helper.c \
	bonus/pars/utils1.c \
	bonus/pars/utils2.c \
	bonus/pars/utils2_helper.c \
	bonus/pars/utils3.c \
	bonus/pars/utils4.c \
	bonus/pars/utils5.c \
	bonus/Libft/ft_atoi.c \
	bonus/Libft/ft_alpha.c \
	bonus/Libft/ft_lstadd_back.c \
	bonus/Libft/ft_lstclear.c \
	bonus/Libft/ft_lstdelone.c \
	bonus/Libft/ft_lstiter.c \
	bonus/Libft/ft_lstlast.c \
	bonus/Libft/ft_lstnew.c \
	bonus/Libft/ft_lstsize.c \
	bonus/Libft/ft_putchar_fd.c \
	bonus/Libft/ft_putnbr_fd.c \
	bonus/Libft/ft_putstr_fd.c \
	bonus/Libft/ft_split.c \
	bonus/Libft/ft_strchr.c \
	bonus/Libft/ft_strdup.c \
	bonus/Libft/ft_strjoin.c \
	bonus/Libft/ft_strlen.c \
	bonus/Libft/ft_strncmp.c \
	bonus/Libft/ft_strrchr.c \
	bonus/Libft/ft_substr.c\
	bonus/next_line/get_next_line.c \
	bonus/next_line/get_next_line_utils.c \
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
