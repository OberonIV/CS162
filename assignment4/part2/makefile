CC=g++ -std=c++11 -g
exe=stairs

# Complete the makefile
# Your code here: 
all: $(exe)

$(exe): stairs.o recurse.cpp
	$(CC) stairs.o recurse.cpp -o $(exe)

stairs.o: stairs.h stairs.cpp
	$(CC) -c stairs.cpp

clean:
	rm -f *.o $(exe)
