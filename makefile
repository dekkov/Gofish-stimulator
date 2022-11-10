CC=g++
EXE_FILE=gofish

all: $(EXE_FILE)

$(EXE_FILE): card.o deck.o hand.o player.o game.o card.h deck.h hand.h player.h game.h main.cpp 
	$(CC) card.o deck.o hand.o player.o game.o main.cpp -o $(EXE_FILE)

card.o: card.h card.cpp 
	$(CC) -c card.cpp

deck.o: deck.h card.h deck.cpp
	$(CC) -c deck.cpp 

hand.o: hand.h card.h hand.cpp
	$(CC) -c hand.cpp

player.o: player.h hand.h card.h player.cpp 
	$(CC) -c player.cpp 

game.o: game.h deck.h player.h card.h game.cpp 
	$(CC) -c game.cpp 

clean:
	rm -f *.o $(EXE_FILE)