#include <iostream>
#include <cassert>
#include <cctype>

#include "Game.h"
#include "Prompts.h"
#include "Piece.h"

Game::~Game() {

    // Delete the factories used to generate pieces
    for (size_t i = 0; i < _registered_factories.size(); i++) {
        delete _registered_factories[i];
    }

    // Delete any other dynamically-allocated resources here



}

// Create a Piece on the board using the appropriate factory.
// Returns true if the piece was successfully placed on the board.
bool Game::init_piece(int piece_type, Player owner, Position pos) {
    Piece* piece = new_piece(piece_type, owner);
    if (!piece) return false;

    // Fail if the position is out of bounds
    if (!valid_position(pos)) {
        Prompts::out_of_bounds();
        return false;
    }

    // Fail if the position is occupied
    if (get_piece(pos)) {
        Prompts::blocked();
        return false;
    }
    _pieces[index(pos)] = piece;
    return true;
}

// Get the Piece at a specified Position.  Returns nullptr if no
// Piece at that Position or if Position is out of bounds.
Piece* Game::get_piece(Position pos) const {
    if (valid_position(pos))
        return _pieces[index(pos)];
    else {
        Prompts::out_of_bounds();
        return nullptr;
    }
}


// Perform a move from the start Position to the end Position
// The method returns an integer status where a value
// >= 0 indicates SUCCESS, and a < 0 indicates failure
int Game::make_move(Position start, Position end) {

  return 0;

}


// Execute the main gameplay loop.
void Game::run() {

    

}

void Game::board() const{
  




// Search the factories to find a factory that can translate
//`piece_type' into a Piece, and use it to create the Piece.
// Returns nullptr if factory not found.
Piece* Game::new_piece(int piece_type, Player owner) {

    PieceGenMap::iterator it = _registered_factories.find(piece_type);

    if (it == _registered_factories.end()) { // not found
        std::cout << "Piece type " << piece_type << " has no generator\n";
        return nullptr;
    } else {
        return it->second->new_piece(owner);
    }
}



// Add a factory to the Board to enable producing
// a certain type of piece. Returns whether factory
// was successfully added or not.
bool Game::add_factory(AbstractPieceFactory* piece_gen) {
    // Temporary piece to get the ID
    Piece* p = piece_gen->new_piece(WHITE);
    int piece_type = p->piece_type();
    delete p;

    PieceGenMap::iterator it = _registered_factories.find(piece_type);
    if (it == _registered_factories.end()) { // not found, so add it
        _registered_factories[piece_type] = piece_gen;
        return true;
    } else {
        std::cout << "Piece type " << piece_type << " already has a generator\n";
        return false;
    }
}

