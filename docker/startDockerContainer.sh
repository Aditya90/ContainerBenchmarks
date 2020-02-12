#!/bin/bash

# Stop and remove the container
docker-compose stop dev-container
docker rm dev-container

# Rebuild the container if necessary and bring it up
docker-compose up --build -d

# Attach to the container through an interactive bash shell
docker exec -it dev-container /bin/bash