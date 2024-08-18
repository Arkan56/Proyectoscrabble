FROM gcc
WORKDIR /usr/src/project
COPY . .
RUN g++ -std=c++11 -o scrabble main.cpp
CMD ["./scrabble"]