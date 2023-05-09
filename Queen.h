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

    void showMoves() override;
    void move() override;
    void take() override;
    void checkForCheck() override;
};


#endif //CHESSGAMECPP_QUEEN_H
