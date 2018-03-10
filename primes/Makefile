NAME=primes
TMP=tmp
CC=clang++
FLAGS=--std=c++11 -fno-exceptions
SRC=src/$(NAME).cpp

all: link
	@./$(NAME)

link: compile
	@$(CC) $(FLAGS) $(TMP)/$(NAME).o $(TMP)/sieve.o -o $(NAME)

compile: clean
	@mkdir -p $(TMP)
	@$(CC) $(FLAGS) -c $(SRC) -o $(TMP)/$(NAME).o
	@$(CC) $(FLAGS) -c src/headers/sieve.cpp -o $(TMP)/sieve.o


.PHONY: clean
clean: 
	@rm -rf $(TMP)

.PHONY: val
val: compile
	@valgrind -v ./$(NAME)

.PHONY: gt
gt: clean
	@git reset
	@git add *