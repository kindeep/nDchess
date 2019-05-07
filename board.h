//
// Created by Kindeep Singh Kargil on 2019-04-23.
//

#ifndef NDCHESS_BOARD_H
#define NDCHESS_BOARD_H

#include "coordinate.h"
#include <array>
#include <vector>
#include <string>

enum PIECES {
    EMPTY, KING_W, QUEEN_W, ROOK_W, BISHOP_W, PAWN_W, KNIGHT_W, KING_B, QUEEN_B, ROOK_B, BISHOP_B, PAWN_B, KNIGHT_B
};

/**
 *
 */
class board {
private:
    std::vector<int> board_data; // board_data that stores the state for all points in the space.
    int space_dimension;
    int space_size = 8;
public:
    /**
     * Creates a default chessboard with the given dimensions
     *
     * @param dimension
     */
    board(int dimension);

    /**
     * creates a chessboard with the given board specifcation.
     *
     * @param dimension
     * @param array
     */
    board(int dimension, std::vector<int> array);

    /**
     *
     */
    ~board();

    /**
     * get piece in space at coordinate. Assumes undefined coords as zero, and ignores extra dimensional values.
     *
     * @param c
     */
    int get(coordinate c);

    /**
     * set's the status of coordinate in the 3d grid.
     *
     * @param c
     * @param value
     */
    void set(coordinate c, int value);

    std::string board_as_string();

    std::string piece_as_string(int piece);

};

#endif //NDCHESS_BOARD_H
