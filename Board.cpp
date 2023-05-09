//
// Created by chaseez on 5/9/2023.
//

#include "Board.h"

void Board::updateBoard(int x, int y) {

}

bool Board::validMove(int x, int y) {
    return 0 <= x and x < BOARD_HEIGHT and 0 <= y and y < BOARD_WIDTH;
}
