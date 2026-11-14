#!/bin/sh

set -eu

if [ -z "${DISPLAY:-}" ]; then
	printf '%s\n' "DISPLAY is not set. Run this from an X11 desktop." >&2
	exit 1
fi
if ! command -v xhost >/dev/null 2>&1; then
	printf '%s\n' "xhost is required to run the MLX42 window." >&2
	exit 1
fi

xhost +local:docker >/dev/null
cleanup()
{
	xhost -local:docker >/dev/null 2>&1 || true
}
trap cleanup EXIT INT TERM

docker run --rm -it \
	-e DISPLAY="$DISPLAY" \
	-v /tmp/.X11-unix:/tmp/.X11-unix \
	cub3d:latest
