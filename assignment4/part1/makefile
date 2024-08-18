CC=g++ -std=c++11 -g
exe=wumpus

# Complete the makefile
# Your code here: 
$(exe): event.o game.o gold.o pool.o room.o stalactites.o wumpus.o adventurer.o armor.o main.cpp
	$(CC) event.o game.o gold.o pool.o room.o stalactites.o wumpus.o adventurer.o armor.o main.cpp -lncurses -o $(exe)
	
event.o: event.cpp event.h
	$(CC) -c event.cpp event.h

game.o: game.cpp game.h
	$(CC) -c game.cpp game.h

room.o: room.cpp room.h 
	$(CC) -c room.cpp room.h
	
gold.o: gold.cpp gold.h 
	$(CC) -c gold.cpp gold.h 

pool.o: pool.cpp pool.h 
	$(CC) -c pool.cpp pool.h 

stalactites.o: stalactites.cpp stalactites.h 
	$(CC) -c stalactites.cpp stalactites.h 
	
wumpus.o: wumpus.cpp wumpus.h
	$(CC) -c wumpus.cpp wumpus.h 

adventurer.o: adventurer.cpp adventurer.h 
	$(CC) -c adventurer.cpp	adventurer.h 
	
armor.o: armor.cpp armor.h 
	$(CC) -c armor.cpp armor.h 

clean:
	rm -rf *.o *.gch $(exe)
	
leak-check:
	valgrind --leak-check=full ./$(exe)