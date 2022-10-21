# GCC support can be specified at major, minor, or micro version
# (e.g. 8, 8.2 or 8.2.0).
# See https://hub.docker.com/r/library/gcc/ for all supported GCC
# tags from Docker Hub.
# See https://docs.docker.com/samples/library/gcc/ for more on how to use this image
FROM gcc:latest

# These commands copy your files into the specified directory in the image
# and set that as the working location
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp/

#RUN apt-get update
RUN apt-get update && apt-get install -y cmake libgtest-dev libboost-test-dev && rm -rf /var/lib/apt/lists/*
RUN apt-get update && apt-get install ninja-build

# This command compiles your app using GCC, adjust for your source code
RUN cmake . --debug-output -G Ninja
RUN cmake --build .
RUN apt-get update && apt-get install dos2unix
RUN dos2unix story.txt
RUN ctest -j10 -C Debug -T test --output-on-failure

# This command runs your application, comment out this line to compile only
#CMD ["./myapp"]

LABEL Name=mosze Version=0.0.1

