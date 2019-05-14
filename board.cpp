//
// Created by Kindeep Singh Kargil on 2019-04-23.
//

#include "board.h"

board::~board() = default;

board::board(int dimension) {
    this->space_dimension = dimension;

    int num_elements = (int) std::pow(space_size, dimension);

    this->board_data = std::vector<int>();

    for (int i = 0; i < pow(space_size, dimension); i++) {
        board_data.push_back(EMPTY);
    }

    setAll(coordinate({1}, 1), PAWN_W);
    setAll(coordinate({6}, 1), PAWN_B);

    setAll(coordinate({0, 0}, 2), ROOK_W);
    setAll(coordinate({0, 7}, 2), ROOK_W);
    setAll(coordinate({7, 0}, 2), ROOK_B);
    setAll(coordinate({7, 7}, 2), ROOK_B);

    setAll(coordinate({0, 1}, 2), KNIGHT_W);
    setAll(coordinate({0, 6}, 2), KNIGHT_W);
    setAll(coordinate({7, 1}, 2), KNIGHT_B);
    setAll(coordinate({7, 6}, 2), KNIGHT_B);

    setAll(coordinate({0, 2}, 2), BISHOP_W);
    setAll(coordinate({0, 5}, 2), BISHOP_W);
    setAll(coordinate({7, 2}, 2), BISHOP_B);
    setAll(coordinate({7, 5}, 2), BISHOP_B);

    setAll(coordinate({0, 3}, 2), QUEEN_W);
    setAll(coordinate({0, 4}, 2), QUEEN_W);
    setAll(coordinate({7, 3}, 2), QUEEN_B);
    setAll(coordinate({7, 4}, 2), QUEEN_B);

    std::vector<int> king_w = {0, 4};
    std::vector<int> king_b = {7, 4};

    for (int i = 0; i < dimension - 2; i++) {
        king_w.push_back(0);
        king_b.push_back(7);
    }

    coordinate king_w_coord = coordinate(king_w, dimension);
    coordinate king_b_coord = coordinate(king_b, dimension);

//    set(coordinate({0, 4}), KING_W);
    set(king_w_coord, KING_W);
    set(king_b_coord, KING_B);

//    setAll({2}, PAWN_B);
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

    int linear_location = 0;

    for (int i = space_dimension - 1; i >= 0; i--) {
        // traversing through coordinates backwards
        linear_location += actCoord[i] * (int) pow(8, i);
    }

    board_data[linear_location] = value;
}

std::string board::board_as_string() {
    std::string result;

    int lbreak = 0;
    for (int val: board_data) {
        if (lbreak >= space_size) {
            result += '\n';
            lbreak = 0;
        };
        result += " " + piece_as_string(val) + " ";
        lbreak++;
    }

    return result + "\n";
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

void board::setAll(int dim, int pos, int val) {

}

void board::foreach_c(coordinate crd_ltr, void (*f)(coordinate)) {
    coordinate inc = space_dimension - crd_ltr.dim();

    while (inc.has_next_inc()) {
        coordinate curr = coordinate::add(crd_ltr, inc);
        f(curr);
        ++inc;
    }
}

// crd_ltr - coordinate left to right...
// coordinates that will be set: [ltr, , , , ]
// all iterations keeping ltr and dimension fixed.
void board::setAll(coordinate crd_ltr, int val) {
    coordinate a_coord = coordinate(space_dimension - crd_ltr.dim());
//    std::cout <<  "LTR: " << crd_ltr.to_string() << std::endl;
    for (int i = 0; i < pow(space_size, a_coord.dim()); i++) {
        coordinate curr = coordinate::add(crd_ltr, a_coord);
//        std::cout << i << " " + a_coord.to_string() << std::endl;
//        std::cout << i << " " + curr.to_string() << std::endl;
        set(curr, val);
        ++a_coord;

    }
}
