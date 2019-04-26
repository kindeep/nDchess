//
// Created by Kindeep Singh Kargil on 2019-04-23.
//

#include "board.h"
#include <cmath>

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

    /*
     * space_size * space_dimension places.
     *
     * go to space_dimensional coordinate * (space_size * (space_dimension -1)
     */

    for (int i = space_dimension - 1; i >= 0; i--) {
        // traversing through coordinates backwards




    }

    // actCoordinate is now a point in (space_dimension)al space.
    // missing vals in a been replaced with 0, and extra values ignored.
}

void board::set(coordinate c, int value) {
    int actCoord[space_dimension];

    for (int index = 0; index < space_dimension; index++) {
        actCoord[index] = c.get(index);
    }

    // actCoordinate is now a point in (space_dimension)al space.
    // missing vals in a been replaced with 0, and extra values ignored.

}
