//
// Created by Kindeep Singh Kargil on 2019-08-04.
//

#include "Rook.h"

bool Rook::check_valid_move(board &_board, coordinate start, coordinate end) {
    // change any one

    bool changed = false;

    for (int d = 0; d < start.dim(); d++) {
        int cs = start.get(d);
        int ce = end.get(d);

        if (abs(cs - ce) > 0) {
            if (changed) {
                return false;
            } else {
                changed = true;
            }
        }
    }

    return true;
}

std::vector<coordinate> Rook::get_valid_moves(int piece, coordinate pos) {
    return std::vector<coordinate>();
}