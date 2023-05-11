//
// Created by chaseez on 5/9/2023.
//

#ifndef CHESSGAMECPP_PIECE_H
#define CHESSGAMECPP_PIECE_H

#include <iostream>

enum PieceValue {
    PAWN=1,
    ROOK=3,
    KNIGHT=5,
    BISHOP=7,
    QUEEN=9,
    KING=-2
};

enum Color {
    BLACK=1,
    WHITE=0
};

class Piece {
public:
    PieceValue value;
    Color team;

    virtual ~Piece() = default;

    virtual void showMoves() = 0;
    virtual void move() = 0;
    virtual void take() = 0;
    virtual void checkForCheck() = 0;
    virtual bool canMove() = 0;
    virtual int getRow() = 0;
    virtual void setRow(int row) = 0;
    virtual int getColumn() = 0;
    virtual void setColumn(int col) = 0;
protected:
    int row;
    int column;
};


#endif //CHESSGAMECPP_PIECE_H
