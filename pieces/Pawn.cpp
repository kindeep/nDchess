//
// Created by Kindeep Singh Kargil on 2019-08-04.
//

#include "Pawn.h"

bool Pawn::check_valid_move(board &_board, coordinate start, coordinate end) {
    int dimension = start.dim();
    // assuming start and end are in the same dimensions. possibly adjust them to be so.

    int allowed_diff1, allowed_diff2, start1, white;

    if (_board.isOccupiedBlack(start)) {
        white = false;
        start1 = 6;
        allowed_diff1 = -1;
        allowed_diff2 = -2;
    } else if (_board.isOccupiedWhite(start)) {
        white = true;
        start1 = 1;
        allowed_diff1 = 1;
        allowed_diff2 = 2;
    } else {
        // start is just empty.
        return false;
    }

//    if (_board.isOccupiedWhite(start)) {
    if (start.get(0) == start1) {
        // at starting position
        // see if it changed by two, and forward only
        if (end.get(0) - start.get(0) == allowed_diff2) {
            // just check for a valid 2 step first move right here. None of the others should change.
            // At this point it's either a true if nothing else changed or just false.
            for (int i = 1; i < start.dim(); i++) {
                int cs = start.get(i);
                int ce = end.get(i);
                if (cs - ce != 0) {
                    return false;
                }
            }
            // check if there is something in the way.
            coordinate start_copy = coordinate(start.vals());
            if (white) {
                for (int j = 2; j <= 3; j++) {
                    start_copy.set(0, j);
                    if (_board.isOccupied(start_copy)) {
                        return false;
                    }
                }
            } else {
                for (int j = 5; j >= 4; j--) {
                    start_copy.set(0,j);
                    if (_board.isOccupied(start_copy)) {
                        return false;
                    }
                }
            }
            return true;
        }
        // now otherwise it's just a general case. Nothing special about it being at the start.
    }

    // check if the linear/straight part of the move is valid before checking diagonal mvmt.

    if (end.get(0) - start.get(0) == allowed_diff1) {
        // linear is valid.
        // if it is just linear, cannot have end occupied by opponent piece.
        // if it is a diag movement, end can only be occupied by an opponent piece or empty.
        bool diag = false;

        for (int i = 1; i < dimension; i++) {
            int cs = start.get(i);
            int ce = end.get(i);

            if (ce - cs == allowed_diff1) {
                // now all of them should be one.
                if (!diag) {
                    diag = true;
                }
            } else {
                // if one diagonal move exists and this is not one, move is invalid.
                if (diag) return false;
            }
        }

        if (diag) {
            // at this point if move is diagonal, it's a valid move. just check occupy stuff.
            return (_board.isOccupied(end) && _board.opponentPieces(start, end));
        } else {
            // it's pure linear.
            return !_board.isOccupied(end);
        }

    } else {
        // either it's in the same place now or just invalid. In any case, return false.
        return false;
    }
//    }

    return false;
}

std::vector<coordinate> Pawn::get_valid_moves(int piece, coordinate pos) {}
