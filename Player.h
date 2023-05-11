//
// Created by chaseez on 5/9/2023.
//

#ifndef CHESSGAMECPP_PLAYER_H
#define CHESSGAMECPP_PLAYER_H

#include <vector>
#include <string>

#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

class Player {
private:
    const int NUM_PIECES = 16;
    std::vector<Piece*> pieces;
    Color team;
    int points;

    void fillPieces();

public:
    Player(Color team) {
        points = 0;
        this->team = team;
        pieces = std::vector<Piece*>(NUM_PIECES);
        fillPieces();
    }

    ~Player() {
        int length = pieces.size();
        for(int i = 0; i < length; ++i) delete pieces.at(i);
    }

    std::vector<Piece*> getPieces() const;
    bool inCheck() const;
};


#endif //CHESSGAMECPP_PLAYER_H
