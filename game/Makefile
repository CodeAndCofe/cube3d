NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -O2 -Iinclude
MLX42_DIR ?= MLX42
MLX42_LIB ?= $(MLX42_DIR)/build/libmlx42.a

ifeq ($(wildcard $(MLX42_DIR)/include/MLX42/MLX42.h),)
$(error MLX42 not found. Run 'git clone https://github.com/codam-coding-college/MLX42.git MLX42 && cmake -S MLX42 -B MLX42/build && cmake --build MLX42/build -j4', or set MLX42_DIR)
endif

CFLAGS += -I$(MLX42_DIR)/include

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
MLX_FLAGS ?= $(MLX42_LIB) -lglfw -framework Cocoa -framework OpenGL -framework IOKit
else
MLX_FLAGS ?= $(MLX42_LIB) -ldl -lglfw -pthread -lm -lGL
endif

SRCS = \
	src/main.c \
	$(filter-out src/Libft/ft_lst%.c,$(wildcard src/Libft/*.c)) \
	$(wildcard src/next_line/*.c) \
	$(wildcard src/pars/*.c) \
	$(wildcard src/rendring/*.c) \
	$(wildcard src/texture/*.c)

OBJS = $(SRCS:.c=.o)
HEADERS = include/cub.h include/ex_cub.h

DOCKER_IMAGE = cub3d:latest

.PHONY: all clean fclean re docker-build docker-run docker-clean

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

docker-build:
	docker build -f docker/Dockerfile -t $(DOCKER_IMAGE) .

docker-run: docker-build
	sh docker/run.sh

docker-clean:
	docker image rm $(DOCKER_IMAGE)
