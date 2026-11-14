FROM ubuntu:24.04

RUN apt-get update && apt-get install -y --no-install-recommends \
	build-essential \
	cmake \
	git \
	libglfw3-dev \
	libgl1-mesa-dev \
	libx11-dev \
	libxext-dev \
	libxrandr-dev \
	libxi-dev \
	libxinerama-dev \
	ca-certificates \
	&& rm -rf /var/lib/apt/lists/*

WORKDIR /cub3d
COPY . .

RUN git clone --depth 1 https://github.com/codam-coding-college/MLX42.git MLX42 \
	&& cmake -S MLX42 -B MLX42/build \
	&& cmake --build MLX42/build -j"$(nproc)" \
	&& make

CMD ["./cub3D", "maps/map_bonus.cub"]
