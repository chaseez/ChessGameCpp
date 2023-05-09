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

    void showMoves() override;
    void move() override;
    void take() override;
    void checkForCheck() override;
};


#endif //CHESSGAMECPP_KING_H
