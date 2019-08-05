//
// Created by Kindeep Singh Kargil on 2019-08-04.
//

#ifndef NDCHESS_BISHOP_H
#define NDCHESS_BISHOP_H


#include "../coordinate.h"
#include "../board.h"

class Bishop {
public:
    static bool check_valid_move(board &_board, coordinate start, coordinate end);

    static std::vector<coordinate> get_valid_moves(int piece, coordinate pos);
};


#endif //NDCHESS_BISHOP_H
