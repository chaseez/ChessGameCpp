//
// Created by chaseez on 5/9/2023.
//

#ifndef CHESSGAMECPP_KNIGHT_H
#define CHESSGAMECPP_KNIGHT_H


#include "Piece.h"

class Knight : public Piece {
public:
    Knight(Color team){
        value = KNIGHT;
        this->team = team;
    }

    ~Knight() override = default;

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


#endif //CHESSGAMECPP_KNIGHT_H
