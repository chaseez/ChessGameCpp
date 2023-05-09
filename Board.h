//
// Created by chaseez on 5/9/2023.
//

#ifndef CHESSGAMECPP_BOARD_H
#define CHESSGAMECPP_BOARD_H


#include "Piece.h"

class Board {
public:
    int** board;

    Board() {
        board = new int*[BOARD_WIDTH];
        for(int i = 0; i < BOARD_HEIGHT; ++i) board[i] = new int[8];
    }

    void updateBoard(int x, int y);
    static bool validMove(int x, int y);

private:
    const static int BOARD_WIDTH = 8;
    const static int BOARD_HEIGHT = 8;
};


#endif //CHESSGAMECPP_BOARD_H
