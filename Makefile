DOCKER_IMAGE = cub3d:latest

.PHONY: docker-build docker-run docker-clean

docker-build:
	docker build -f Dockerfile -t $(DOCKER_IMAGE) .

docker-run: docker-build
	sh run_docker.sh

docker-clean:
	docker image rm $(DOCKER_IMAGE)
