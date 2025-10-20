CC = cc
CFLAGS = -Wall -Werror -Wextra -Iinclude #-fsanitize=address -g3
MLX_FLAG = -lmlx -framework OpenGL -framework AppKit -lm
SRCS2 = \
	mandatory/rendring/start.c\
	mandatory/rendring/draw.c\
	mandatory/rendring/object.c\
	mandatory/rendring/player.c\
	mandatory/rendring/view.c\
	mandatory/rendring/mlx_inputs.c\
	mandatory/rendring/movement.c\
	mandatory/rendring/helper.c\
	mandatory/rendring/drawing_wall.c\
	mandatory/texture/load_text.c\
	mandatory/texture/load_texture_utils1.c\
	mandatory/texture/load_texture_utils2.c\
	mandatory/rendring/intersect.c

SRCS = \
	mandatory/main.c \
	mandatory/pars/parsing.c \
	mandatory/pars/parsing_helper.c \
	mandatory/pars/utils1.c \
	mandatory/pars/utils2.c \
	mandatory/pars/utils2_helper.c \
	mandatory/pars/utils3.c \
	mandatory/pars/utils4.c \
	mandatory/pars/utils5.c \
	mandatory/Libft/ft_atoi.c \
	mandatory/Libft/ft_alpha.c \
	mandatory/Libft/ft_lstadd_back.c \
	mandatory/Libft/ft_lstclear.c \
	mandatory/Libft/ft_lstdelone.c \
	mandatory/Libft/ft_lstiter.c \
	mandatory/Libft/ft_lstlast.c \
	mandatory/Libft/ft_lstnew.c \
	mandatory/Libft/ft_lstsize.c \
	mandatory/Libft/ft_putchar_fd.c \
	mandatory/Libft/ft_putnbr_fd.c \
	mandatory/Libft/ft_putstr_fd.c \
	mandatory/Libft/ft_split.c \
	mandatory/Libft/ft_strchr.c \
	mandatory/Libft/ft_strdup.c \
	mandatory/Libft/ft_strjoin.c \
	mandatory/Libft/ft_strlen.c \
	mandatory/Libft/ft_strncmp.c \
	mandatory/Libft/ft_strrchr.c \
	mandatory/Libft/ft_substr.c\
	mandatory/next_line/get_next_line.c \
	mandatory/next_line/get_next_line_utils.c \
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
