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

    void showMoves() override;
    void move() override;
    void take() override;
    void checkForCheck() override;
};


#endif //CHESSGAMECPP_BISHOP_H
