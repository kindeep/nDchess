//
// Created by Kindeep Singh Kargil on 2019-08-04.
//

#include "Rook.h"

bool Rook::check_valid_move(board &_board, coordinate start, coordinate end) {
    // change any one

    bool changed = false;
    int change_index = -1;

    for (int d = 0; d < start.dim(); d++) {
        int cs = start.get(d);
        int ce = end.get(d);

        if (abs(cs - ce) > 0) {
            if (changed) {
                return false;
            } else {
                changed = true;
                change_index = d;
            }
        }
    }

    // at this point, the move is valid. just check if something is in the way.

    int cfrom = start.get(change_index);
    int cto = start.get(change_index);


    coordinate crd_copy = coordinate(start.vals());
    for (int i = std::min(cfrom, cto) + 1; i < std::max(cfrom, cto); i++) {
        crd_copy.set(change_index, i);
        if (_board.isOccupied(crd_copy)) {
            return false;
        }
    }

    // we know the boxes in the way are not occupied. now need to check if the box at the end is opponent or empty

    return !_board.isOccupied(end) || _board.opponentPieces(start, end);
}

std::vector<coordinate> Rook::get_valid_moves(int piece, coordinate pos) {
    return std::vector<coordinate>();
}