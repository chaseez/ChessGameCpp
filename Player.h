//
// Created by chaseez on 5/9/2023.
//

#ifndef CHESSGAMECPP_PLAYER_H
#define CHESSGAMECPP_PLAYER_H

#include <vector>
#include "Piece.h"
#include "Pawn.h"

class Player {
private:
    const int NUM_PIECES = 16;
    std::vector<Piece*> pieces;
    Color team;
    int points;

    void fillPieces();

public:
    Player(Color team) {
        this->team = team;
        pieces = std::vector<Piece*>(NUM_PIECES);
        fillPieces();
    }
};


#endif //CHESSGAMECPP_PLAYER_H
