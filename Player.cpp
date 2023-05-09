//
// Created by chaseez on 5/9/2023.
//

#include "Player.h"


void Player::fillPieces() {
    for(int i = 0; i < NUM_PIECES; ++i)
    {
        pieces[i] = new Pawn(team);
        pieces[i]->move();
        pieces[i]->take();
        pieces[i]->checkForCheck();
    }
}