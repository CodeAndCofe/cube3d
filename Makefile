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

B_SRCS2 = \
	bonus/rendring/start_bonus.c\
	bonus/rendring/draw_bonus.c\
	bonus/rendring/object_bonus.c\
	bonus/rendring/player_bonus.c\
	bonus/rendring/view_bonus.c\
	bonus/rendring/mlx_inputs_bonus.c\
	bonus/rendring/movement_bonus.c\
	bonus/rendring/helper_bonus.c\
	bonus/rendring/drawing_wall_bonus.c\
	bonus/texture/load_text_bonus.c\
	bonus/texture/load_texture_utils1_bonus.c\
	bonus/texture/load_texture_utils2_bonus.c\
	bonus/texture/load_text_utils_bonus.c\
	bonus/rendring/intersect_bonus.c\
	bonus/rendring/bonus_events_bonus.c

B_SRCS = \
	bonus/main_bonus.c \
	bonus/pars/parsing_bonus.c \
	bonus/pars/parsing_helper_bonus.c \
	bonus/pars/utils1_bonus.c \
	bonus/pars/utils2_bonus.c \
	bonus/pars/utils2_helper_bonus.c \
	bonus/pars/utils3_bonus.c \
	bonus/pars/utils4_bonus.c \
	bonus/pars/utils5_bonus.c \
	bonus/pars/utils6_bonus.c \
	bonus/Libft/ft_atoi_bonus.c \
	bonus/Libft/ft_alpha_bonus.c \
	bonus/Libft/ft_lstadd_back_bonus.c \
	bonus/Libft/ft_lstclear_bonus.c \
	bonus/Libft/ft_lstdelone_bonus.c \
	bonus/Libft/ft_lstiter_bonus.c \
	bonus/Libft/ft_lstlast_bonus.c \
	bonus/Libft/ft_lstnew_bonus.c \
	bonus/Libft/ft_lstsize_bonus.c \
	bonus/Libft/ft_putchar_fd_bonus.c \
	bonus/Libft/ft_putnbr_fd_bonus.c \
	bonus/Libft/ft_putstr_fd_bonus.c \
	bonus/Libft/ft_split_bonus.c \
	bonus/Libft/ft_strchr_bonus.c \
	bonus/Libft/ft_strdup_bonus.c \
	bonus/Libft/ft_strjoin_bonus.c \
	bonus/Libft/ft_strlen_bonus.c \
	bonus/Libft/ft_strncmp_bonus.c \
	bonus/Libft/ft_strrchr_bonus.c \
	bonus/Libft/ft_substr_bonus.c \
	bonus/next_line/get_next_line_bonus.c \
	bonus/next_line/get_next_line_utils_bonus.c \
	$(B_SRCS2)


B_OBJS = $(B_SRCS:.c=.o)
OBJS = $(SRCS:.c=.o)
NAME = cub3d
NAME_BONUS = cub3d_bonus
HEADER = include/cub.h
HEADER2 = include/ex_cub.h

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(MLX_FLAG) $(OBJS) $(LDFLAGS) $(LIBS_TO_LINK) -o $(NAME)

$(NAME_BONUS): $(B_OBJS)
	$(CC) $(CFLAGS) $(MLX_FLAG) $(B_OBJS) $(LDFLAGS) $(LIBS_TO_LINK) -o $(NAME_BONUS)

%.o: %.c $(HEADER) $(HEADER2)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all
