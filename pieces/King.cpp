//
// Created by Kindeep Singh Kargil on 2019-08-04.
//

#include "King.h"

bool King::check_valid_move(board &_board, coordinate start, coordinate end) {
    // change any coord by at most one

    bool valid = true;

    for (int d = 0; d < start.dim(); d++) {
        int cs = start.get(d);
        int ce = end.get(d);

        if (abs(cs - ce) > 1) {
            valid = false;
            // ahh can just return false here tbh
            return false;
        }
    }

    if (_board.isOccupiedWhite(end)) {
        return valid && _board.isOccupiedBlack(start);
    } else if (_board.isOccupiedBlack(end)) {
        return valid && _board.isOccupiedWhite(end);
    } else {
        // not occupied
        return valid;
    }
}

std::vector<coordinate> King::get_valid_moves(int piece, coordinate pos) {
    return std::vector<coordinate>();
}
