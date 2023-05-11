//
// Created by chaseez on 5/9/2023.
//

#ifndef CHESSGAMECPP_PAWN_H
#define CHESSGAMECPP_PAWN_H

#include "Piece.h"

class Pawn : public Piece {
public:
    bool firstMove;

    Pawn(Color team) {
        value = PAWN;
        this->team = team;
        firstMove = true;
    }

    ~Pawn() override = default;

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


#endif //CHESSGAMECPP_PAWN_H
