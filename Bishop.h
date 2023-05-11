//
// Created by chaseez on 5/9/2023.
//

#ifndef CHESSGAMECPP_BISHOP_H
#define CHESSGAMECPP_BISHOP_H


#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(Color team) {
        value = BISHOP;
        this->team = team;
    }

    ~Bishop() override = default;

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


#endif //CHESSGAMECPP_BISHOP_H
