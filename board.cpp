//
// Created by Kindeep Singh Kargil on 2019-04-23.
//

#include "board.h"
#include "pieces/Piece.h"
#include "pieces/Pawn.h"
#include "pieces/Queen.h"
#include "pieces/King.h"
#include "pieces/Rook.h"
#include "pieces/Bishop.h"

board::~board() = default;

board::board(int dimension) {
    this->space_dimension = dimension;

    int num_elements = (int) std::pow(space_size, dimension);

    this->board_data = std::vector<int>();
    board_data.reserve((int) pow(space_size, dimension));
    for (int i = 0; i < pow(space_size, dimension); i++) {
        board_data.push_back(EMPTY);
    }

    // Initialize Pawns
    setAll(coordinate({1}, 1), PAWN_W);
    setAll(coordinate({6}, 1), PAWN_B);

    // Initialize Rooks
    setAll(coordinate({0, 0}, 2), ROOK_W);
    setAll(coordinate({0, 7}, 2), ROOK_W);
    setAll(coordinate({7, 0}, 2), ROOK_B);
    setAll(coordinate({7, 7}, 2), ROOK_B);

    // Initialize Knights
    setAll(coordinate({0, 1}, 2), KNIGHT_W);
    setAll(coordinate({0, 6}, 2), KNIGHT_W);
    setAll(coordinate({7, 1}, 2), KNIGHT_B);
    setAll(coordinate({7, 6}, 2), KNIGHT_B);

    // Initialize Bishops
    setAll(coordinate({0, 2}, 2), BISHOP_W);
    setAll(coordinate({0, 5}, 2), BISHOP_W);
    setAll(coordinate({7, 2}, 2), BISHOP_B);
    setAll(coordinate({7, 5}, 2), BISHOP_B);

    // Initialize Queens
    setAll(coordinate({0, 3}, 2), QUEEN_W);
    setAll(coordinate({0, 4}, 2), QUEEN_W);
    setAll(coordinate({7, 3}, 2), QUEEN_B);
    setAll(coordinate({7, 4}, 2), QUEEN_B);

    // Initialize Kings
    std::vector<int> king_w = {0, 4};
    king_w.reserve(dimension);
    std::vector<int> king_b = {7, 4};
    king_b.reserve(dimension);
    for (int i = 0; i < dimension - 2; i++) {
        king_w.push_back(0);
        king_b.push_back(7);
    }

    set(coordinate(king_w, dimension), KING_W);
    set(coordinate(king_b, dimension), KING_B);
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
/**
 *
 * Set all sub-dimensions of crd_ltr to val
 *
 * e.g. for a 5 dimensional space, if crd_ltr = {1,2}, set all coordinates in the form {1,2,x,x,x} to val.
 *
 * @param crd_ltr
 * @param val
 */
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

/**
 * Check if a move from start coordinate to end coordinate is valid for a given piece.
 *
 * @param piece
 * @param start
 * @param end
 * @return
 */
bool board::check_valid_move(coordinate start, coordinate end) {
    bool (*check)(board &, coordinate, coordinate);

    // Mostly just wanted to try out function pointers here. not exactly a great idea.
    switch (get(start)) {
        case PAWN_B:
        case PAWN_W:
            check = Pawn::check_valid_move;
            break;
        case QUEEN_B:
        case QUEEN_W:
            check = Queen::check_valid_move;
            break;
        case KING_B:
        case KING_W:
            check = King::check_valid_move;
            break;
        case ROOK_W:
        case ROOK_B:
            check = Rook::check_valid_move;
            break;
        case BISHOP_B:
        case BISHOP_W:
            check = Bishop::check_valid_move;
            break;
        case KNIGHT_B:
        case KNIGHT_W:
            check = Bishop::check_valid_move;
            break;
        default:
            return false;
    }

    return check(*this, start, end);
}

//bool board::isOccupied(coordinate &c) {
//    return get(c) != EMPTY;
//    // possibly add checks for if it's not some random value somehow not in enums
//}

bool board::isOccupied(coordinate c) {
    return get(c) != EMPTY;
    // possibly add checks for if it's not some random value somehow not in enums
}

//bool board::isOccupiedBlack(coordinate &c) {
//    return BLACK_PIECES.find(get(c)) != BLACK_PIECES.end();
//}

bool board::isOccupiedBlack(coordinate c) {
    return BLACK_PIECES.find(get(c)) != BLACK_PIECES.end();
}

//bool board::isOccupiedWhite(coordinate &c) {
//    return WHITE_PIECES.find(get(c)) != WHITE_PIECES.end();
//}

bool board::isOccupiedWhite(coordinate c) {
    return WHITE_PIECES.find(get(c)) != WHITE_PIECES.end();
}

std::vector<coordinate> board::get_valid_moves(int piece, coordinate pos) {
    return std::vector<coordinate>();
}

void board::execute_move(coordinate start, coordinate end) {
    if (check_valid_move(start, end)) {
        set(end, get(start));
        set(start, EMPTY);
    }
}

bool board::opponentPieces(int p1, int p2) {
    return
            (BLACK_PIECES.find(p1) != BLACK_PIECES.end() && WHITE_PIECES.find(p2) != WHITE_PIECES.end()) ||
            (BLACK_PIECES.find(p2) != BLACK_PIECES.end() && WHITE_PIECES.find(p1) != WHITE_PIECES.end());
}

bool board::opponentPieces(coordinate c1, coordinate c2) {
    return opponentPieces(get(c1), get(c2));
}

std::string board::cell_as_string(coordinate c) {
    return piece_as_string(get(c)) + " at " + c.to_string();
}



