#include "ChessPiece.h"

int Pawn::valid_move_shape(Position start, Position end, std::vector<Position>& trajectory) const {
	return success
}

int Rook::valid_move_shape(Position start, Position end, std::vector<Position>& trajectory) const {
	
	if (start.x == end.x && start.y != end.y) {
		return SUCCESS;
	}
	if (start.x != end.x && start.y == end.y) {
		return SUCCESS;
	}
	return MOVE_ERROR_ILLEGAL;
}

int Knight::valid_move_shape(Position start, Position end, std::vector<Position>& trajectory) const {
	return success
}

int Bishop::valid_move_shape(Position start, Position end, std::vector<Position>& trajectory) const {
	diffx = abs(start.x - end.x);
	diffy = abs(start.y - end.y);

	if (diffx == diffy) {
		return SUCCESS;
	}
	return MOVE_ERROR_ILLEGAL;
}

int Queen::valid_move_shape(Position start, Position end, std::vector<Position>& trajectory) const {
	return success
}

int King::valid_move_shape(Position start, Position end, std::vector<Position>& trajectory) const {
	diffx = abs(start.x - end.x)
	diffy = abs(start.y - end.y)

	if ((diffx == 1 || diffx == 0) && (diffy == 1 || diffy == 0)){
		if (!(diffx == 0 && diffy == 0)) {
			return SUCESS;
		}
	}
	return MOVE_ERROR_ILLEGAL;
}

