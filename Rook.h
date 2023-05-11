//
// Created by chaseez on 5/9/2023.
//

#ifndef CHESSGAMECPP_ROOK_H
#define CHESSGAMECPP_ROOK_H


#include "Piece.h"

class Rook : public Piece {
public:
    Rook(Color team){
        value = ROOK;
        this->team = team;
    }

    ~Rook() override = default;

    void showMoves() override;
    void move() override;
    void take() override;
    void checkForCheck() override;
    bool canMove() override;
    int getRow() override { return row; }
    void setRow(int row) override { this->row = row; }
    int getColumn() override { return column; }
    void setColumn(int column) override { this->column = column; }
};


#endif //CHESSGAMECPP_ROOK_H
