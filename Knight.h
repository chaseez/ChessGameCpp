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

    void showMoves() override;
    void move() override;
    void take() override;
    void checkForCheck() override;
};


#endif //CHESSGAMECPP_KNIGHT_H
