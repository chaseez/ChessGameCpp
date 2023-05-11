//
// Created by chaseez on 5/9/2023.
//

#ifndef CHESSGAMECPP_KING_H
#define CHESSGAMECPP_KING_H


#include "Piece.h"

class King: public Piece {
public:
    King(Color team){
        value = KING;
        this->team = team;
    }

    ~King() override = default;


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


#endif //CHESSGAMECPP_KING_H
