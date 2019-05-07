#include <iostream>
#include <array>
#include "board.h"
#include <string>

int main() {
    std::cout << "n Dimensional chess" << std::endl;


    board aBoard = board(1,
                         {KING_B, PAWN_B, EMPTY, EMPTY, EMPTY, EMPTY, PAWN_W, KING_W});


//    std::cout << aBoard.get(coordinate({1})) << std::endl;
    std::cout << aBoard.board_as_string() << std::endl;

    board nml_cboard = board(1,
                             {
                                     ROOK_B, PAWN_B, EMPTY, EMPTY, EMPTY, EMPTY, PAWN_W, ROOK_W,
                                     KNIGHT_B, PAWN_B, EMPTY, EMPTY, EMPTY, EMPTY, PAWN_W, KNIGHT_W,
                                     BISHOP_B, PAWN_B, EMPTY, EMPTY, EMPTY, EMPTY, PAWN_W, BISHOP_W,
                                     QUEEN_B, PAWN_B, EMPTY, EMPTY, EMPTY, EMPTY, PAWN_W, QUEEN_W,
                                     KING_B, PAWN_B, EMPTY, EMPTY, EMPTY, EMPTY, PAWN_W, KING_W,
                                     BISHOP_B, PAWN_B, EMPTY, EMPTY, EMPTY, EMPTY, PAWN_W, BISHOP_W,
                                     KNIGHT_B, PAWN_B, EMPTY, EMPTY, EMPTY, EMPTY, PAWN_W, KNIGHT_W,
                                     ROOK_B, PAWN_B, EMPTY, EMPTY, EMPTY, EMPTY, PAWN_W, ROOK_W,
                             });

    std::cout << nml_cboard.board_as_string() << std::endl;

    return 0;
}