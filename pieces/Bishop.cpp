//
// Created by Kindeep Singh Kargil on 2019-08-04.
//

#include "Bishop.h"

template<typename T>
int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

bool Bishop::check_valid_move(board &_board, coordinate start, coordinate end) {
    int dimension = start.dim();
    int known_diff = -1;
    int num_diff = 0;
    std::vector<bool> changed;
    changed.reserve(dimension);
    std::vector<int> changed_sign;
    changed_sign.reserve(dimension);
    for (int i = 0; i < start.dim(); i++) {
        int cs = start.get(i);
        int ce = end.get(i);

        if (ce - cs != 0) {
            // found diff
            if (known_diff == -1) {
                known_diff = std::abs(ce - cs);
            } else if (known_diff != std::abs(ce - cs)) {
                // some other diff than known found
                return false;
            }
            changed[i] = true;
            changed_sign[i] = sgn(ce - cs);
            num_diff++;
        }
    }

    if (num_diff < 2) {
        return false;
    }

    // gotta replace all these with copy constructors idk why i'm doing this
    coordinate start_copy = coordinate(start.vals());

    for (int curr_diff = 1; curr_diff < known_diff; curr_diff++) {
        for (int i = 0; i < dimension; i++) {
            if (changed[i]) {
                start_copy.set(i, start.get(i) + (changed_sign[i] * curr_diff));
            }
        }
        if (_board.isOccupied(start_copy)) return false;
    }

    return !_board.isOccupied(end) ||_board.opponentPieces(start, end);
}

std::vector<coordinate> Bishop::get_valid_moves(int piece, coordinate pos) {
    return std::vector<coordinate>();
}
