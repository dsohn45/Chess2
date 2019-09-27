#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Game.h"
#include "ChessGame.h"
#include "Prompts.h"




// Set up the chess board with standard initial pieces
ChessGame::ChessGame(): Game() {
    initialize_factories();
    std::vector<int> pieces {
        ROOK_ENUM, KNIGHT_ENUM, BISHOP_ENUM, QUEEN_ENUM,
        KING_ENUM, BISHOP_ENUM, KNIGHT_ENUM, ROOK_ENUM
    };
    for (size_t i = 0; i < pieces.size(); ++i) {
        init_piece(PAWN_ENUM, WHITE, Position(i, 1));
        init_piece(pieces[i], WHITE, Position(i, 0));
        init_piece(pieces[i], BLACK, Position(i, 7));
        init_piece(PAWN_ENUM, BLACK, Position(i, 6));
    }
}


// Set up the chess board with game state loaded from file
ChessGame::ChessGame(const std::string) : Game() {

    initialize_factories();

    // Add code here to collect piece information from file
    // and call init_piece as needed to create and place each one
    // (see the no-argument constructor for appropriate syntax)

}


// Perform a move from the start Position to the end Position                                
// The method returns an integer with the status                                             
// >= 0 is SUCCESS, < 0 is failure                                                           
int ChessGame::make_move(Position start, Position end) {

    return SUCCESS; 

}


// Report whether the chess game is over                                                    
bool ChessGame::game_over() const {

  return false; 

}


// Prepare the game to create pieces to put on the board
void ChessGame::initialize_factories() {

    // Add all factories needed to create Piece subclasses
    add_factory(new PieceFactory<Pawn>(PAWN_ENUM));
    add_factory(new PieceFactory<Rook>(ROOK_ENUM));
    add_factory(new PieceFactory<Knight>(KNIGHT_ENUM));
    add_factory(new PieceFactory<Bishop>(BISHOP_ENUM));
    add_factory(new PieceFactory<Queen>(QUEEN_ENUM));
    add_factory(new PieceFactory<King>(KING_ENUM));
}




