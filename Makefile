CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11 -g

play: Play.o Game.o ChessGame.o
	$(CXX) Play.o Game.o ChessGame.o -o play

Play.o: Play.cpp Game.h ChessGame.h Prompts.h
	$(CXX) $(CXXFLAGS) -c Play.cpp

Game.o: Game.cpp Game.h Piece.h Prompts.h Enumerations.h Terminal.h
	$(CXX) $(CXXFLAGS) -c Game.cpp

ChessGame.o: ChessGame.cpp Game.h ChessGame.h Piece.h ChessPiece.h Prompts.h Enumerations.h
	$(CXX) $(CXXFLAGS) -c ChessGame.cpp


clean:
	rm *.o play

