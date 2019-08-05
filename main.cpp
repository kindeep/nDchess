#include <iostream>
#include <array>
#include "board.h"
#include <string>
#include <fstream>
#include <ctime>

std::string time_filename;

void write_log(const std::string &to_write) {
    std::ofstream log;
    log.open("/Users/kindeep/Projects/nDchess/testing/test_log", std::ios_base::app); // open file in append mode
    log << to_write;
    log.close();
}

void append_time(int n, double elapsed_secs) {
    std::ofstream times;
    times.open("/Users/kindeep/Projects/nDchess/testing/" + time_filename,
               std::ios_base::app); // list of elapsed seconds
    times << std::to_string(n) << "," << std::to_string(elapsed_secs) << "\n";
    times.close();
}

int main() {
    std::cout << "n-D chess\n" << std::endl;
    std::time_t curr_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    time_filename = std::string("Times " + std::string(std::ctime(&curr_time)) + ".csv");
    write_log("************\nStarted test at: " + std::string(std::ctime(&curr_time)) + "\n");

//    board aBoard = board(1, {KING_B, PAWN_B, EMPTY, EMPTY, EMPTY, EMPTY, PAWN_W, KING_W});
//    std::cout << aBoard.board_as_string() << std::endl;
//    board nml_cboard = board(2,
//                             {
//                                     ROOK_B, PAWN_B, EMPTY, EMPTY, EMPTY, EMPTY, PAWN_W, ROOK_W,
//                                     KNIGHT_B, PAWN_B, EMPTY, EMPTY, EMPTY, EMPTY, PAWN_W, KNIGHT_W,
//                                     BISHOP_B, PAWN_B, EMPTY, EMPTY, EMPTY, EMPTY, PAWN_W, BISHOP_W,
//                                     QUEEN_B, PAWN_B, EMPTY, EMPTY, EMPTY, EMPTY, PAWN_W, QUEEN_W,
//                                     KING_B, PAWN_B, EMPTY, EMPTY, EMPTY, EMPTY, PAWN_W, KING_W,
//                                     BISHOP_B, PAWN_B, EMPTY, EMPTY, EMPTY, EMPTY, PAWN_W, BISHOP_W,
//                                     KNIGHT_B, PAWN_B, EMPTY, EMPTY, EMPTY, EMPTY, PAWN_W, KNIGHT_W,
//                                     ROOK_B, PAWN_B, EMPTY, EMPTY, EMPTY, EMPTY, PAWN_W, ROOK_W,
//                             });
//    std::cout << nml_cboard.board_as_string() << std::endl;

    for (int dim = 3; dim < 4; dim++) {
        auto start = std::chrono::system_clock::now();
        std::time_t start_dt = std::chrono::system_clock::to_time_t(start);

        write_log("Initializing Board\nDimension: " + std::to_string(dim) + "\nStarted at: " + std::ctime(&start_dt));

        board test_board = board(dim);
        std::cout << dim << "-D Chess Board" << std::endl;
        std::cout << test_board.board_as_string() << std::endl;
        auto end = std::chrono::system_clock::now();
        std::time_t end_dt = std::chrono::system_clock::to_time_t(end);
        std::chrono::duration<double> elapsed_seconds = end - start;

        append_time(dim, elapsed_seconds.count());

        write_log("Finished at: " + std::string(std::ctime(&end_dt)) + "Elapsed Seconds: " +
                  std::to_string(elapsed_seconds.count()) + "\n\n");
    }

    std::time_t end_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    write_log("\nFinished test at: " + std::string(std::ctime(&end_time)) + "************");

    return 0;
}