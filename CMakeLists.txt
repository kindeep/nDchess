cmake_minimum_required(VERSION 3.12)
project(nDchess)

set(CMAKE_CXX_STANDARD 11)

#set(JSON_BuildTests OFF CACHE INTERNAL "")

#add_subdirectory(nlohmann_json)

#add_library(json)

#target_link_libraries( PRIVATE nlohmann_json::nlohmann_json)

add_executable(nDchess board.cpp board.h coordinate.cpp coordinate.h pieces/Piece.cpp pieces/Piece.h pieces/Pawn.cpp pieces/Pawn.h pieces/King.cpp pieces/King.h pieces/Rook.cpp pieces/Rook.h pieces/Bishop.cpp pieces/Bishop.h pieces/Queen.cpp pieces/Queen.h pieces/Knight.cpp pieces/Knight.h test_moves.cpp)
#add_executable(nDchess main.cpp board.cpp board.h coordinate.cpp coordinate.h pieces/Piece.cpp pieces/Piece.h pieces/Pawn.cpp pieces/Pawn.h pieces/King.cpp pieces/King.h pieces/Rook.cpp pieces/Rook.h pieces/Bishop.cpp pieces/Bishop.h pieces/Queen.cpp pieces/Queen.h pieces/Knight.cpp pieces/Knight.h test_moves.cpp)