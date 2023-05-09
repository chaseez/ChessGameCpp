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

    void showMoves() override;
    void move() override;
    void take() override;
    void checkForCheck() override;
};


#endif //CHESSGAMECPP_ROOK_H
