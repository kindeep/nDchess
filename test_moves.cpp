//
// Created by Kindeep Singh Kargil on 2019-08-04.
//

#include "board.h"
#include "lib/json.hpp"

namespace nj = nlohmann;


coordinate parse_coordinate_input(std::string input) {
    auto obj = nj::json::parse(input);

    std::vector<int> coord = obj;

    coordinate c = coordinate(coord);

//    std::cout << c.to_string() << std::endl;
    return coord;
}

coordinate parse_coordinate_input(std::string input, int dimensions) {
//    std::cout<< "Trying to parse " << input << std::endl;
    auto obj = nj::json::parse(input);

    std::vector<int> coord = obj;

//    std::cout << "After json parse: " << std::endl;

//    for (int i : obj) {
//        std::cout << i << std::endl;
//    }

    coordinate c = coordinate(coord, dimensions);

//    std::cout << c.to_string() << std::endl;
    return coord;
}

int main() {
    // json test

//    parse_coordinate_input("[1,2,3,4]");

    //
    board test_board = board(2);

    long pc = test_board.get(coordinate({0, 4}));

    std::cout << test_board.piece_as_string(pc) << std::endl;

    // test king
    std::cout << test_board.check_valid_move(coordinate({0, 4}), coordinate({1, 5})) << std::endl;

    std::cout << test_board.piece_as_string(test_board.get(coordinate({0, 0}))) << std::endl;

    // test rook
    std::cout << test_board.check_valid_move(coordinate({0, 0, 0}), coordinate({0, 5, 1})) << std::endl;

    int dimensions;

    std::cout << "Enter number of dimensions for chessboard: ";

    std::cin >> dimensions;

    std::cout << "Initializing board with " << dimensions << " dimensions" << std::endl;

    board game_board = board(dimensions);
    std::cout << game_board.board_as_string() << std::endl;


    std::string in = "";

    while (in != "exit") {
        std::cout << "Move? (y/exit):" << std::endl;
        std::cin >> in;

        if (in == "y") {
            std::string start_json, end_json;
            std::cout << "Start: ";
            std::cin >> start_json;
            std::cout << "End: ";
            std::cin >> end_json;
            coordinate start = parse_coordinate_input(start_json, dimensions);
            coordinate end = parse_coordinate_input(end_json, dimensions);
            std::cout << "Move " << game_board.cell_as_string(start)  << " to " << game_board.cell_as_string(end) << std::endl;
            std::cout << "Valid move? " << game_board.check_valid_move(start, end) << std::endl;
            game_board.execute_move(start, end);
        }

        std::cout << game_board.board_as_string() << std::endl;
    }

}