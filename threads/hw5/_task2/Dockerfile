FROM ubuntu:22.04

RUN apt update
RUN apt install -y gcc cmake build-essential

WORKDIR /usr/src/server_queue

COPY server.cpp ./
COPY server.h ./
COPY task2_serv.cpp ./
COPY CMakeLists_serv.txt CMakeLists.txt

WORKDIR /usr/src/server_queue/build

RUN cmake ..
RUN make

CMD ["./server"]