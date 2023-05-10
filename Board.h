//
// Created by chaseez on 5/9/2023.
//

#ifndef CHESSGAMECPP_BOARD_H
#define CHESSGAMECPP_BOARD_H


#include "Piece.h"
#include "Player.h"

class Board {
public:
    int** board;
    int** mask;

    Board() {
        board = new int*[BOARD_WIDTH];
        for(int i = 0; i < BOARD_WIDTH; ++i) {
            board[i] = new int[BOARD_HEIGHT];
            for(int j = 0; j < BOARD_HEIGHT; ++j) board[i][j] = 0;
        }

        mask = new int*[MASK_WIDTH];
        for(int i = 0; i < MASK_WIDTH; ++i) {
            mask[i] = new int[MASK_HEIGHT];
            for(int j = 0; j < MASK_HEIGHT; ++j) mask[i][j] = 0;
        }
    }

    ~Board() {
        for(int i =0; i < BOARD_HEIGHT; ++i) delete board[i];
        delete[] board;

        for(int i = 0; i < MASK_HEIGHT; ++i) delete mask[i];
        delete[] mask;
    }

    void updateBoard(int x, int y);
    static bool validMove(int x, int y);
    void printBoard() const;
    void printMask() const;
    void populateBoard(const Player& white, const Player& black);
    void populateMask();
    int** getBoard() const;
    int** getMask() const;

private:
    const static int BOARD_WIDTH = 8;
    const static int BOARD_HEIGHT = 8;
    const static int MASK_WIDTH = 16;
    const static int MASK_HEIGHT = 16;
};


#endif //CHESSGAMECPP_BOARD_H
