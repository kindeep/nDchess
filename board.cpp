//
// Created by Kindeep Singh Kargil on 2019-04-23.
//

#include "board.h"
#include <cmath>
#include <iostream>

board::~board() = default;

board::board(int dimension) {
    this->space_dimension = dimension;

    int num_elements = (int) std::pow(space_size, dimension);

    this->board_data = std::vector<int>();
}

board::board(int dimension, std::vector<int> array) {
    this->space_dimension = dimension;
    for (int elem: array) {
        this->board_data.push_back(elem);
    }
}

int board::get(coordinate c) {
    int actCoord[space_dimension];

    for (int index = 0; index < space_dimension; index++) {
        actCoord[index] = c.get(index);
    }

    int linear_location = 0;

    for (int i = space_dimension - 1; i >= 0; i--) {
        // traversing through coordinates backwards
        linear_location += actCoord[i] * (int) pow(8, i);
    }

    return board_data[linear_location];
}

void board::set(coordinate c, int value) {
    int actCoord[space_dimension];

    for (int index = 0; index < space_dimension; index++) {
        actCoord[index] = c.get(index);
    }
    // actCoordinate is now a point in (space_dimension)al space.
    // missing vals in a been replaced with 0, and extra values ignored.
}

std::string board::board_as_string() {

    std::string result;

    int lbreak = 0;
    for (int val: board_data) {
        if (lbreak >= space_size) {
            std::cout << "Whaaat" << std::endl;
            result += '\n';
            lbreak = 0;
        };
        result += " " + piece_as_string(val) + " ";
        lbreak++;
    }

    return result;
}

std::string board::piece_as_string(int piece) {
    std::string rep;
    switch (piece) {
        case QUEEN_B:
            rep = "QUB";
            break;
        case KING_B:
            rep = "KIB";
            break;
        case ROOK_B:
            rep = "RKB";
            break;
        case BISHOP_B:
            rep = "BIB";
            break;
        case PAWN_B:
            rep = "PWB";
            break;
        case KNIGHT_B:
            rep = "KNB";
            break;
        case QUEEN_W:
            rep = "QUW";
            break;
        case KING_W:
            rep = "KIW";
            break;
        case ROOK_W:
            rep = "RKW";
            break;
        case BISHOP_W:
            rep = "BIW";
            break;
        case PAWN_W:
            rep = "PWW";
            break;
        case KNIGHT_W:
            rep = "KNW";
            break;
        case EMPTY:
            rep = "XXX";
            break;
        default:
            rep = "???";
    }
    return rep;

}
