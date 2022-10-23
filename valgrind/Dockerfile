# GCC support can be specified at major, minor, or micro version
# (e.g. 8, 8.2 or 8.2.0).
# See https://hub.docker.com/r/library/gcc/ for all supported GCC
# tags from Docker Hub.
# See https://docs.docker.com/samples/library/gcc/ for more on how to use this image
FROM debian:stretch


# Update package manager
RUN apt-get update
RUN apt-get upgrade -y

# Has stuff like gcc, make, and libc6-dev
RUN apt-get install -y build-essential

# Valgrind!
RUN apt-get install -y valgrind

# These commands copy your files into the specified directory in the image
# and set that as the working location
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp

# This command compiles your app using GCC, adjust for your source code
RUN g++ -o myapp main.cpp
RUN valgrind --leak-check=full ./myapp

LABEL Name=mosze Version=0.0.1

