//
// Created by chaseez on 5/9/2023.
//

#ifndef CHESSGAMECPP_QUEEN_H
#define CHESSGAMECPP_QUEEN_H


#include "Piece.h"

class Queen : public Piece {
public:
    Queen(Color team){
        value = QUEEN;
        this->team = team;
    }

    ~Queen() override = default;

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


#endif //CHESSGAMECPP_QUEEN_H
