//
// Created by chaseez on 5/9/2023.
//

#ifndef CHESSGAMECPP_PAWN_H
#define CHESSGAMECPP_PAWN_H


#include "Piece.h"

class Pawn : public Piece {
public:
    Pawn(Color color) {
        value = PAWN;
        this->color = color;
    }

    void move() override;
    void take() override;
    void checkForCheck() override;

};


#endif //CHESSGAMECPP_PAWN_H
