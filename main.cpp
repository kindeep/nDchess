#include <iostream>
#include <array>
#include "board.h"
#include <string>

int main() {
    std::cout << "n Dimensional chess" << std::endl;

    board aBoard = board(1, {KING_B, PAWN_B, EMPTY, EMPTY, EMPTY, EMPTY, PAWN_W, KING_W});

    std::cout << aBoard.board_as_string() << std::endl;

    board nml_cboard = board(2,
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

    //    board test_default = board(2);
//    std::cout << "Default 2 dim" << std::endl;
//    std::cout << test_default.board_as_string() << std::endl;
//
//    board test_default_3 = board(3);
//    std::cout << "Default 3 dim" << std::endl;
//    std::cout << test_default_3.board_as_string() << std::endl;
//
//    board test_default_4 = board(4);
//    std::cout << "Default 3 dim" << std::endl;
//    std::cout << test_default_4.board_as_string() << std::endl;

//    board test_default_11 = board(9);
//    std::cout << "Default 11 dim" << std::endl;
//    std::cout << test_default_11.board_as_string() << std::endl;


    for (int dim = 1; dim < 5; dim++) {
        board test_board = board(dim);
        std::cout << dim << "-D Chess Board" << std::endl;
        std::cout << test_board.board_as_string() << std::endl;
    }

    return 0;
}