//
// Created by Kindeep Singh Kargil on 2019-08-04.
//

#ifndef NDCHESS_PAWN_H
#define NDCHESS_PAWN_H


#include "Piece.h"

class Pawn : Piece {
public:
    static bool check_valid_move(board &_board, coordinate start, coordinate end);

    static std::vector<coordinate> get_valid_moves(int piece, coordinate pos);
};


#endif //NDCHESS_PAWN_H
