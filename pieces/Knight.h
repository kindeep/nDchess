//
// Created by Kindeep Singh Kargil on 2019-08-04.
//

#ifndef NDCHESS_KNIGHT_H
#define NDCHESS_KNIGHT_H


#include "../coordinate.h"
#include "../board.h"

class Knight {
public:
    static bool check_valid_move(board &_board, coordinate start, coordinate end);

    static std::vector<coordinate> get_valid_moves(int piece, coordinate pos);
};


#endif //NDCHESS_KNIGHT_H
