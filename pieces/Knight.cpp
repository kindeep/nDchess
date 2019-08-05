//
// Created by Kindeep Singh Kargil on 2019-08-04.
//

#include "Knight.h"

bool Knight::check_valid_move(board &_board, coordinate start, coordinate end) {
    int change1 = 0;
    int change2 = 0;

    int dimensions = start.dim();

    for (int i = 0; i < dimensions; i++) {
        int cs = start.get(i);
        int ce = end.get(i);

        if (ce - cs != 0) {
            // there is a change
            // check if change is actually allowed
            if (change1 == 0) {
                if (std::abs(ce - cs) <= 2) {
                    change1 = ce - cs;
                } else {
                    return false;
                }
            } else {
                if (change2 == 0) {
                    if (std::abs(ce - cs) <= 2 && std::abs(ce - cs) != change1) {
                        change2 = ce - cs;
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }
    }

    if (change2 == 0 || change1 == 0) return false;

    return !_board.isOccupied(end) || _board.opponentPieces(start, end);
}

std::vector<coordinate> Knight::get_valid_moves(int piece, coordinate pos) {
    return std::vector<coordinate>();
}
