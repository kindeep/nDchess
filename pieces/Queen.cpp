//
// Created by Kindeep Singh Kargil on 2019-08-04.
//

#include "Queen.h"
#include "Bishop.h"
#include "Rook.h"

bool Queen::check_valid_move(board &_board, coordinate start, coordinate end) {
    return Bishop::check_valid_move(_board, start, end) || Rook::check_valid_move(_board, start, end);
}

std::vector<coordinate> Queen::get_valid_moves(int piece, coordinate pos) {
    return std::vector<coordinate>();
}
