#include "ChessPiece.h"
int abs(int x) {
	if (x < 0) {
		return -x;
	} else {
		return x;
	}
}

int Pawn::valid_move_shape(Position start, Position end, std::vector<Position>& trajectory) const {
	return success
}

int Rook::valid_move_shape(Position start, Position end, std::vector<Position>& trajectory) const {
	
	if (start.x == end.x && start.y != end.y) {
		if (start.y > end.y) {
			move = -1;
		} else {
			move = 1;
		}
		curr = start.y;
		while (curr != end.y) {
			trajectory.push_back(Position(start.x, curr));
		}
		return SUCCESS;
	}

	if (start.x != end.x && start.y == end.y) {
		if (start.x > end.x) {
			move = -1;
		} else {
			move = 1;
		}
		curr = start.x;
		while (curr != end.x) {
			curr += move;
			trajectory.push_back(Position(start.x, curr));	
		}
		return SUCCESS;
	}
	return MOVE_ERROR_ILLEGAL;
}

int Knight::valid_move_shape(Position start, Position end, std::vector<Position>& trajectory) const {
	if (abs(end.x - start.x) == 2 && abs(end.y - start.y) == 1 || 
		abs(end.x - start.x) == 1 && abs(end.y - start.y) == 2) {
		trajectory.push_back(end);
		return 1;
	} else {
		return 0
	}
}

int Bishop::valid_move_shape(Position start, Position end, std::vector<Position>& trajectory) const {
	diffx = abs(start.x - end.x);
	diffy = abs(start.y - end.y);

	if (diffx == diffy) {

		int move_x = 1;
		int move_y = 1; 

		if (end.x < start.x) {
			move_x = -1
		} else if (end.x == start.x) {
			move_x = 0;
		}

		if (end.y < start.y) {
			move_y = -1;
		} else if (end.y == start.y) {
			move_y = 0;
		}

		int curr_x = start.x + move_x;
		int curr_y = start.y + move_y;

		while(curr_x != end.x && curr_y != end.y) {
			trajectory.push_back(Position(curr_x, curr_y));
			curr_x += move_x;
			curr_y += move_y;
		} 

		return SUCCESS;
	}
	return MOVE_ERROR_ILLEGAL;
}

int Queen::valid_move_shape(Position start, Position end, std::vector<Position>& trajectory) const {
	int move_x = 1;
	int move_y = 1; 

	if (end.x < start.x) {
		move_x = -1
	} else if (end.x == start.x) {
		move_x = 0;
	}

	if (end.y < start.y) {
		move_y = -1;
	} else if (end.y == start.y) {
		move_y = 0;
	}

	if (abs(end.x - start.x) > 0 && abs(end.y - start.y) == 0 || 
		abs(end.y - start.y) > 0 && abs(end.x - start.x) == 0 || 
		abs(end.y - start.y) == abs(end.x - start.x)) {
			
		int curr_x = start.x + move_x;
		int curr_y = start.y + move_y;

		while(curr_x != end.x && curr_y != end.y) {
			trajectory.push_back(Position(curr_x, curr_y));
			curr_x += move_x;
			curr_y += move_y;
		} 
		return 1;
	} else {
		return -1;
	}
}

int King::valid_move_shape(Position start, Position end, std::vector<Position>& trajectory) const {
	diffx = abs(start.x - end.x)
	diffy = abs(start.y - end.y)

	if ((diffx == 1 || diffx == 0) && (diffy == 1 || diffy == 0)){
		if (!(diffx == 0 && diffy == 0)) {
			trajectory.push_back(end)
			return SUCCESS;
		}
	}
	return MOVE_ERROR_ILLEGAL;
}
