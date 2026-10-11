FROM ubuntu:16.04

RUN apt update 
RUN apt install -y g++

WORKDIR /usr/src/helloworld

COPY ./helloworld.cpp .

RUN g++ helloworld.cpp -o helloworld

CMD ["./helloworld"]