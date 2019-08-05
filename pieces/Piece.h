//
// Created by Kindeep Singh Kargil on 2019-08-04.
//

#ifndef NDCHESS_PIECE_H
#define NDCHESS_PIECE_H


#include "../coordinate.h"
#include "../board.h"
#include <cmath>

class Piece {
public:
    /**
     * Only checks if the piece can move by that much.
     * Does not account for if the end is occupied
     *
     * @param start
     * @param end
     * @return
     */
    static bool check_valid_move(board &_board, coordinate start, coordinate end);

    static std::vector<coordinate> get_valid_moves(int piece, coordinate pos);
};


#endif //NDCHESS_PIECE_H
