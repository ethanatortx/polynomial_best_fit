CC = g++
CFLAGS = -std=c++14
SRCS = utility\string_utility.cpp csv\csv.cpp hash\md5.cpp math\prime.cpp main.cpp

main.o: $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o main.o

clean:
	Del "main.o"